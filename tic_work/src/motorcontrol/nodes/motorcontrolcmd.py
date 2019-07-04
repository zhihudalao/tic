#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
import os, time
import thread

from math import pi as PI, degrees, radians, sin, cos
import os
import time
import sys, traceback
from serial.serialutil import SerialException
from serial import Serial

import roslib
import math

from geometry_msgs.msg import Quaternion, Twist, Pose
from nav_msgs.msg import Odometry
from std_msgs.msg import Int16,Int32, Bool
from tf.broadcaster import TransformBroadcaster

#from dashgo_driver.srv import *
#from SrvInt32.srv import *
from std_srvs.srv import Trigger, TriggerResponse
import binascii
from sensor_msgs.msg import Range
import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import PointCloud2, PointField 
from motorcontrol.msg import control, controlsensor
from ctypes import *

ODOM_POSE_COVARIANCE = [1e-3, 0, 0, 0, 0, 0, 
                        0, 1e-3, 0, 0, 0, 0,
                        0, 0, 1e6, 0, 0, 0,
                        0, 0, 0, 1e6, 0, 0,
                        0, 0, 0, 0, 1e6, 0,
                        0, 0, 0, 0, 0, 1e3]
ODOM_POSE_COVARIANCE2 = [1e-9, 0, 0, 0, 0, 0, 
                         0, 1e-3, 1e-9, 0, 0, 0,
                         0, 0, 1e6, 0, 0, 0,
                         0, 0, 0, 1e6, 0, 0,
                         0, 0, 0, 0, 1e6, 0,
                         0, 0, 0, 0, 0, 1e-9]

ODOM_TWIST_COVARIANCE = [1e-3, 0, 0, 0, 0, 0, 
                         0, 1e-3, 0, 0, 0, 0,
                         0, 0, 1e6, 0, 0, 0,
                         0, 0, 0, 1e6, 0, 0,
                         0, 0, 0, 0, 1e6, 0,
                         0, 0, 0, 0, 0, 1e3]
ODOM_TWIST_COVARIANCE2 = [1e-9, 0, 0, 0, 0, 0, 
                          0, 1e-3, 1e-9, 0, 0, 0,
                          0, 0, 1e6, 0, 0, 0,
                          0, 0, 0, 1e6, 0, 0,
                          0, 0, 0, 0, 1e6, 0,
                          0, 0, 0, 0, 0, 1e-9]


SERVO_MAX = 180
SERVO_MIN = 0

