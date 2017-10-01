#include <stdio.h>
#include "reminder.h"

/**************F U N C T I O N S***********************************************/

int get_month()
{
    return (time_info->tm_mon + 1);
}

int get_day()
{
    return (time_info->tm_mday); 
}

char *get_month_abb()
{
    strftime(month_abb, DATE_LIMIT, "%b", time_info);
    return month_abb;
}

char *get_curr_time()
{
    time_info = localtime(&today);
    time(&today);
    ctime(&today);
    tod = malloc(sizeof((ctime(&today))));
    strftime(tod, DATE_LIMIT, "%a %b %d ", time_info);
    return tod;
}

int set_day()
{
    int day = -1;
    printf("For which day? ");
      
    while(day < 1 || day > 31){   
        printf("Enter a date between 1-31: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &day);
    }
    return day;
}

int set_month()
{
    int month = -1;
    printf("Which month would you like to create a reminder for?\n");
    
    while(month < 1 || month > 12) {
        printf("Enter a month between 1-12: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &month);
    }
    return month;
}
void set_date()
{
    snprintf(Reminder.date, sizeof(Reminder.date), "%s", tod);
}
void set_message()
{
    printf("Enter your reminder: \n");
    fgets(buffer, sizeof(buffer), stdin);
    snprintf(Reminder.message, sizeof(Reminder.message), "%s", buffer);
}

void read_reminder()
{

}

void write_reminder()
{
    /*
        get length of array storing reminder structs
        write to next available entry after checking for overflow
    */
}

void delete_prev_reminders()
{

}

void sort_reminders()
{

}
void startup()
{
    get_curr_time();

    file = fopen(".reminders.txt", "a");
    if(file == NULL) {
        fprintf(stderr, "errno :%d\n", errno);
        perror("Error");
        exit(EXIT_FAILURE);
    } 
}

/**************** M A I N **************************************************/

int main(int argc, char *argv[])
{
    startup();

    printf("%s\n", tod);
    
    set_day();
    set_date();
    set_message();
    
    printf("%s\n", Reminder.date);
    printf("%s\n", Reminder.message);

    fclose(file);
    free(tod);
}
