#!/bin/bash

function set_env()
{ 
  source /root/zrbase/install_isolated/setup.bash
  source /root/tic_work/devel/setup.bash
  export ROS_MASTER_URI=http://192.168.8.88:11311
  export ROS_IP=192.168.8.88
  export ROS_HOSTNAME=192.168.8.88
  export TIC_SYSTEM_HOME=/root
  export TIC_BAG_DIR=${TIC_SYSTEM_HOME}/bag
  export TIC_LOG_DIR=${TIC_SYSTEM_HOME}/log
  
  if [[ ! -d ${TIC_BAG_DIR} ]]; then
   mkdir -p ${TIC_BAG_DIR}
  fi

  if [[ ! -d ${TIC_LOG_DIR} ]]; then
   mkdir -p ${TIC_LOG_DIR}
  fi

  source ${TIC_SYSTEM_HOME}/zrbase/install_isolated/setup.bash

  source ${TIC_SYSTEM_HOME}/tic_work/devel/setup.bash
   
  rosclean purge -y &> /dev/null

}

function start_core()
{
  echo "start roscore ....">> ${TIC_LOG_DIR}/launch.log
  roscore &> ${TIC_LOG_DIR}/roscore.log &
  for (( ; ; ))
  do
   echo "try to get run_id of roscore ..." >> ${TIC_LOG_DIR}/launch.log
   sleep 0.1
   run_id=`rosparam get /run_id 2>&1`
   ret=`echo "$run_id" | grep "ERROR" | awk -F ':' '{print $1}'`
   if [[ $ret != "ERROR" ]]; then
       echo "roscore is started, run_id:$run_id" >> ${TIC_LOG_DIR}/launch.log
       break
   fi
  done
}

function start_node()
{
  echo "start nodes ...">> ${TIC_LOG_DIR}/launch.log 
   
  sh ${TIC_SYSTEM_HOME}/sh/start_sensor.sh &> ${TIC_LOG_DIR}/launch.log &
  sh ${TIC_SYSTEM_HOME}/sh/navigation.sh &>${TIC_LOG_DIR}/launch.log &
  roslaunch rosbridge_server rosbridge_websocket.launch &> ${TIC_LOG_DIR}/launch.log &
  rosrun tic_console tic_console &> ${TIC_LOG_DIR}/launch.log &
  sh ${TIC_SYSTEM_HOME}/sh/joy.sh &>${TIC_LOG_DIR}/launch.log &
}

function record_bag()
{ 
   cd ${TIC_SYSTEM_HOME}/sh
  ./ticbag_record.py &> ${TIC_LOG_DIR}/bag.log &
}
set_env

start_core

start_node

#record_bag
