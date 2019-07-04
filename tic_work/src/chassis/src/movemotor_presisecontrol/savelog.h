#ifndef __LOG_H__
#define __LOG_H__

#include <ros/ros.h>
#include <fstream>
#include <stdarg.h>
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

#define TIC_LOG(...) ticSaveLogToFile(__VA_ARGS__)

#define TIC_DEBUG(...)  ROS_DEBUG(__VA_ARGS__)
#define TIC_INFO(...)   ROS_INFO(__VA_ARGS__)
#define TIC_WARN(...)   ROS_WARN(__VA_ARGS__)
#define TIC_ERROR(...)  ROS_ERROR(__VA_ARGS__)
#define TIC_FATAL(...)  ROS_FATAL(__VA_ARGS__)

#define TIC_LOG_DEBUG(...)  {TIC_LOG(__VA_ARGS__);TIC_DEBUG(__VA_ARGS__);}
#define TIC_LOG_INFO(...)   {TIC_LOG(__VA_ARGS__);TIC_INFO(__VA_ARGS__);}
#define TIC_LOG_WARN(...)   {TIC_LOG(__VA_ARGS__);TIC_WARN(__VA_ARGS__);}
#define TIC_LOG_ERROR(...)  {TIC_LOG(__VA_ARGS__);TIC_ERROR(__VA_ARGS__);}
#define TIC_LOG_FATAL(...)  {TIC_LOG(__VA_ARGS__);TIC_FATAL(__VA_ARGS__);}

static std::string ticSetLogName(void)
{
  std::string file;
  struct passwd *pwd = nullptr;
  pwd = getpwuid(getuid());
  file = pwd->pw_name;

  if(file != "root")
  {
    file = "/home/"+file+"/log"+ros::this_node::getName()+".log";
  }
  else
  {
    file = "/"+file+"/log"+ros::this_node::getName()+".log";
  }
  return file;
}

static void ticSaveLogToFile(const char *format, ...)
{
  static std::string file;
  static std::string name;
  static bool flag = false;
  if(!flag) flag = true, file = ticSetLogName(),name = ros::this_node::getName();

  time_t t;
  struct tm * lt;
  time (&t);//获取Unix时间戳
  lt = localtime (&t);//转为时间结构

  char str_tmp[100];
  va_list vArgList; //定义一个va_list型的变量,这个变量是指向参数的指针.
  va_start (vArgList, format); //用va_start宏初始化变量,这个宏的第二个参数是第一个可变参数的前一个参数,是一个固定的参数
  vsnprintf(str_tmp, 100, format, vArgList); //注意,不要漏掉前面的_
  va_end(vArgList); //用va_end宏结束可变参数的获取

  std::ofstream out;
  out.open(file,std::ios::app);
  out<< lt->tm_year+1900 << '/' << lt->tm_mon << '/' << lt->tm_mday << ' '<< lt->tm_hour <<':'<< lt->tm_min << ':' << lt->tm_sec <<" "<< name << " ";
  out<<str_tmp<<"\n";
  out.close();
}

#endif // LOG_H
