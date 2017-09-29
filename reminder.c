#include <stdio.h>
#include "reminder.h"

/******************************************************************/

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
    strftime(month_abb, sizeof(month_abb), "%b", time_info);
    return month_abb;
}

char *get_curr_time()
{
    time_info = localtime(&today);
    time(&today);
    tod = (char *)malloc(sizeof((ctime(&today))));
    tod = ctime(&today);
    return tod;
}

int set_day()
{
    int day;
    printf("For which day? ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &day);
      
    while(day < 1 || day > 31){   
        printf("Incorrect input, enter a date between 1-31: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &day);
    }
    return day;
}

int set_month()
{
    int month;
    printf("Which month would you like to create a reminder for?\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &month);
    
    while(month < 1 || month > 12) {
        printf("Incorrect input, enter a month between 1-12: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &month);
    }
    return month;
}
void set_date()
{
    int d = get_day();
    char *m = get_month_abb();
    snprintf(Reminder.date, sizeof(Reminder.date), "%s %d: ", m, d);
}
void set_message()
{
    printf("Enter your reminder: \n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%s", Reminder.message);
}

void read_reminder(FILE *file, struct reminder_list r)
{
    while(strcmp        
}

void write_reminder(FILE *file, struct reminder_list r, char *date, char *message)
{
    
}

void delete_prev_reminders(FILE *file, struct reminder_list r)
{

}

void sort_reminders(FILE *file, struct reminder_list r)
{

}
void startup()
{
    file = fopen(".reminders.txt", "a");
    if(file == NULL) {
        fprintf(stderr, "errno :%d\n", errno);
        perror("Error");
        exit(EXIT_FAILURE);
    } 
}

/******************************************************************/

int main(int argc, char *argv[])
{
    char *curr_time = get_curr_time();
    startup();

    printf("%s\n", tod);
    printf("%s\n", curr_time);
    printf("%d\n", get_month());
    printf("%d\n", get_day());
    printf("%s\n", get_month_abb());
    
    set_day();
    set_date();
    set_message();
    
    printf("%s\n", Reminder.date);
    printf("%s\n", Reminder.message);

    fclose(file);
    free(tod);
}
