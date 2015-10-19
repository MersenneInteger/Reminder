#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

struct node{
  char *remind;
  int day, month;
  struct node *next;
};
struct node *first = NULL;
struct node *last = NULL;

void createReminder(){

  char ch;
  
  struct node *new_node = malloc(sizeof(struct node));

  new_node->next = NULL;

  printf("Which month would you like to set a reminder for?\n");
  scanf("%d", &(new_node)->month);
  printf("For which day?\n");
  scanf("%d",&(new_node)->day);

  printf("Enter your message : ");
  scanf("%s", &(new_node)->remind);

  first = last = new_node;
  //...

}

int getMonth(){
  //return month
  time_t mytime;
  struct tm * timeInfo;
  time(&mytime);
  
  timeInfo = localtime(&mytime);
  // printf("month: %d\n", timeInfo->tm_mon + 1);
  //test
  // printf(ctime(&mytime));
  return (timeInfo->tm_mon + 1);

}

int getDay(){

  time_t mytime;
  struct tm * timeInfo;
  time(&mytime);
  timeInfo = localtime(&mytime);

  return (timeInfo->tm_mday);
}

void deleteNode(){

}
int main(void){

  char *reminder[MAX];
  int dd, mm, i, j;

  //testing
  
  printf("%d-",getMonth());
  printf("%d\n", getDay());
  deleteNode();

  //new_node->reminder = "test";
  //new_node->next = first;
  //first = new_node;

  createReminder();

  return 0;
}

