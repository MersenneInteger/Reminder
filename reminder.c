#include <stdio.h>
#include "reminder.h"

/********************************* F U N C T I O N S ********************************/

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
    while(month < 1 || month > 12) {
        printf("Enter a month between 1-12: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &month);
    }
    return month;
}
void set_date()
{
    int d = set_day();
    int m = set_month();

    struct tm *future_time;
    future_time = localtime(&today);
    future_time->tm_mon = m -1;
    future_time->tm_mday = d;

    mktime(future_time);
    strftime(Reminder.date, DATE_LIMIT, "%a %b %d ", future_time);
}
void set_message()
{
    printf("Enter your reminder: \n");
    fgets(buffer, sizeof(buffer), stdin);
    snprintf(Reminder.message, sizeof(Reminder.message), "%s", buffer);
}

void read_reminder()
{
    while(fread(&Reminder, sizeof(Reminder), 1, file))
        if(!strcmp(tod, Reminder.date))
            printf("%s\n%s\n", Reminder.date, Reminder.message);
}

void write_reminder()
{
    char ans = 'n';
    printf("Enter a reminder (y/n)? ");
    scanf("%c", &ans);
    if(ans == 'y' || ans == 'Y') {

        fclose(file);
        file = fopen(".reminders.bin", "ab");
        if(file == NULL) {
            fprintf(stderr, "errno :%d\n", errno);
            perror("Error");
            exit(EXIT_FAILURE);
        }
        set_date();
        set_message();
        fwrite(&Reminder, sizeof(Reminder), 1, file);
    } else exit(EXIT_SUCCESS);
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

    file = fopen(".reminders.bin", "rb");
    if(file == NULL) {
        fprintf(stderr, "errno :%d\n", errno);
        perror("Error");
        exit(EXIT_FAILURE);
    } 
}

/***************************** M A I N *******************************************/

int main(int argc, char *argv[])
{
    startup();
    printf("%s\n", tod);

    read_reminder(); 
    write_reminder();
    printf("-------------\n");
    read_reminder();

    fclose(file);
    free(tod);
}
