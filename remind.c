#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <assert.h>
#define MAX 365
#define BUFF 150

char buffer[BUFF];
char *abbMonth(int m);

struct list{
  int day, month;
  char remind[MAX];
}list1;


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
  char *string = (ctime(&mytime));
  return string;
  
}

char *getCurAbbMonth(){
  char *st;
  time_t mytime;
  struct tm * timeInfo;
  time(&mytime);
  timeInfo = localtime(&mytime);
  strftime(st, 20, "Month : %h\n",timeInfo);
  return st;
}

int setDay(){
  printf("For which day? ");
  scanf("%d",&(list1).day); //add numerical day to list1 struct

  if(list1.day <= 0 || list1.day >= 31){ //range 1-31

    printf("Incorrect input, enter a date between 1-31: ");
    scanf("%d",&(list1).day); //retry getting correct input
    //I need to come back and create validation loop
  }
  return (list1.day);//return day as int
}

int setMonth(){

  printf("Which month would you like to create a reminder for?\n");
  scanf("%d",&(list1).month); //add numerical month to list1 struct

    if(list1.month <= 0 || list1.month > 12){ //range : 1-12
      
    printf("Incorrect input, enter a month between 1-12: ");
    scanf("%d",&(list1).month); //retry getting correct user input
	//I need to come back and put this all into a loop that only exits once the range is 
	//satisfied
    }
  return (list1.month); //returns month as int to be stored in variable
   
}

void getReminder(char *a, int d){
  
  char *st, *st_copy;
  FILE *file = fopen("reminder.bin", "rb+");
  int line = 2;
  size_t data;

  if(file == NULL){
    perror("file not found");
    exit(1);
  }

  while(!feof(file)){
    st_copy = fgets(buffer, BUFF, file);
    printf("%s", st_copy);
  }
  /*
 check:
  for(int i = 0; i < 2; i++){
    st[i] = getc(file);
    if(st[i] == ' ') break;
  }

  int dd = atoi(st);

  if(dd == d){
    for(int i=0; i < line;i++) {
      st_copy = fgets(buffer, BUFF, file);
      printf("%s", st_copy);
    }
  }else {
    fseek(file, BUFF, SEEK_SET);
    if(ferror(file)){
      printf("End of file, no reminder found.");
      exit(1);
    }else
	goto check;
  }
  */
}


int main(int argc, char *argv[]){

  int day, month;
  char *str, ans = 'n', *time, *input, *ab;
  long fileSize;
  size_t data;

  FILE *file = fopen("reminder.bin", "rb+"); //open binary file

  time = getCurrentTime(); //set time as a string
  printf("-%s\n", time); //prints time
  day = getDay(); //set day as int
  month = getMonth(); //set month as time
  ab = abbMonth(month); //set ab as the abbr of month
  struct list list1 = *(struct list*)malloc(sizeof(struct list)); //create struct to hold day and month
  
  
  if(file == NULL){ //if file does not exist
    
    file = fopen("reminder.bin","wb+"); //open a new binary file

    printf("Would you like to set a reminder (y/n)?\n");
    scanf("%c", &ans); //accept input as char
    

    if(ans == 'y'){
      
      month = setMonth(); //stores month as int
      day = setDay(); //stores day as int
      printf("Enter your reminder: ");
      str = (char *)malloc(BUFF+1); //create memory for string with max length of 150
     
      getline(&str,&data,stdin); //read line from std input
      fgets(str,150,stdin); //get total user input, store in str
      strcpy(&list1.remind[day], str); //copy str into list1 reminder

      snprintf(buffer, BUFF, "%s %d: %s\n", ab, day, &list1.remind[day]); // store in buffer
      //fwrite(&list1.remind[day], sizeof(char), sizeof(buffer), file);
      fwrite(buffer, sizeof(char), sizeof(buffer), file); //write to file
      printf("\nReminder set: \n"); 
      puts(buffer); //print buffer
      
      fseek(file, 0, SEEK_END); //go to end of file
      fileSize = ftell(file); //get file size
      rewind(file); //go to the beginning of file
      free(str); //free memory
    }
    exit(1); //exit program
  }

//if answer on line 151 was anything other than 'y'
      getReminder(ab, day); //retrieve reminder at date stored in ab and int stored in day
      
      printf("\nWould you like to set a reminder (y/n)?\n"); 
      scanf("%c", &ans);
       
      if(ans == 'y'){

	month = setMonth();
       	day = setDay();	
	printf("Enter your reminder : ");
	str = (char *)malloc(BUFF+1);
	
	getline(&str,&data,stdin);
        fgets(str,BUFF,stdin);
        strcat(str, time);
	strcpy(&list1.remind[day], str);
        snprintf(buffer, BUFF, "%s %d: %s\n", ab,day, &list1.remind[day]);
	fwrite(buffer, sizeof(char),sizeof(buffer), file);

	printf("\nReminder set: \n");
	puts(buffer);
	free(input);
    }
  
  fclose(file);
 
 
  return 0;
}

char *abbMonth(int m){

  char *str;
  
  switch (m) {
    
  case 1:
    str = "Jan";
    break;
  case 2:
    str = "Feb";
    break;
  case 3:
    str = "Mar";
    break;
  case 4:
    str = "Apr";
    break;
  case 5:
    str = "May";
    break;
  case 6:
    str = "Jun";
    break;
  case 7:
    str = "Jul";
    break;
  case 8:
    str = "Aug";
    break;
  case 9:
    str = "Sep";
    break;
  case 10:
    str = "Oct";
    break;
  case 11:
    str = "Nov";
    break;
  case 12:
    str = "Dec";
    break;
  default :
    str = "Date not found";
    break;
  
  }
  return str;
}
