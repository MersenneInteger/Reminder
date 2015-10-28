#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
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

char *getCurrentTime(){

  time_t mytime;
  time(&mytime);
  //printf(ctime(&mytime));
  char *string = (ctime(&mytime));
  return string;
  
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
/*
char *getReminder(int m, int d){
  

}
*/

int main(int argc, char *argv[]){

  int day, month, currentDay;
  size_t data = 150;
  bool exists = true;
  char *str, ans = 'n', *time;
  long fileSize;
  //version 1.1, using binary files instead of linked lists to store and retreive data

  //getCurrentTime();
  FILE *file = fopen("reminder.bin", "rb");

  time = getCurrentTime();

  if(file == NULL){
    
    exists = false;
    file= fopen("reminder.bin","wb+");
  
    if(exists){
      printf("Would you like to set a reminder (y/n)\n?");
      scanf("%c", &ans);

    if(ans == 'y'){
      printf("Enter your reminder: ");
      str = (char *)malloc(data+1);
      getline(&str,&data,stdin);

      //c strings make life so hard
      fgets(str,150,stdin);

      fwrite(str, sizeof(str[0]),sizeof(str)/sizeof(char),file);
      int num = strlen(str);
      
      fwrite(time,sizeof(char),50, file);
      fwrite(str,sizeof(str)/sizeof(str[0]),num,file);
      //confirm string input was read in correctly
      puts(str);
       
      fseek(file, 0, SEEK_END);
      fileSize = ftell(file);

      rewind(file);

      char *buffer = (char*)malloc(sizeof(char)*fileSize);
      if(buffer == NULL)
	perror("Error");

      data = fread(buffer, 1, fileSize, file);
      if(data != fileSize)
	perror("Error");

      printf("%s\n", buffer);
      free(str);
      free(buffer);
    }
   }
  }else{
      printf("%s", time);
      month = setMonth();
      day = setDay();

      fwrite(&month, sizeof(int),1,file);
      fwrite(&day, sizeof(int),1,file);

      printf("Enter your reminder : ");
      str = (char *)malloc(data+1);
      getline(&str,&data,stdin);

      fgets(str,150,stdin);

      fwrite(str, sizeof(str[0]),sizeof(str)/sizeof(char),file);
      int num = strlen(str);
      
      fwrite(time,sizeof(char),50, file);
      fwrite(str,sizeof(str)/sizeof(str[0]),num,file);

      puts(str);

    }
  
  fclose(file);
 
  return 0;
}

