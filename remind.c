#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h>
#define MAX 150

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

//getReminder function test
void *getReminder(int m, int d){

  size_t bytes;
  char buffer[150];
  bool found = true;
  char *st;
  FILE *file = fopen("reminder.bin", "rb+");

  if(file == NULL){
    perror("file not found");
    exit(1);
  }

  while(!feof(file)){
    bytes = fread(buffer, 150, 1, file);
    while(found){
      if(getc(file)== d){
	found = false;
	if(isdigit(buffer))
	 strtol(st,&buffer, 10);
	printf("%s", buffer);
      }
      else{
      	break;
	found = false;
      }
    }
   }
 }
int main(int argc, char *argv[]){

  int day, month;
  size_t data;
  char buffer[150];
  char *str, ans = 'n', *time, *timeStamp;
  long fileSize;
  char *input;

  FILE *file = fopen("reminder.bin", "rb+");

  time = getCurrentTime();
  printf("-%s", time);
  day = getDay();
  month = getMonth();

  
  if(file == NULL){
    
    file = fopen("reminder.bin","wb+");

    printf("Would you like to set a reminder (y/n)\n?");
    scanf("%c", &ans);

    if(ans == 'y'){
      
      month = setMonth();    
      day = setDay();
      
      //fwrite(&month, sizeof(int),1,file);
      //fwrite(&day, sizeof(int),1,file);
      //fseek(file, 9, SEEK_SET);
      
      printf("Enter your reminder: ");
      str = (char *)malloc(data+1);
      
      //c strings make life so hard
      getline(&str,&data,stdin);
      fgets(str,150,stdin);
      int num = strlen(str);
      snprintf(buffer, 150, "%d %d : %s\n", month, day, str); 

      fwrite(buffer,sizeof(str)/sizeof(str[0]),num, file);
      //fwrite(time,sizeof(char),50, file);
     
      while(!feof(file)){
	data = fread(buffer, 150, 1, file);
	printf("%s", buffer);
      }
 
      //confirm string input was read in correctly
      //puts(str);
       
      fseek(file, 0, SEEK_END);
      fileSize = ftell(file);
      rewind(file);

      char *buffer = (char*)malloc(sizeof(char)*fileSize);
      if(buffer == NULL)
	perror("Error");

      data = fread(buffer, 150, fileSize, file);
      if(data != fileSize)
	perror("Error");

      printf("%s\n", buffer);
      free(str);
      free(buffer);

    }
    exit(1);
  }

      month = getMonth();
      day = getDay();      
      getReminder(month, day);


      if(file == NULL){
	perror("file not found");
	exit(1);
      }
      
      rewind(file);
      while(!feof(file)){
	  data = fread(buffer, 150, 1, file);
	  printf("%s", buffer);
	}

      //fwrite(&month, sizeof(int),1,file);
      //fwrite(&day, sizeof(int),1,file);
      //fseek(file, 9, SEEK_SET);

       printf("Would you like to set a reminder (y/n)?\n");
       scanf("%c", &ans);

       
      if(ans == 'y'){

	month = setMonth();
       	day = setDay();
		
	printf("Enter your reminder : ");
	input = (char *)malloc(data+1);
	
	getline(&str,&data,stdin);
	input = fgets(str,150,stdin);

	snprintf(buffer, 150, "%d %d : %s\n", month, day, input); 

	fwrite(buffer, sizeof(input[0]),sizeof(input)/sizeof(char),file);
	int num = strlen(input);
      
	fwrite(str,sizeof(str)/sizeof(str[0]),num,file);
	//fwrite(time,sizeof(char),50, file);
	printf("Reminder set: \n");
	//puts(time);
	puts(buffer);
    }
  
  fclose(file);
 
  return 0;
}


