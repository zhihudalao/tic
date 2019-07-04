#include <tic.h>
#include <json11.h>
#include <GetVersion.h>
#include <iostream>

char *PID_;
bool navigation_running_;
bool mapping_running_;

void whatCallback(const std_msgs::String::ConstPtr& msg)
{    
    if (msg->data == "Mapping")	{
        *PID_ = 'ist_slam_node';
        std::cout << '1' << std::endl;
        if(!(mapping_running_ = tic::ProcessIsRun(PID_)))
        system("sh /root/sh/mapping.sh");
        std::cout << '2' << std::endl;
	 }
	else if(msg->data == "Navigation") {
        *PID_ = 'move_base';
        if(!(navigation_running_ = tic::ProcessIsRun(PID_)))
	    system("sh /root/sh/move_base.sh");
     }
}


void SavemapCallback(const std_msgs::BoolPtr &msg)
{
    if (msg->data) {   
            system("sh /root/zrbase/install_isolated/lib/ist_tools/savemap.sh");
            sleep(1);
            std::cout<<"Save map success"<<std::endl;
            system("rosnode kill /ist_slam_node");
            system("rosnode kill /ist_slam_occupancy_grid_node");
        }   
}


void PathRecordOrPlayCallback(const std_msgs::String::ConstPtr& msg)
{

   std::string s = msg->data;
   std::cout<< msg->data <<std::endl;
   std::string err;
   char ticCMD[255];
    auto json = json11::Json::parse(s,err);
   //std::string json_str = json.dump();
   std::string action =json["action"].string_value();
   std::string name = json["name"].string_value();
   int times = json["times"].int_value();
   
    if (action == "Record") { 
      sprintf(ticCMD,"rosrun MyPath Path%s  %s  %d", action.c_str() ,name.c_str(), times);
      system(ticCMD);
      std::cout<< ticCMD << std::endl;
   }
   if (action == "Play") { 
      sprintf(ticCMD,"rosrun MyPath Path%s  %s  %d", action.c_str() ,name.c_str(), times);
      std::cout<< ticCMD << std::endl;
      system(ticCMD);
   }
   if (action == "End") { 
      system("rosnode kill /playpath");        
      std::cout<< "End PathPlay" << std::endl;
   }

  

}



 int main(int argc, char *argv[]) {
   
   if (('v' == getopt(argc, argv, "v"))) {
      GetVersion();
      exit(0);
   } 
	ros::init(argc, argv, "tic_console");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("MappingOrNavi", 1000, whatCallback);
   ros::Subscriber sub_Save_map = n.subscribe("save_map", 1000, SavemapCallback);
   ros::Subscriber sub_PathRecordOrPlay = n.subscribe("PathRecordOrPlay", 1000, PathRecordOrPlayCallback);
//  ros::Subscriber sub_Exploration = n.subscribe("Exploration", 1000, ExplorationCallback);  	
   ros::spin();

	return 0;
}