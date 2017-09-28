#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER 150
#define STORAGE_SIZE 1000

char *curr_day;
char *curr_month;
char *curr_year;
char month_abb[100];
int reminder_count;
char buffer[BUFFER];

time_t today;
struct tm * time_info;

//struct to store date and reminder message
struct reminder_list {
	char date[BUFFER];
	char message[BUFFER];
} Reminder;

//arrray of structs to store reminders to write to a file
struct reminder_list rem_storage[STORAGE_SIZE];

//gets current month, day, and year
int get_month();
int get_day();
char *get_month_abb();
char *get_curr_time(); 
int get_reminder_count(FILE *file);

//sets reminder date and message
void set_message();
void read_reminder(FILE *file, struct reminder_list r);
void write_reminder(FILE *file, struct reminder_list r, char *date, char *message);
void delete_prev_reminders(FILE *file, struct reminder_list r);
