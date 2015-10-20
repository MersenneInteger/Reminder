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

  // printf("%s", list1.remind);


  return (list1.remind[0]);
}

void updateRemindArray(char *rArray[], int size){
  //set variable i to equal the date and assign it
  //to index of RemindArray to increment days in real time

  //get day, store in variable, get day again, if day is not
  //the same then increment array

  //check new day, if messageFound is true display message, if not
  //ask them to set reminder

}



int main(int argc, char *argv[]){

  char *r[R+1];
  int month, day, currentDay;

  /* FILE *file;
  char *buffer;
  size_t reminderinFile;
  long fSize;

  file = fopen("reminder.bin", "rb+");

  if(file == NULL){
    file = fopen("reminder.bin", "wb+");
  }
  */
  getCurrentTime();

  setMonth();
  setDay();
  setReminder();
  printf("%s", list1.remind[0]);

  printf("%s", r[0]);

  
  return 0;
}

