#include <cstdlib>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include <signal.h>
#include <std_msgs/Float32MultiArray.h>

namespace tic {
    
bool ProcessIsRun(char *proc)
{
    FILE *fp = NULL;
    int count = 1;
    int BUFSZ = 100;
    char buf[BUFSZ];
    char command[150];
    
    sprintf(command, "ps -ef | grep -w %s | wc -l",proc);

    if((fp = popen(command,"r")) == NULL)
    {
        return false;
    }
    if((fgets(buf,BUFSZ,fp)) != NULL)
    {
        count = atoi(buf);
     }
    pclose(fp);

    fp = NULL;
    if( count == 1 ) {
        return false;
    } else {
        return true;
    }
}
}