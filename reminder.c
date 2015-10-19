#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  
  if(new_node == NULL){
    printf("No messages for this day.");
    return;
  }
 
  printf("Which month would you like to set a reminder for?\n");
  scanf("%d", &(new_node)->month);
  printf("For which day?\n");
  scanf("%d",&(new_node)->day);
  //repeat:
  printf("Enter your message : ");
  scanf("%s", &(new_node)->remind);

  /*  if(strlen(new_node->remind) > 200)
    printf("A reminder must be less than 200 characters. Please try again.");
  goto repeat;
  */
  first = last = new_node;

}

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

void deleteNode(){

}
int main(void){

  char *reminder[MAX];
  int dd, mm, i, j;
  
  printf("%d-",getMonth());
  printf("%d\n", getDay());
  deleteNode();
  createReminder();

  return 0;
}

