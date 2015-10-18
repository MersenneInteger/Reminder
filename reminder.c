#include <stdio.h>
#include <time.h>

//#define MAX 100

struct node{
  int value; 
  struct node *next;
};
struct node *first = NULL;


int main(void){

  char *reminder[MAX];
  int dd, mm, i, j;
  

  //need to create seperate function for time
  time_t mytime;
  struct tm * timeInfo;
  time(&mytime);
  
  timeInfo = localtime(&mytime);
  printf("month: %d\n", timeInfo->tm_mon + 1);
  //test
  printf(ctime(&mytime));

  //printf("Reminder: ");
  //display reminder


  printf("What day would you like to set a reminder for?");
  printf("\n(dd mm)\n");

  scanf("%d %d", &dd, &mm);

  printf("%d %d\n", dd, mm);

  printf("Enter your message : ");
  scanf("%s", &reminder);

  
  

  


  return 0;
}
