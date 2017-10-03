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
    int m = set_month();
    int d = set_day();

    struct tm *future_time;
    future_time = localtime(&today);
    future_time->tm_mon = m-1;
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

void file_err_check(FILE *f)
{
    if(f == NULL) {
        fprintf(stderr, "errno :%d\n", errno);
        perror("Error");
        exit(EXIT_FAILURE);
    } 
}

void read_reminder()
{
    fclose(file);
    file = fopen(".reminders.bin", "rb");
    file_err_check(file);

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
        file_err_check(file);

        set_date();
        set_message();
        fwrite(&Reminder, sizeof(Reminder), 1, file);
    } else return;
}

void delete_prev_reminders()
{
    fclose(file);
    file = fopen(".reminders.bin", "rb+");
    FILE *new_file = fopen(".temp.bin", "ab");
    file_err_check(file);
    file_err_check(new_file);

    char tmp[DATE_LIMIT];
    char tmp2[DATE_LIMIT];
    snprintf(tmp, sizeof(tmp), "%s", tod);
    memmove(tmp, tmp + 4, 10);
    
    while(fread(&Reminder, sizeof(Reminder), 1, file)) {
        snprintf(tmp2, sizeof(tmp2), "%s", Reminder.date);
        memmove(tmp2, tmp2+4, 10);
        if(strcmp(tmp, tmp2) <= 0)
            fwrite(&Reminder.date, sizeof(Reminder), 1, new_file);
    } 
    int rem_err = remove(".reminders.bin");
    if(rem_err) {
        perror("file removal failure");
        return;
    }
    int ren_err = rename(".temp.bin", ".reminders.bin");
    if(ren_err) {
        perror("rename failed");
        return;
    }
}

void sort_reminders()
{

}

void startup()
{
    get_curr_time();
    file = fopen(".reminders.bin", "ab");
    file_err_check(file);
}

/***************************** M A I N *******************************************/

int main(int argc, char **argv)
{
    startup();
    printf("%s\n----------\n", tod);
    read_reminder(); 
    write_reminder();
    delete_prev_reminders();

    fclose(file);
    free(tod);
}
