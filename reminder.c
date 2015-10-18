#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct node{
  char *remind; 
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

  new_node = malloc(sizeof(struct node));
  //new_node->reminder = "test";
  //new_node->next = first;
  //first = new_node;

  printf("What day would you like to set a reminder for?");
  printf("\n(dd mm)\n");

  scanf("%d %d", &dd, &mm);

  // if(mm == (tm_mon+1))
  //getDays()

  //printf("%d %d\n", dd, mm);

  printf("Enter your message : ");
  scanf("%s", &reminder);
  //insert node
  //scanf("%s", &new_node->remind);
 

  return 0;
}
