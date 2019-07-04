#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
uint8_t nHour;
uint8_t nMinute;
uint8_t nSecond;
uint8_t nMonth;
uint8_t nDay;
uint8_t nWeek;
uint16_t nYear;
}RTC_TIME_DEF;


char *myStrncpy(char *dest, const char *src, int n) {
int size = sizeof(char)*(n + 1);
char *tmp = (char*) malloc(size); 
if (tmp) {
memset(tmp, '\0', size); 
memcpy(tmp, src, size - 1); 
memcpy(dest, tmp, size); 

free(tmp);
return dest;
}
else {
return NULL;
}
}


RTC_TIME_DEF GetVersion(void) {
char arrDate[20];
char arrTime[20]; 
char pDest[20];
RTC_TIME_DEF stTime;

sprintf(arrDate,"%s",__DATE__);//Jul 03 2018
sprintf(arrTime,"%s",__TIME__);//06:17:05
std::cout<< arrDate << std::endl;
std::cout<< arrTime << std::endl;
sprintf(pDest, "%s", myStrncpy(pDest, arrDate, 3));


sprintf(pDest, "%s", myStrncpy(pDest, arrDate + 4 + 3, 4));
stTime.nYear = atoi(pDest);
if (strcmp(pDest, "Jan") == 0) stTime.nMonth = 1;
else if (strcmp(pDest, "Feb") == 0) stTime.nMonth = 2;
else if (strcmp(pDest, "Mar") == 0) stTime.nMonth = 3;
else if (strcmp(pDest, "Apr") == 0) stTime.nMonth = 4;
else if (strcmp(pDest, "May") == 0) stTime.nMonth = 5;
else if (strcmp(pDest, "Jun") == 0) stTime.nMonth = 6;
else if (strcmp(pDest, "Jul") == 0) stTime.nMonth = 7;
else if (strcmp(pDest, "Aug") == 0) stTime.nMonth = 8;
else if (strcmp(pDest, "Sep") == 0) stTime.nMonth = 9;
else if (strcmp(pDest, "Oct") == 0) stTime.nMonth = 10;
else if (strcmp(pDest, "Nov") == 0) stTime.nMonth = 11;
else if (strcmp(pDest, "Dec") == 0) stTime.nMonth = 12;
else stTime.nMonth = 1;

sprintf(pDest, "%s", myStrncpy(pDest, arrDate+4, 2));
stTime.nDay = atoi(pDest);
sprintf(pDest, "%s", myStrncpy(pDest, arrTime, 2));
stTime.nHour = atoi(pDest);
sprintf(pDest, "%s", myStrncpy(pDest, arrTime+3, 2));
stTime.nMinute = atoi(pDest);
sprintf(pDest, "%s", myStrncpy(pDest, arrTime + 3 + 3, 2));
stTime.nSecond = atoi(pDest);

return stTime;
}