#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX 150
#define R 365

struct list{
  int day, month;
  char remind[MAX];
} list1;

int getMonth(){
  
  time_t mytime;
  struct tm * timeInfo;
  time(&mytime);
  timeInfo = localtime(&mytime);

  return (timeInfo->tm_mon + 1);
}

int getDay(){

  time_t mytime;
  struct tm * timeInfo;
  time(&mytime);
  timeInfo = localtime(&mytime);

  return (timeInfo->tm_mday);
}

void getCurrentTime(){

  time_t mytime;
  time(&mytime);
  printf(ctime(&mytime));
}

int setDay(){
  printf("For which day? ");
  scanf("%d",&(list1).day);
  return (list1.day);
}

int setMonth(){

  printf("Which month would you like to create a reminder for?\n");
  scanf("%d",&(list1).month);

  return (list1.month);
}
char *setReminder(){

  // int m = getMonth();
  // int d = getDay();

  printf("\nEnter your message for %d-%d\n", list1.month, list1.day);
  scanf("%s", &(list1).remind);

  // printf("%d %d\n%s\n", list1.month, list1.day, list1.remind);

  return (list1.remind);
}
int main(int argc, char *argv[]){

  getCurrentTime();

  setMonth();
  setDay();
  setReminder();


  return 0;
}
