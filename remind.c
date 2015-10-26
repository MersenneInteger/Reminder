#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define _GNU_SOURCE

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

}

void updateRemindArray(char *rArray[], int size){


}

int main(int argc, char *argv[]){

  int day, month, currentDay, nbytes = 150;
  bool exists = true;
  char *str;
  //version 1.1, using binary files instead of linked lists to store and retreive data

  FILE *file = fopen("reminder.txt", "rb");
  if(file == NULL){
    exists = false;
    file= fopen("reminder.txt","wb");
  }
  if(exists){
    printf("Would you like to set a reminder (set) or get a reminder(get)?");
    str = (char *)malloc(nbytes+1);
    nbytes = getline(&str, &nbytes, stdin);

    if(nbytes == -1)
      puts("Error");
    else
      {
	puts("You typed :");
	puts(str);
      }

    
  }

  getCurrentTime();

  setMonth();
  setDay();
  setReminder();
 


  
  return 0;
}