class MotorControl:
    ''' Configuration Parameters
    '''    
    N_ANALOG_PORTS = 6
    N_DIGITAL_PORTS = 12
    
    def __init__(self, port="/dev/ttyStm32", baudrate=115200, timeout=0.05):
        
        # Local motor only need rpm for motor, no need for PID_RATE, so set it to 1
        self.PID_RATE = 1.333333    
        #self.PID_RATE = 30 # Do not change this!  It is a fixed property of the MotorControl PID controller.
        # No need for current solution yet, so leave it as previous value
        self.PID_INTERVAL = 1000 / 30
        
        self.port = port
        self.baudrate = baudrate
        self.timeout = timeout
        self.encoder_count = 0
        self.writeTimeout = timeout
        self.interCharTimeout = timeout / 30.
    
        # Keep things thread safe
        self.mutex = thread.allocate_lock()
            
        # An array to cache analog sensor readings
        self.analog_sensor_cache = [None] * self.N_ANALOG_PORTS
        
        # An array to cache digital sensor readings
        self.digital_sensor_cache = [None] * self.N_DIGITAL_PORTS
    
    def connect(self):
        try:
            print "Connecting to MotorControl on port", self.port, "..."
            self.port = Serial(port=self.port, baudrate=self.baudrate, timeout=self.timeout, writeTimeout=self.writeTimeout)
            # The next line is necessary to give the firmware time to wake up.
            time.sleep(1)
            '''
            test = self.get_baud()
            if test != self.baudrate:
                time.sleep(1)
                test = self.get_baud()   
                if test != self.baudrate:
                    raise SerialException
            
            print "Connected at", self.baudrate
            '''
            print "MotorControl is ready."

        except SerialException:
            print "Serial Exception:"
            print sys.exc_info()
            print "Traceback follows:"
            traceback.print_exc(file=sys.stdout)
            print "Cannot connect to MotorControl!"
            os._exit(1)

    def open(self): 
        ''' Open the serial port.
        '''
        self.port.open()

    def close(self): 
        ''' Close the serial port.
        '''
        self.port.close() 
    
    def send(self, cmd):
        ''' This command should not be used on its own: it is called by the execute commands
            below in a thread safe manner.
        '''
        self.port.write(cmd + '\r')

    def recv(self, timeout=0.5):
        timeout = min(timeout, self.timeout)
        ''' This command should not be used on its own: it is called by the execute commands   
            below in a thread safe manner.  Note: we use read() instead of readline() since
            readline() tends to return garbage characters from the Arduino
        '''
        c = ''
        value = ''
        attempts = 0
        while c != '\r':
            c = self.port.read(1)
            value += c
            attempts += 1
            if attempts * self.interCharTimeout > timeout:
                return None

        value = value.strip('\r')

        return value

    def recvcmdtype(self, timeout=0.5):
        timeout = min(timeout, self.timeout)
        i = 4
        c = ''
        value = ''
        attempts = 0
        dataarry = []
        while i != 0:
            c = self.port.read(1) 
            if c != "":
                value += c  
                attempts += 1
                if attempts * self.interCharTimeout > timeout:
                    return None               
            i = i -1

        
        for c in value:
            dataarry.append('{:02X}'.format(ord(c)))

        if len(dataarry) != 0:
            # print "dataarry is : ", dataarry
            # if dataarry[0] == "AE" and dataarry[1] == "EA" and dataarry[2] == "00" and dataarry[3] == "5A":
            #     i = 74
            if dataarry[0] == "AE" and dataarry[1] == "EA" and dataarry[2] == "01" and dataarry[3] == "5A":
                i = 10
            else:
                i = 0

            # print "i is: ", i
        return i

    def recvCMD(self, timeout=0.5):
        timeout = min(timeout, self.timeout)
        ''' This command should not be used on its own: it is called by the execute commands   
            below in a thread safe manner.  Note: we use read() instead of readline() since
            readline() tends to return garbage characters from the Arduino
        '''
        c = ''
        value = list()
        i = self.recvcmdtype(self.timeout)
        # print "i is: " ,i 
        attempts = 0
        while i != 0:
            c = self.port.read(1)
            # print "recive data char is:", c
            # print "recive data is: " , '{:02X}'.format(ord(c))
            
            if c != "":
                value.append(int(binascii.b2a_hex(c),16)) 
                attempts += 1
            # if attempts * self.interCharTimeout > timeout:
            #     return []
            i = i - 1
        
        if len(value) != 0:      
            return value
        else:
            return []       

    def recv_ack(self):
        ''' This command should not be used on its own: it is called by the execute commands
            below in a thread safe manner.
        '''
        ack = self.recv(self.timeout)
        return ack == 'OK'

    def recv_int(self):
        ''' This command should not be used on its own: it is called by the execute commands
            below in a thread safe manner.
        '''
        value = self.recv(self.timeout)
        try:
            return int(value)
        except:
            return None

    def recv_array(self):
        ''' This command should not be used on its own: it is called by the execute commands
            below in a thread safe manner.
        '''
        try:
            values = self.recv(self.timeout * self.N_ANALOG_PORTS).split()
            return map(int, values)
        except:
            return []

    def execute(self, cmd):
        ''' Thread safe execution of "cmd" on the MotorControl returning a single integer value.
        '''
        self.mutex.acquire()
        
        try:
            self.port.flushInput()
        except:
            pass
        
        ntries = 1
        attempts = 0
        
        try:
            self.port.write(cmd + '\r')
            value = self.recv(self.timeout)
            while attempts < ntries and (value == '' or value == 'Invalid Command' or value == None):
                try:
                    self.port.flushInput()
                    self.port.write(cmd + '\r')
                    value = self.recv(self.timeout)
                except:
                    print "Exception executing command: " , cmd
                attempts += 1
        except:
            self.mutex.release()
            print "Exception executing command: ", cmd
            value = None
        
        self.mutex.release()
        return int(value)

    def execute_array(self, cmd):
        ''' Thread safe execution of "cmd" on the MotorControl returning an array.
        '''
        self.mutex.acquire()
        
        try:
            self.port.flushInput()
        except:
            pass
        
        ntries = 1
        attempts = 0
        
        try:
            self.port.write(cmd + '\r')
            values = self.recv_array()
            while attempts < ntries and (values == '' or values == 'Invalid Command' or values == [] or values == None):
                try:
                    self.port.flushInput()
                    self.port.write(cmd + '\r')
                    values = self.recv_array()
                except:
                    # print "Exception executing command: ", cmd 
                    attempts += 1
        except:
            self.mutex.release()
            print "Exception executing command: " , cmd
            raise SerialException
            return []
        
        try:
            values = map(int, values)
        except:
            values = []

        self.mutex.release()
        return values
        
    def execute_ack(self, cmd):
        ''' Thread safe execution of "cmd" on the Arduino returning True if response is ACK.
        '''
        self.mutex.acquire()
        
        try:
            self.port.flushInput()
        except:
            pass
        
        ntries = 1
        attempts = 0
        
        try:
            self.port.write(cmd + '\r')
            ack = self.recv(self.timeout)
            while attempts < ntries and (ack == '' or ack == 'Invalid Command' or ack == None):
                try:
                    self.port.flushInput()
                    self.port.write(cmd + '\r')
                    ack = self.recv(self.timeout)
                except:
                    print "Exception executing command: ", cmd
            attempts += 1
        except:
            self.mutex.release()
            print "execute_ack exception when executing", cmd
            print sys.exc_info()
            return 0
        
        self.mutex.release()
        return ack == 'OK'   

    def execute_ackcmd(self, cmd):
        ''' Thread safe execution of "cmd" on the Arduino returning True if response is ACK.
        '''
        self.mutex.acquire()
        
        try:
            self.port.flushInput()
        except:
            pass
        
        # ntries = 1
        # attempts = 0_
        # reciveValue = list()
        try:
            self.port.write(cmd)
            #rospy.shutdown()
            
            # ack = self.recvCMD(self.timeout)   
            # time.sleep(0.01)        
        except:
            self.mutex.release()
            #print "execute_ack exception when executing", cmd
            print sys.exc_info()
            return []
        
        # reciveValue = ack
        self.mutex.release()
        
        # print "reciveValue is: ", reciveValue
        return []   

    def update_pid(self, Kp, Kd, Ki, Ko):
        ''' Set the PID parameters on the Arduino
        '''
        print "Updating PID parameters"
        cmd = 'u ' + str(Kp) + ':' + str(Kd) + ':' + str(Ki) + ':' + str(Ko)
        self.execute_ack(cmd)                          

    def get_baud(self):
        ''' Get the current baud rate on the serial port.
        '''
        return int(self.execute('b'))

    def get_encoder_counts(self):
        values = self.execute_array('e')
        #print "encoder is :" + str(values)
        if len(values) != 2:
            print "Encoder count was not 2"
            raise SerialException
            return None
        else:
            return values

    def reset_encoders(self):
        ''' Reset the encoder counts to 0
        '''
        return self.execute_ack('r')
    
    def reset_pid(self):
        ''' Reset the encoder counts to 0
        '''
        return self.execute_ack('w')

    def execute_ack(self, cmd):
        ''' Thread safe execution of "cmd" on the Arduino returning True if response is ACK.
        '''
        self.mutex.acquire()
        
        try:
            self.port.flushInput()
        except:
            pass
        
        ntries = 1
        attempts = 0
        
        try:
            self.port.write(cmd + '\r')
            ack = self.recv(self.timeout)
            while attempts < ntries and (ack == '' or ack == 'Invalid Command' or ack == None):
                try:
                    self.port.flushInput()
                    self.port.write(cmd + '\r')
                    ack = self.recv(self.timeout)
                except:
                    print "Exception executing command: ", cmd
            attempts += 1
        except:
            self.mutex.release()
            print "execute_ack exception when executing", cmd
            print sys.exc_info()
            return 0
        
        self.mutex.release()
        return ack == 'OK'   

    def drive(self, cmd):
        ''' Speeds are given in encoder ticks per PID interval
        '''
        return self.execute_ackcmd(cmd)   
           
    def stop(self):
        ''' Stop both motors.
        '''
        #self.drive(0, 0)

    def setUseSonar(self):
        return self.execute_ack('y')

    def ping_o(self):
        values = self.execute_array('o')
        if len(values) != 2:
            print "ping count was not 2"
            raise SerialException
            return None
        else:
            return values
    def ping_p(self):
        values = self.execute_array('p')
        if len(values) != 2:
            print "ping count was not 2"
            raise SerialException
            return None
        else:
            return values
    def ping_q(self):
        return int(self.execute('q'))

    def get_voltage(self):
        return self.execute('v')

    def get_emergency_button(self):
        return self.execute('j')

    def get_pidin(self):
        values = self.execute_array('i')
        if len(values) != 2:
            print "get_pidin count was not 2"
            raise SerialException
            return None
        else:
            return values

    def get_pidout(self):
        values = self.execute_array('f')
        if len(values) != 2:
            print "get_pidout count was not 2"
            raise SerialException
            return None
        else:
            return values

