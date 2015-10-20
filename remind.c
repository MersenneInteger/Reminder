#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>

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

  if(list1.day <= 0 || list1.day >= 31){

    printf("Incorrect input, enter a date between 1-31: ");
    scanf("%d",&(list1).day);
  }
  return (list1.day);
}

int setMonth(){

  printf("Which month would you like to create a reminder for?\n");
  scanf("%d",&(list1).month);

    if(list1.month <= 0 || list1.month > 12){
      
    printf("Incorrect input, enter a month between 1-12: ");
    scanf("%d",&(list1).month);

    }
  return (list1.month);
   
}
char *setReminder(){


  printf("\nEnter your message for %d-%d\n", list1.month, list1.day);
  scanf("%s", &(list1).remind[0]);

  return (list1.remind[0]);
}

void updateRemindArray(char *rArray[], int size){


}

int main(int argc, char *argv[]){

  char *r[R+1];
  int month, day, currentDay;

  getCurrentTime();

  setMonth();
  setDay();
  setReminder();


  
  return 0;
}

