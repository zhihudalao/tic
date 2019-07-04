#include "boardDown.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

struct communicationBuf_Type BoardDataBuf = {0}; //发送至下位机的数据缓存

/****************************************
* 作者/公司  : ***
* 函数介绍   : 下位机断线重连
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void BaordDown::resetContBoard(void)
{
	if(!NodeData.debug)
	{
#if UART_ENABLE
	if(BoardOpenFlag == false)
	{
		try
		{
			uart.close();
			uart.setPort("/dev/ttyBoard");
			uart.setBaudrate(115200);
			serial::Timeout to = serial::Timeout::simpleTimeout(1000);
			uart.setTimeout(to);
			uart.open();

			if(uart.isOpen())
			{
				ROS_INFO("Open ttyBoard OK");
				BoardOpenFlag = true;
			}
		}
		catch (serial::IOException& e)
		{
			BoardOpenFlag = false;
			ROS_ERROR("Open ttyBoard Uart Error");
			uart.close();
			sleep(1);
		}
	}
#else //网络通信
	static bool initFlag = false;
	int ret = 0;
	
	if(!BoardOpenFlag)
	{
		if(!initFlag)
		{
			socketfd = socket(AF_INET,SOCK_DGRAM,0); //创建套接字
			if(socketfd == -1)
			{
				ROS_ERROR("Socket Error");
			}
			//memset(&sockaddr, 0, sizeof(sockaddr));
			bzero(&sockaddr, sizeof(sockaddr));
			sockaddr.sin_family = AF_INET; //IPV4 协议
			sockaddr.sin_port = htons(8666); //服务器端口
			//sockaddr.sin_addr.s_addr = inet_addr("192.168.8.166"); //服务器IP
			sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

			if(bind(socketfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
			{
				ROS_ERROR("Socket bind Error");
			}
			else
			{
				ROS_INFO("Socket Bind OK");
				BoardOpenFlag = true;
			}
			
/*			
			int flags = fcntl(socketfd, F_GETFL, 0);//获取原始sockfd属性
			fcntl(socketfd, F_SETFL, flags | O_NONBLOCK);//添加非阻塞
			initFlag = true;
			ret = connect(socketfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
*/
		}
/*
		if(errno == EISCONN) //已经连接
		{
			BoardOpenFlag = true;
			ROS_INFO("Connect Board OK");
		}
		else //未连接成功
		*/
	/*
		{
			ret = connect(socketfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
			if(ret == 0)
			{
				BoardOpenFlag = true;
				ROS_INFO("Connect Board OK");
			}
			else
			{
				if(errno == EINPROGRESS) //正在连接中
				{
					ROS_ERROR("Wait connect Board");
				}
				else
				{
					ROS_ERROR("Connect Board Error");
				}
					
			}
		}*/
	}
