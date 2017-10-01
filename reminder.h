#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER 150
#define STORAGE_SIZE 1000
#define DATE_LIMIT 50

FILE *file;

char *tod;
char month_abb[100];
char buffer[BUFFER];

time_t today;
struct tm * time_info;

//struct to store date and reminder message
struct reminder_list {
	char date[BUFFER];
	char message[BUFFER];
} Reminder;

//gets current month, day, and year
int get_month();
int get_day();
char *get_month_abb();
char *get_curr_time(); 

//sets reminder date and message
void set_message();
void read_reminder();
void write_reminder();
void delete_prev_reminders();
void sort_reminders();
void startup();
