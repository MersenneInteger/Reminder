#include <stdio.h>
#include "reminder.h"

/***************************/
int get_month()
{
    time(&today); 
    time_info = localtime(&today);
    return (time_info->tm_mon + 1);
}

int get_day()
{
    time(&today); 
    timeInfo = localtime(&today); 
    return (timeInfo->tm_mday); 
}

char *get_curr_time()
{
    time(&loctime);
    today = malloc(sizeof((ctime(&loctime))));
    today = ctime(&loctime);
    return today;
}

void set_date()
{

}

int set_day()
{
    int day;
    printf("For which day? ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &day);
      
    while(day < 1 || day > 31){   
        printf("Incorrect input, enter a date between 1-31: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &day);
    }
    return day;
}

int set_month()
{
    int month;
    printf("Which month would you like to create a reminder for?\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &month);
    
    while(month < 1 || month > 12) {
        printf("Incorrect input, enter a month between 1-12: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &month);
    }
    return month;
}

int main(int argc, char *argv[])
{
    char *curr_time = get_curr_time();
    set_day();
}