#endif
	}
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 向下位机发送数据
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void BaordDown::sendBoardData(uint8_t *buf, uint16_t len)
{
  uint8_t tx_buf[20];
  int i = 0;
  uint32_t sum = 0;

  if(buf == NULL) return;

  sum = crcSum(buf, len);

  i = 0;
  tx_buf[i++] = 0xAE;
  tx_buf[i++] = 0xEA;
  tx_buf[i++] = len;
  tx_buf[i++] = len>>8;
  tx_buf[i++] = sum;
  tx_buf[i++] = sum >> 8;
  tx_buf[i++] = sum >> 16;
  tx_buf[i++] = sum >> 24;

#if UART_ENABLE
  try
  {
    uart.write(tx_buf, i);
    uart.write(buf, len);
  }
  catch (serial::IOException& e)
  {
    ROS_ERROR("Send ttyBoard Uart Data Error");
    BoardOpenFlag = false;
  }
#else
  if(BoardOpenFlag)
  {
    socklen_t addrlen=sizeof(client);
    sendto(socketfd, tx_buf, i, 0, (struct sockaddr *)&client, addrlen);
    sendto(socketfd, buf, len, 0, (struct sockaddr *)&client, addrlen);

    /*
    static int errorindex = 0;
    fd_set rfds, wfds;
    struct timeval tv;

    FD_ZERO(&rfds);FD_ZERO(&wfds);
    FD_SET(socketfd, &rfds);
    FD_SET(socketfd, &wfds);
    //set select() time out
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    int selres = select(socketfd + 1, &rfds, &wfds, NULL, &tv);
    switch (selres)
    {
      case -1:
        ROS_ERROR("select error");
        BoardOpenFlag = false;
        break;
      case 0:
        ROS_ERROR("select time out");
        BoardOpenFlag = false;
        break;
      default:
        if (FD_ISSET(socketfd, &wfds)) //可写状态
        {
          try
          {
            send(socketfd, tx_buf, i,0); ///发送
            send(socketfd, buf, len,0); ///发送
          }
          catch (serial::IOException& e)
          {
            ROS_ERROR("Read Socket Data Error");
            BoardOpenFlag = false;
          }
          errorindex = 0;
        }
        else
        {
          if(errorindex<10)
          {
            errorindex++;
          }
          else
          {
            ROS_ERROR("Read Socket Data Error");
            BoardOpenFlag = false;
          }
        }
        break;
    }
    */
  }
#endif
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 读取下位机数据
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
uint16_t BaordDown::readBoardData(uint8_t *buf, uint16_t len)
{
	int temp = 0;
	temp = 0;
	if(NodeData.debug)
	{
		temp = 1;
	}
	else
	{
#if UART_ENABLE
		len = readBoardDataLen();

		if(BoardOpenFlag == true)
		{
			try
			{
				temp = uart.read(buf, len);
			}
			catch (serial::IOException& e)
			{
				ROS_ERROR("Read ttyBoard Uart Data Error");
				BoardOpenFlag = false;		
			}				
		}
#else
		if(BoardOpenFlag)
		{
			socklen_t addrlen=sizeof(client);
			temp =recvfrom(socketfd,buf,2000,0,(struct sockaddr *)&client, &addrlen);
		}
#endif		
	}
	
	return temp;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 读取下位机数据长度
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
uint16_t BaordDown::readBoardDataLen()
{
	uint16_t len = 0;
	len = 0;

#if UART_ENABLE
	if(BoardOpenFlag == true)
	{
		try
		{
			len = uart.available();
		}
		catch (serial::IOException& e)
		{
			ROS_ERROR("Read ttyBoard Uart Data Len Error");
			BoardOpenFlag = false;
		}
	}
#endif
	return len;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 下位机数据校验计算
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
uint32_t BaordDown::crcSum(uint8_t *buf, uint16_t len)
{
	uint32_t sum = 0;
	uint32_t temp = 0;
	uint8_t i = 0;
	uint32_t *data = (uint32_t *)buf;
	
	//和校验
	for(i=0;i<(len/4);i++)
	{
		sum += data[i];
	}

	//长度不足时
	if(len%4 != 0x00)
	{
		switch(len%4)
		{
			case 1:
				temp = buf[len]<<24|0x00FFFFFF;
				break;
			case 2:
				temp = buf[len-1]<<24|buf[len]<<16|0x0000FFFF;
				break;
			case 3:
				temp = buf[len-2]<<24|buf[len-1]<<16|buf[len]<<8|0x000000FF;
				break;
			default:
				temp =  0;
				break;
		}
		sum += temp;
	}
	return sum;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 将要发送的数据添加到缓存中
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void BaordDown::addSendCmd(uint8_t id, uint8_t subid, uint32_t data)
{
  BoardDataBuf.tx_buf[BoardDataBuf.tx_index++] = id;
  BoardDataBuf.tx_buf[BoardDataBuf.tx_index++] = subid;
  BoardDataBuf.tx_buf[BoardDataBuf.tx_index++] = data;
  BoardDataBuf.tx_buf[BoardDataBuf.tx_index++] = data>>8;
  BoardDataBuf.tx_buf[BoardDataBuf.tx_index++] = data>>16;
  BoardDataBuf.tx_buf[BoardDataBuf.tx_index++] = data>>24;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 下位机数据头校验
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
enum pcDataStatus_Type BaordDown::readBoardHardToBuf(uint8_t data)
{
	static uint8_t temp = 0;
  enum pcDataStatus_Type ret;
	
	ret = pc_data_status_hard;
	
	if((temp == 0) && (data == 0xAE))
	{
    pcDataBuf.hard0 = data;
		temp = 1;
	}
	else if((temp == 1) && (data == 0xEA))
	{
		temp = 0;
    pcDataBuf.hard1 = data;
		ret = pc_data_status_len;
	}
	
	return ret;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 下位机数据长度解析
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
enum pcDataStatus_Type BaordDown::readBoardLenToBuf(uint8_t data)
{
	static char temp = 0;
  enum pcDataStatus_Type ret;
	
	ret = pc_data_status_len;
	if(temp == 0)
	{
    pcDataBuf.len = data;
		temp = 1;
	}
	else if(temp == 1)
	{
		temp = 0;
    pcDataBuf.len = pcDataBuf.len | data<<8;

    if(pcDataBuf.len != 0)
		{
			ret = pc_data_status_sum;
		}
		else
		{
			ret = pc_data_status_hard;
		}
	}

	return ret;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 下位机校验解析
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
enum pcDataStatus_Type BaordDown::readBoardSumToBuf(uint8_t data)
{
	static char temp = 0;
  enum pcDataStatus_Type ret;

	ret = pc_data_status_sum;
	
	if(temp == 0)
	{
		temp = 1;
    pcDataBuf.sum = data;
	}
	else if(temp == 1)
	{
		temp = 2;
    pcDataBuf.sum = pcDataBuf.sum | (data<<8);
	}
	else if(temp == 2)
	{
		temp = 3;
    pcDataBuf.sum = pcDataBuf.sum | (data<<16);
	}
	else if(temp == 3)
	{
		temp = 0;
    pcDataBuf.sum = pcDataBuf.sum | (data<<24);

    if(pcDataBuf.sum != 0)
		{
			ret = pc_data_status_data;
		}
		else //校验为0时，重新接收数据
		{
			ret = pc_data_status_hard;
		}
	}		

	return ret;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 将下位机数据添加到缓存中
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
enum pcDataStatus_Type BaordDown::readBoardDataToBuf(uint8_t data)
{
	static uint16_t temp = 0;
  enum pcDataStatus_Type ret;
	
	ret = pc_data_status_data;

  pcDataBuf.data[temp] = data;

  if(++temp >= pcDataBuf.len)
	{
		temp = 0;
		ret = pc_data_status_data_sum;
	}

	return ret;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 下位机数据校验
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
enum pcDataStatus_Type BaordDown::boardDataSum()
{
  enum pcDataStatus_Type ret;
	uint32_t crc = 0;

  crc = crcSum(pcDataBuf.data, pcDataBuf.len);

  if(crc == pcDataBuf.sum)
	{
		ret = pc_data_status_data_process;
	}
	else
	{
		ret = pc_data_status_hard;
	}

	return ret;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 下位机标准格式处理
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void BaordDown::boardDataProcessID(struct pcDataSubType *data, uint8_t *buf)
{
	data->id = buf[0];
	data->subid = buf[1];

	data->data = buf[2];
	data->data |= buf[3]<<8;
	data->data |= buf[4]<<16;
	data->data |= buf[5]<<24;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 下位机数据解析
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void BaordDown::boardDataProcess(uint8_t *buf, uint16_t len)
{
	static char status = 0;
	uint16_t i = 0;

	i = 0;
	while(i < len)
	{
		switch(status)
		{    
			case pc_data_status_hard:
        status = readBoardHardToBuf(buf[i]);//接收数据头
				break;
			case pc_data_status_len:     
        status = readBoardLenToBuf(buf[i]);//接收数据长度
				break;
			case pc_data_status_sum:
        status = readBoardSumToBuf(buf[i]);//接收校验
				break;
			case pc_data_status_data:
        status = readBoardDataToBuf(buf[i]);//接收数据
        if(status == pc_data_status_data_sum) status = boardDataSum();//计算校验
        if(status == pc_data_status_data_process) status = subBoardDataProcess();//数据解析
				break;
			default:
				status = pc_data_status_hard;//数据处理完成
				break;
		}
		i++;
	}
}

void BaordDown::setMotorStatus(void)
{
  TIC_LOG("down left speed = %d right speed = %d",
                           NodeData.motor.move.cmd_LeftSpeed,
                           NodeData.motor.move.cmd_RightSpeed);

  addSendCmd(0, 0x00, NodeData.motor.move.cmd_LeftSpeed); //左轮速度
  addSendCmd(0, 0x01, NodeData.motor.move.cmd_RightSpeed);//右轮速度

  if(NodeData.motor.brushLift.rSpeed != NodeData.motor.brushLift.dSpeed) //刷盘升降电机
	{
		TIC_LOG("down brush lift = %d",NodeData.motor.brushLift.dSpeed);
    addSendCmd(0, 4, NodeData.motor.brushLift.dSpeed);
	}

  if(NodeData.motor.wiperLift.dSpeed != NodeData.motor.wiperLift.rSpeed) //吸水条升降
	{
		TIC_LOG("down wiper lift = %d",NodeData.motor.wiperLift.dSpeed);
    addSendCmd(0, 5, NodeData.motor.wiperLift.dSpeed);
	}

  if(NodeData.motor.vacuum.dSpeed != NodeData.motor.vacuum.rSpeed) //吸风电机
	{
		TIC_LOG("down vacuum = %d",NodeData.motor.vacuum.dSpeed);
    addSendCmd(0, 2, NodeData.motor.vacuum.dSpeed);
	}

  if(NodeData.motor.brush.dSpeed != NodeData.motor.brush.rSpeed) //刷盘旋转
	{
		TIC_LOG("down brush = %d",NodeData.motor.brush.dSpeed);
    addSendCmd(0, 7, NodeData.motor.brush.dSpeed);
	}

  if(NodeData.motor.waterSpray.dSpeed != NodeData.motor.waterSpray.rSpeed) //喷水电机
	{
    TIC_LOG("down water spray = %d",NodeData.motor.waterSpray.dSpeed);
    addSendCmd(0, 3, NodeData.motor.waterSpray.dSpeed);
	}

  if(NodeData.cmd_valve != NodeData.info_valve) //阀门或继电器
	{
		TIC_LOG("down valve = %d",NodeData.cmd_valve);
		addSendCmd(0, 6, NodeData.cmd_valve);
	}
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 下位机主ID处理
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
enum pcDataStatus_Type BaordDown::subBoardDataProcess()
{
  struct pcDataSubType temp = {0};

  for(int i=0; i<pcDataBuf.len; i+=6)
	{
    boardDataProcessID(&temp, &pcDataBuf.data[i]);
		switch(temp.id)
		{
			case 0:
        baordDataProcessID0(temp.subid, temp.data);
				break;
			case 1:
        baordDataProcessID1(temp.subid, temp.data);
				break;
			case 2:
        baordDataProcessID2(temp.subid, temp.data);
				break;				
			default:
				break;
		}
	}

	return pc_data_status_hard;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 主ID0数据解析
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void BaordDown::baordDataProcessID0(uint8_t id, int32_t data)
{
	switch(id)
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		default:
			break;
	}
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 主ID1数据解析
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void BaordDown::baordDataProcessID1(uint8_t id, int32_t data)
{
	switch(id)
	{
		case 0:
      NodeData.encoder.info_left = data;
	  TIC_LOG("up encoder left = %d",NodeData.motor.brushLift.rSpeed);
			break;
		case 1:
      NodeData.encoder.info_right = data;
	  TIC_LOG("up encoder right = %d",NodeData.motor.brushLift.rSpeed);
			break;
		case 2:
      NodeData.encoder.info_time = data;
			break;
		case 6:
      NodeData.key.emergency = data?true:false;
			break;
		case 7:
      NodeData.motor.brushLift.rSpeed = data?1:0;
			TIC_LOG("up brush lift = %d",NodeData.motor.brushLift.rSpeed);
			break;
		case 8:
      NodeData.motor.wiperLift.rSpeed = data?1:0;
			TIC_LOG("up wiper lift = %d",NodeData.motor.wiperLift.rSpeed);
			break;
		case 9:
      NodeData.motor.vacuum.rSpeed = data;
			TIC_LOG("up vacuum = %d",NodeData.motor.vacuum.rSpeed);
			break;
		case 10:
      NodeData.motor.brush.rSpeed = data;
			TIC_LOG("up brush = %d",NodeData.motor.brush.rSpeed);
			break;
		case 11:
      NodeData.motor.waterSpray.rSpeed = data;
			TIC_LOG("up water spray = %d",NodeData.motor.waterSpray.rSpeed);
			break;
		case 12:
      NodeData.info_valve = data?true:false;
			break;
		case 13:
      NodeData.info_clear_waterl = data;
			break;
		case 14:
      NodeData.info_sewage_waterl = data;
			break;
		case 15:
			if(data > 0)
			{
        NodeData.battery.charger_current = 0;
        NodeData.battery.discharge_current = data/1000.0;
			}
			else
			{
        NodeData.battery.charger_current = data/1000.0;
        NodeData.battery.discharge_current = 0;
			}
			break;
		case 16:
      NodeData.battery.voltage = data/1000.0;
			break;
		case 17:
      NodeData.battery.electricity = data;
			break;
		case 18:
      NodeData.battery.temp = data;
			break;
		case 19:
      NodeData.pcb.time.run = data;
      NodeData.pcb.time.s = (NodeData.pcb.time.run/1000)%60;
      NodeData.pcb.time.m = (NodeData.pcb.time.run/1000/60)%60;
      NodeData.pcb.time.h = (NodeData.pcb.time.run/1000/60/60);
			break;
		case 20:
      NodeData.pcb.version =
			"V"+std::to_string((data>>24)&0xFF)+'.'+std::to_string((data>>16)&0xFF)+
			'.'+std::to_string((data>>8)&0xFF)+'.'+std::to_string((data>>0)&0xFF);
			break;
		case 21:
      NodeData.ultrasionic.distance[0] = data;
			break;
		case 22:
      NodeData.ultrasionic.distance[1] = data;
			break;
		case 23:
      NodeData.ultrasionic.distance[2] = data;
			break;
		case 24:
      NodeData.ultrasionic.distance[3] = data;
			break;
		case 25:
      NodeData.ultrasionic.distance[4] = data;
			break;
		case 26:
      NodeData.ultrasionic.distance[5] = data;
			break;
		case 27:
      NodeData.ultrasionic.distance[6] = data;
			break;
		case 28:
      NodeData.ultrasionic.distance[7] = data;
			break;
		case 29:
			TIC_LOG("ID = 1 SID = %d data = %d",id, data);
			if((data&0x00000001) == 0x00000001) NodeData.key.frontAntiCollision = true;//bit0 前 bint1 后
			else NodeData.key.frontAntiCollision = false;
			if((data&0x00000002) == 0x00000002) NodeData.key.breakAntiCollision = true;//bit0 前 bint1 后
			else NodeData.key.breakAntiCollision = false;
			break;
		case 30:
			NodeData.key.power = data?true:false; //关机返回1
			break;
		default:
			break;
	}
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 主ID2数据解析
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void BaordDown::baordDataProcessID2(uint8_t id, int32_t data)
{
	switch(id)
	{
		case 0:
			break;
		case 1:
			break;
		default:
			break;
	}
}

BaordDown::BaordDown()
{

}
