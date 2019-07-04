#ifndef __BOARD_DOWN_H__
#define __BOARD_DOWN_H__

#include "extur.h"
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int32.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "savelog.h"

#define UART_ENABLE (0)

//上下位机通信状态
enum pcDataStatus_Type
{
	pc_data_status_hard,
	pc_data_status_len,
	pc_data_status_sum,
	pc_data_status_data,
	pc_data_status_data_sum,
	pc_data_status_data_process
};

//上下位机数据缓存
struct pcData_Type
{
	uint8_t hard0;
	uint8_t hard1;
	uint16_t len;
	uint32_t sum;
	uint8_t data[2000];
};

//上下位机数据类型
struct pcDataSubType
{
	uint8_t id;
	uint8_t subid;
	int32_t data;
};

struct communicationBuf_Type
{
	uint8_t rx_buf[2000];
	uint8_t tx_buf[2000];
	uint16_t tx_index;
};

extern struct communicationBuf_Type BoardDataBuf; //发送至下位机的数据缓存

class BaordDown
{
public:
  BaordDown();
  //下位机断线重连
  void resetContBoard();
  //读取下位机数据
  uint16_t readBoardData(uint8_t *buf, uint16_t len);
  //下位机数据解析
  void boardDataProcess(uint8_t *buf, uint16_t len);
  //向下位机发送数据
  void sendBoardData(uint8_t *buf, uint16_t len);
  //控制下位机电机
  void setMotorStatus(void);

private:
  struct pcData_Type pcDataBuf = {0}; //接收下位机的数据缓存
  bool BoardOpenFlag = false; //串口打开标志
  //serial::Serial uart; //串口
  int socketfd; //socket
  struct sockaddr_in sockaddr;
  struct sockaddr_in client;

  //读取下位机数据长度
  uint16_t readBoardDataLen();
  uint32_t crcSum(uint8_t *buf, uint16_t len);
  enum pcDataStatus_Type boardDataSum();
  //将要发送的数据添加到缓存中
  void addSendCmd(uint8_t id, uint8_t subid, uint32_t data);

  //接收数据
  enum pcDataStatus_Type readBoardDataToBuf(uint8_t data);
  //接收校验
  enum pcDataStatus_Type readBoardSumToBuf(uint8_t data);
  //接收数据长度
  enum pcDataStatus_Type readBoardLenToBuf(uint8_t data);
  //接收数据头
  enum pcDataStatus_Type readBoardHardToBuf(uint8_t data);
  //下位机主ID处理
  enum pcDataStatus_Type subBoardDataProcess();
  //下位机标准格式处理
  void boardDataProcessID(struct pcDataSubType *data, uint8_t *buf);
  //主ID0数据解析
  void baordDataProcessID0(uint8_t id, int32_t data);
  //主ID1数据解析
  void baordDataProcessID1(uint8_t id, int32_t data);
  //主ID2数据解析
  void baordDataProcessID2(uint8_t id, int32_t data);
};
#endif
