#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct node{
  char *remind;
  int day, month;
  struct node *next;
};
struct node *first = NULL;
struct node *last = NULL;

void createReminder(){
  struct node *new_node = malloc(sizeof(struct node));

  new_node->next = NULL;

  printf("Which month would you like to set a reminder for?\n");
  scanf("%d", &(new_node)->month);
  printf("For which day?\n");
  scanf("%d\n",&(new_node)->day);

  printf("Enter your message : ");
  scanf("%s", &(new_node)->remind);

  first = last = new_node;


}
  
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

  //new_node->reminder = "test";
  //new_node->next = first;
  //first = new_node;

  createReminder();

  // if(mm == (tm_mon+1))
  //getDays()

  //printf("%d %d\n", dd, mm);



 

  return 0;
}