class BaseController:
    def __init__(self, MotorControl, base_frame):
        self.MotorControl = MotorControl
        self.base_frame = base_frame
        self.rate = float(rospy.get_param("~base_controller_rate", 10))
        self.timeout = rospy.get_param("~base_controller_timeout", 1.0)
        self.stopped = False
        self.useImu = rospy.get_param("~useImu", False)
        self.useSonar = rospy.get_param("~useSonar", False)
        self.emergencybt_val = 0
        self.cmd = []     
        self.Sensorcmd = []       
        pid_params = dict()
        pid_params['wheel_diameter'] = rospy.get_param("~wheel_diameter", "") 
        pid_params['wheel_track'] = rospy.get_param("~wheel_track", "")
        pid_params['encoder_resolution'] = rospy.get_param("~encoder_resolution", "") 
        pid_params['gear_reduction'] = rospy.get_param("~gear_reduction", 1.0)
        pid_params['Kp'] = rospy.get_param("~Kp", 20)
        pid_params['Kd'] = rospy.get_param("~Kd", 12)
        pid_params['Ki'] = rospy.get_param("~Ki", 0)
        pid_params['Ko'] = rospy.get_param("~Ko", 50)
        self.globSwitchflag = False
        self.controldata = control()
        self.controlsensor = controlsensor()
        self.originSpeed = 0
        self.originRotate = 0
        
        self.accel_limit = rospy.get_param('~accel_limit', 0.1)
        self.motors_reversed = rospy.get_param("~motors_reversed", False)
        self.sonar_r0 =0.0
        self.sonar_r1 =0.0
        self.sonar_r2 =0.0
        self.sonar_r3 =0.0
        self.sonar_r4 =0.0
        self.safe_range_0 = 10
        self.safe_range_1 = 30   
        self.initencodeclearflag = True     
        # Set up PID parameters and check for missing values
        self.setup_pid(pid_params)
            
        # How many encoder ticks are there per meter?
        self.ticks_per_meter = self.encoder_resolution * self.gear_reduction  / (self.wheel_diameter * PI)
        
        # What is the maximum acceleration we will tolerate when changing wheel speeds?
        self.max_accel = self.accel_limit * self.ticks_per_meter / self.rate
                
        # Track how often we get a bad encoder count (if any)
        self.bad_encoder_count = 0

        self.encoder_min = rospy.get_param('encoder_min', -32768)
        self.encoder_max = rospy.get_param('encoder_max', 32768)
        self.encoder_low_wrap = rospy.get_param('wheel_low_wrap', (self.encoder_max - self.encoder_min) * 0.3 + self.encoder_min )
        self.encoder_high_wrap = rospy.get_param('wheel_high_wrap', (self.encoder_max - self.encoder_min) * 0.7 + self.encoder_min )
        self.l_wheel_mult = 0
        self.r_wheel_mult = 0
        
                        
        now = rospy.Time.now()    
        self.then = now # time for determining dx/dy
        self.t_delta = rospy.Duration(1.0 / self.rate)
        self.t_next = now + self.t_delta

        # Internal data        
        self.enc_left = 0            # encoder readings
        self.enc_right = 0
        self.x = 0                      # position in xy plane
        self.y = 0
        self.th = 0                     # rotation in radians
        self.v_left = 0
        self.v_right = 0
        self.v_des_left = 0             # cmd_vel setpoint
        self.v_des_right = 0
        self.last_cmd_vel = now

        # Subscriptions
        rospy.Subscriber("cmd_vel", Twist, self.cmdVelCallback)
        #rospy.Subscriber("smoother_cmd_vel", Twist, self.cmdVelCallback)
        # self.robot_cmd_vel_pub = rospy.Publisher('robot_cmd_vel', Twist, queue_size=5)
        rospy.Subscriber("wash", Bool, self.getCmdswitchFlagCallback)
        # rospy.Subscriber("is_passed", Int16, self.isPassedCallback)
        # self.isPassed = True

        # rospy.Subscriber("is_passed_2", Int16, self.isPassedCallback_2)
        # self.isPassed_2 = True
        
        rospy.loginfo("Started base controller for a base of " + str(self.wheel_track) + "m wide with " + str(self.encoder_resolution) + " ticks per rev")
        rospy.loginfo("Publishing odometry data at: " + str(self.rate) + " Hz using " + str(self.base_frame) + " as base frame")

        # self.lVelPub = rospy.Publisher('Lvel', Int16, queue_size=5)
        # self.rVelPub = rospy.Publisher('Rvel', Int16, queue_size=5)
        
        # self.emergencybt_pub = rospy.Publisher('emergencybt_status', Int32, queue_size=5)	
        self.initControldata(self.controldata)
    
    def setup_pid(self, pid_params):
        self.wheel_diameter = pid_params['wheel_diameter']
        self.wheel_track = pid_params['wheel_track']
        self.encoder_resolution = pid_params['encoder_resolution']
        self.gear_reduction = pid_params['gear_reduction']
        
        self.Kp = pid_params['Kp']
        self.Kd = pid_params['Kd']
        self.Ki = pid_params['Ki']
        self.Ko = pid_params['Ko']
        
        #self.MotorControl.update_pid(self.Kp, self.Kd, self.Ki, self.Ko)

    def changeformat(self, origindata):
        changeret = ''
        
        retdata = c_int(origindata)
        # datatest = (retdata.value & 0xff000000) >> 24
        changeret += chr(retdata.value & 0xff)
        changeret += chr((retdata.value & 0xff00) >> 8)        
        changeret += chr((retdata.value & 0xff0000) >> 16)        
        changeret += chr((retdata.value & 0xff000000) >> 24)

 
        return changeret
        
    def getSum(self, checksum):
        
        retdata = c_int(checksum)
        sumtotal = 0
        sumtotal += (retdata.value & 0xff000000) >> 24
        sumtotal += (retdata.value & 0xff0000) >> 16
        sumtotal += (retdata.value & 0xff00) >> 8
        sumtotal += retdata.value & 0xff
        return sumtotal

    def checkSensorSum(self, req, len):
        i = 0
        checksum = 0    

        checksum += self.getSum(req.imudata)
        checksum += self.getSum(req.encoderdata)
        checksum += self.getSum(req.wavedata)
        checksum += self.getSum(req.glosscheckdata)
        checksum += self.getSum(req.collisiondata)
        
        return checksum  

    def Getmaxspeed(self, m, n):
        if abs(m) > abs(n):
            return abs(m)
        return abs(n)

    def setPwMpercentage(self, leftspeed, rightspeed, switch):
        if switch == 1:
            maxspeed = self.Getmaxspeed(leftspeed, rightspeed)
            
            if maxspeed > 0 and maxspeed <= 0.2:
                pwmvalue = 100
            elif maxspeed > 0.2 and maxspeed <= 0.4:
                pwmvalue = 75
            elif maxspeed > 0.4 and maxspeed <= 0.6:
                pwmvalue = 50
            elif maxspeed > 0.6 and maxspeed <= 0.8:
                pwmvalue = 100
            elif maxspeed > 0.8:
                pwmvalue = 25
            else:
                pwmvalue = 0
        else:
            pwmvalue = 0
        # print "pwmvalue ", pwmvalue
        return pwmvalue

    def setSwitchValue(self, leftspeed, rightspeed):

        maxspeed = self.Getmaxspeed(leftspeed, rightspeed)
        if self.globSwitchflag == True and maxspeed > 0.0 :
            switchvalue = 1          
        else:
            switchvalue = 0
        return switchvalue
    

    def checkSumdata(self, req, len):
        checksum = 0      
        checksum += self.getSum(req.leftmotorspeed)
        checksum += self.getSum(req.rightmotorspeed)
        checksum += self.getSum(req.encodeclear)
        checksum += self.getSum(req.suckwindmotorenable)
        checksum += self.getSum(req.suckwindpwmlevel)
        checksum += self.getSum(req.suckwatermotorenable)
        checksum += self.getSum(req.suckwaterpwmenable)
        checksum += self.getSum(req.brushplatepushenable)
        checksum += self.getSum(req.brushplatepushtime)
        checksum += self.getSum(req.suckwaterpushenbale)
        checksum += self.getSum(req.suckwaterpushtime)
        checksum += self.getSum(req.spraywaterelectvalveenbale)
        checksum += self.getSum(req.spraywaterelectvalvelevel)
        checksum += self.getSum(req.turnonwaterelectvalveenbale)
        checksum += self.getSum(req.turnonwaterelectvalvelevel)
        checksum += self.getSum(req.stirringmotorenable)
        checksum += self.getSum(req.stirringmotorpwmenable)
        checksum += self.getSum(req.brushplateenable)
        checksum += self.getSum(req.brushplatepwdlevel)
        # print "sum is: ", checksum
        return checksum

    def getMessagebyCmd1(self, req):

        req.header1 = 0xAE
        req.header2 = 0xEA
        req.hostid = 0x00
        req.subhostid = 0x5A
        if self.initencodeclearflag == True:
            req.encodeclear = 1
            self.initencodeclearflag = False
        else:
            req.encodeclear = 0

        req.suckwindmotorenable = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.suckwindpwmlevel= int(self.setPwMpercentage(self.originSpeed, self.originRotate, req.suckwindmotorenable))
        req.suckwatermotorenable = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.suckwaterpwmenable  = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.brushplatepushenable = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.brushplatepushtime = int(self.setPwMpercentage(self.originSpeed, self.originRotate, req.brushplatepushenable))
        req.suckwaterpushenbale = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.suckwaterpushtime = int(self.setPwMpercentage(self.originSpeed, self.originRotate, req.suckwaterpushenbale))
        req.spraywaterelectvalveenbale = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.spraywaterelectvalvelevel = int(self.setPwMpercentage(self.originSpeed, self.originRotate, req.spraywaterelectvalveenbale))
        req.turnonwaterelectvalveenbale = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.turnonwaterelectvalvelevel = int(self.setPwMpercentage(self.originSpeed, self.originRotate, req.turnonwaterelectvalveenbale))
        req.stirringmotorenable = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.stirringmotorpwmenable = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.brushplateenable = int(self.setSwitchValue(self.originSpeed, self.originRotate))
        req.brushplatepwdlevel = int(self.setPwMpercentage(self.originSpeed, self.originRotate, req.brushplateenable))
        cmdtmp = ''
        checksum = self.checkSumdata(req, 0)
        retdata = c_int(checksum)
        req.checknumhigh = (retdata.value & 0xff00) >> 8
        req.checknumlow = retdata.value & 0xff
        cmdtmp += chr(req.header1)    
        cmdtmp += chr(req.header2) 
        cmdtmp += chr(req.hostid)
        cmdtmp += chr(req.subhostid)    

        # cmdtmp += self.changeformat(self.v_left)
        # cmdtmp += self.changeformat(self.v_right)
        cmdtmp += self.changeformat(req.leftmotorspeed)
        cmdtmp += self.changeformat(req.rightmotorspeed)
        cmdtmp += self.changeformat(req.encodeclear)
        cmdtmp += self.changeformat(req.suckwindmotorenable)
        cmdtmp += self.changeformat(req.suckwindpwmlevel)
        cmdtmp += self.changeformat(req.suckwatermotorenable)
        cmdtmp += self.changeformat(req.suckwaterpwmenable)
        cmdtmp += self.changeformat(req.brushplatepushenable)
        cmdtmp += self.changeformat(req.brushplatepushtime)
        cmdtmp += self.changeformat(req.suckwaterpushenbale)
        cmdtmp += self.changeformat(req.suckwaterpushtime)
        cmdtmp += self.changeformat(req.spraywaterelectvalveenbale)
        cmdtmp += self.changeformat(req.spraywaterelectvalvelevel)
        cmdtmp += self.changeformat(req.turnonwaterelectvalveenbale)
        cmdtmp += self.changeformat(req.turnonwaterelectvalvelevel)
        cmdtmp += self.changeformat(req.stirringmotorenable)
        cmdtmp += self.changeformat(req.stirringmotorpwmenable)
        cmdtmp += self.changeformat(req.brushplateenable)
        cmdtmp += self.changeformat(req.brushplatepwdlevel)
        cmdtmp += chr(req.checknumhigh)
        cmdtmp += chr(req.checknumlow)

        self.cmd = cmdtmp 
    
    def setSensorMessageCmd(self):
        self.controlsensor.header1 = 0xAE
        self.controlsensor.header2 = 0xEA
        self.controlsensor.hostid = 0x01
        self.controlsensor.subhostid = 0x5A
        self.controlsensor.imudata = int(0)
        self.controlsensor.encoderdata = int(0)
        self.controlsensor.wavedata = int(0)
        self.controlsensor.glosscheckdata = int(0)
        self.controlsensor.collisiondata = int(0)

    def getMessagebyCmd2(self, req):
        cmdtmp = ''
        checksum = self.checkSensorSum(req, 0)
        retdata = c_int(checksum)
        req.checknumhigh = (retdata.value & 0xff00) >> 8
        req.checknumlow = retdata.value & 0xff  
        cmdtmp += chr(req.header1)        
        cmdtmp += chr(req.header2) 
        cmdtmp += chr(req.hostid)
        cmdtmp += chr(req.subhostid)
        cmdtmp += self.changeformat(req.imudata)
        cmdtmp += self.changeformat(req.encoderdata)
        cmdtmp += self.changeformat(req.wavedata)
        cmdtmp += self.changeformat(req.glosscheckdata)
        cmdtmp += self.changeformat(req.collisiondata)
        cmdtmp += chr(req.checknumhigh)
        cmdtmp += chr(req.checknumlow)
        
        self.Sensorcmd = cmdtmp 
    
    def poll(self):
        now = rospy.Time.now()
        if now > self.t_next:                      
            if now > (self.last_cmd_vel + rospy.Duration(self.timeout)):
                self.v_des_left = 0
                self.v_des_right = 0
                
            if self.v_left < self.v_des_left:
                self.v_left += self.max_accel
                if self.v_left > self.v_des_left:
                    self.v_left = self.v_des_left
            else:
                self.v_left -= self.max_accel
                if self.v_left < self.v_des_left:
                    self.v_left = self.v_des_left
            
            if self.v_right < self.v_des_right:
                self.v_right += self.max_accel
                if self.v_right > self.v_des_right:
                    self.v_right = self.v_des_right
            else:
                self.v_right -= self.max_accel
                if self.v_right < self.v_des_right:
                    self.v_right = self.v_des_right
            # self.lVelPub.publish(self.v_left)
            # self.rVelPub.publish(self.v_right)            

            if not self.stopped:
                self.controldata.leftmotorspeed = int(self.v_left)
                self.controldata.rightmotorspeed = int(self.v_right)
                self.originSpeed = int(self.v_left)
                self.originRotate = int(self.v_right)                
                self.getMessagebyCmd1(self.controldata)        
                self.MotorControl.drive(self.cmd)     
            self.t_next = now + self.t_delta
            
    def stop(self):
        self.stopped = True
        # self.MotorControl.drive(0, 0)
            
    def isPassedCallback(self, msg):
        if(msg.data>2):
            self.isPassed = False
        else:
            self.isPassed = True


    def isPassedCallback_2(self, msg):
        if(msg.data>2):
            self.isPassed_2 = False
        else:
            self.isPassed_2 = True

    def getCmdswitchFlagCallback(self, switchFlag):
        # print "call back switch flag: ", switchFlag
        if switchFlag.data == True:
            self.globSwitchflag = True
        else:
            self.globSwitchflag = False

    def initControldata(self, initcontroldataValue):
        initcontroldataValue.leftmotorspeed = 0
        initcontroldataValue.rightmotorspeed = 0        
        self.initencodeclearflag = True
	self.globSwitchflag = False
        self.getMessagebyCmd1(initcontroldataValue)


    def cmdVelCallback(self, req):
        # Handle velocity-based movement requests
        self.last_cmd_vel = rospy.Time.now()
        # robot_cmd_vel = Twist()
        
        x = req.linear.x         # m/s
        th = req.angular.z       # rad/s
        # self.originSpeed = x
        # self.originRotate = req.angular.z
        # # print "origin speed is: ", req.linear.x

        # if self.emergencybt_val==1:
        #     robot_cmd_vel.linear.x = 0
        #     robot_cmd_vel.linear.y = 0
        #     robot_cmd_vel.angular.z = 0
        # else:
        #     robot_cmd_vel.linear.x = x
        #     robot_cmd_vel.linear.y = 0
        #     robot_cmd_vel.angular.z = th
            
        # self.robot_cmd_vel_pub.publish(robot_cmd_vel)

        # if (self.useSonar == True) :
        #     if((self.sonar_r0<=self.safe_range_0 and self.sonar_r0>=2) and (x>0)):
        #         x= 0.0
        #         th=-0.2
        #         rospy.logwarn("sonar0 smaller than safe_range_0, only trun rigth")

        #     if((self.sonar_r1<=self.safe_range_0 and self.sonar_r1>=2) and (x>0)):
        #         x=0.0
        #         th=0.2
        #         rospy.logwarn("sonar1 smaller than safe_range_0, only trun left")

        #     if(((self.sonar_r2<=self.safe_range_0 and self.sonar_r2>=2)) and (th>0)) or (((self.sonar_r2<=self.safe_range_0 and self.sonar_r2>=2))and (x>0.0)):
        #         x=0.0  
        #         th= -0.2
        #         rospy.logwarn("sonar_r2 smaller than safe_range_0")


        #     if(((self.sonar_r3<=self.safe_range_0 and self.sonar_r3>=2)) and (th<0)) or (((self.sonar_r3<=self.safe_range_0 and self.sonar_r3>=2))and (x>0.0)):
        #         x=0.0
        #         th= 0.2
        #         rospy.logwarn("sonar_r3 smaller than safe_range_0")

        # if not self.isPassed and x>0:
        #     x = 0

        # if not self.isPassed_2 and x>0:
        #     x = 0

        # print "x  angle is: ", x 
        # print "th speed is: ", th
        left = 0 
        right = 0
        if x == 0:
            if th>0.0 and th<0.2:
                th=0.2
            elif th>-0.2 and th<0.0:
                th=-0.2

            right = th * self.wheel_track  * self.gear_reduction / 2.0
            left = -right
            # print "1final left speed is: ", left  
            # print "1final right speed is: ", right 
        elif th == 0:
            left = right = x 
            # print "speed x is: ", x
            # print "2final left speed is: ", left  
            # print "2final right speed is: ", right            
        else:
            if (th>0.0 and th<0.2) and (x>-0.05 and x<0.05):
                th=0.2
            if (th>-0.2 and th<0.0) and (x>-0.05 and x<0.05):
                th=-0.2

            left = x - th * self.wheel_track  * self.gear_reduction / 2.0
            right = x + th * self.wheel_track  * self.gear_reduction / 2.0
            # print "3final left speed is: ", left  
            # print "3final right speed is: ", right 

        # print "2final left speed is: ", left  
        # print "2final right speed is: ", right  
        self.v_des_left = int(left * self.ticks_per_meter / self.MotorControl.PID_RATE)
        self.v_des_right = int(right * self.ticks_per_meter / self.MotorControl.PID_RATE)

        # print "v_des_left left speed is: ", self.v_des_left  
        # print "v_des_right right speed is: ", self.v_des_right  
