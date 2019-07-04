#include <ros/ros.h>
#include <iostream>
#include "motorlist.h"
#include "info.h"
#include "savelog.h"

/****************************************
* 作者/公司  : ***
* 函数介绍   : 主函数
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
int main(int argc, char **argv)
{
    if('v' == getopt(argc,argv, "v"))
        std::cout << __DATE__ << "\r\n" << __TIME__ << "\r\n" <<"Revision:" << "V2.18" << std::endl, exit(0);

    ros::init(argc,argv, "chassis");
    InfoCmdList infolist;
    Motorlist motorlist;

    ros::Rate loop_rate(100); //运行频率
    while(ros::ok())
    {
        infolist.run();
        motorlist.run();
        loop_rate.sleep();
    }

	return 0;
}
