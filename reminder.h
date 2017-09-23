#include <stdio.h>

#define BUFFER 150
#define STORAGE_SIZE 1000

char *curr_day;
char *curr_month;
char *curr_year;
int reminder_count;

//struct to store date and reminder message
struct reminder_list {
	char date[BUFFER];
	char message[BUFFER];
} Reminder;

//arrray of structs to store reminders to write to a file
struct reminder_list rem_storage[MAX_SIZE];

//gets current month, day, and year
char *get_month();
char *get_day();
char *get_year();
char *get_curr_time(); 
int get_reminder_count(File *file);

//sets reminder date and message
void set_date();
void set_message();
void read_reminder(FILE *file, struct reminder_list r);
void write_reminder(File *file, struct reminder_list r, char *date, char *message);
void delete_prev_reminders(File *file, struct reminder_list r);