class MotorControlROS():
    def __init__(self):
        rospy.init_node('MotorControl', log_level=rospy.DEBUG)
                
        # Cleanup when termniating the node
        rospy.on_shutdown(self.shutdown)
        
        self.port = rospy.get_param("~port", "/dev/ttyStm32")
        self.baud = int(rospy.get_param("~baud", 115200))
        self.timeout = rospy.get_param("~timeout", 0.5)
        self.base_frame = rospy.get_param("~base_frame", 'base_link')

        # Overall loop rate: should be faster than fastest sensor rate
        self.rate = int(rospy.get_param("~rate", 50))
        r = rospy.Rate(self.rate)

        # Rate at which summary SensorState message is published. Individual sensors publish
        # at their own rates.        
        self.sensorstate_rate = int(rospy.get_param("~sensorstate_rate", 10))
        
        self.use_base_controller = rospy.get_param("~use_base_controller", False)
        
        
        # Set up the time for publishing the next SensorState message
        now = rospy.Time.now()
        self.t_delta_sensors = rospy.Duration(1.0 / self.sensorstate_rate)
        self.t_next_sensors = now + self.t_delta_sensors
        
        # Initialize a Twist message
        self.cmd_vel = Twist()
  
        # A cmd_vel publisher so we can stop the robot when shutting down
        self.cmd_vel_pub = rospy.Publisher('cmd_vel', Twist, queue_size=5)
        
        # Initialize the controlller
        self.controller = MotorControl(self.port, self.baud, self.timeout)
        
        # Make the connection
        self.controller.connect()
        
        rospy.loginfo("Connected to MotorControl on port " + self.port + " at " + str(self.baud) + " baud")
     
        # Reserve a thread lock
        mutex = thread.allocate_lock()
              
        # Initialize the base controller if used
        if self.use_base_controller:
            self.myBaseController = BaseController(self.controller, self.base_frame)
    
        # Start polling the sensors and base controller
        while not rospy.is_shutdown():           
                    
            if self.use_base_controller:
                mutex.acquire()
                self.myBaseController.poll()           
                mutex.release()
            r.sleep()
    
    def shutdown(self):
        # Stop the robot
        try:
            rospy.loginfo("Stopping the robot...")
            self.cmd_vel_pub.publish(Twist())
            rospy.sleep(2)
        except:
            pass
        rospy.loginfo("Shutting down MotorControl Node...")
        
if __name__ == '__main__':
    myMotorControl = MotorControlROS()

