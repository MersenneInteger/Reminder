#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <assert.h>

#define DAYS 366 
#define BUFF 150

int iSIZE = 0;

/***************************/
char sBuffer[BUFF];
char *abbMonth(int m);

struct ReminderList{ //struct stores two int values for month and day and a string for reminder to be set

        char date[BUFF];
        char reminder[BUFF];

}List; //create var

struct ReminderList reminderStorage[DAYS];

/***************************/
void getiSize(FILE *file){
    
         int size;
         char temp[BUFF];
         file = fopen("reminder.txt", "r");
         strcpy(temp,fgets(sBuffer, BUFF, file));
         size = atoi(temp);
         printf("testing inside getiSize");
         printf("%d\n", size);
         // read first array index from file 
         //convert to int and assign to temp
         //iSize = temp + 1
        
}

void setiSize()
{
    iSIZE++;
}
int getMonth()
{

        time_t mytime; 
        struct tm * timeInfo; //creat struct to store time
        time(&mytime); //call time func
        timeInfo = localtime(&mytime); //store local time in struct

        return (timeInfo->tm_mon + 1); //returns the month 
}

int getDay()
{

        time_t mytime; //creat struct to store time
        struct tm * timeInfo; //call time func
        time(&mytime); 
        timeInfo = localtime(&mytime); //store local time in struct

        return (timeInfo->tm_mday); //return day
}

char *getCurrentTime()
{

        time_t mytime;
        time(&mytime);
        char *string = (ctime(&mytime)); //store time as a string, includes day and month
        return string;

}

char *getCurAbbMonth()
{
        char *st;
        time_t mytime;
        struct tm * timeInfo; //create struct to store time info
        time(&mytime);
        timeInfo = localtime(&mytime); //set local time
        strftime(st, 20, "Month : %h\n",timeInfo); //stores month abbreviation in st
        return st;
}

int setDay()
{
        int day;
        printf("For which day? ");
        scanf("%d", &day);
        if(day <= 0 || day > 31){  
                printf("Incorrect input, enter a date between 1-31: ");
                scanf("%d", &day);
        }
        return day;
}

int setMonth()
{
        int month;
        printf("Which month would you like to create a reminder for?\n");
        scanf("%d", &month);

        if(month <= 0 || month > 12) {
                printf("Incorrect input, enter a month between 1-12: ");
                scanf("%d", &month);
                //I need to come back and put this all into a loop that only exits once the range is 
                //satisfied
        }
        return month;
}

//void getReminder(FILE *file, char dateHeader[BUFF])
void getReminder(struct ReminderList List)
{
        //List.date ...
        /*
        file = fopen("reminder.bin", "rb");
        if(file == NULL)
        {
            perror("Error: File could not be opened.");
            exit(EXIT_FAILURE);
        }
        
        while(!feof(file))
        {   
            fgets(sBuffer, BUFF, file);
            if(strcmp(dateHeader, sBuffer) == 0)
                printf( " print reminder here ");
            return;
        } 
    */

}

int main(int argc, char *argv[])
{
        
        int iDay, iMonth;
        char *str, ans = 'n', *time, currentDate[BUFF];
        long lFileSize;
        size_t data;

        FILE *file = fopen("reminder.txt", "r"); //open binary file
        
        //getiSize(file); //testing

        time = getCurrentTime(); //set time as a string
        printf("-%s\n", time); //prints time

        iDay = getDay(); //set day as int
        iMonth = getMonth(); //set month as string
        snprintf(currentDate, BUFF, "%s %d", abbMonth(iMonth), iDay);
        printf("Current date: %s\n", currentDate);
        
        if(file == NULL)
        { //if file does not exist
                
                file = fopen("reminder.txt","a+"); //open a new binary file

                printf("Would you like to set a reminder (y/n)?\n");
                scanf("%c", &ans); //accept input as char


                if(ans == 'y')
                { 
                        
                        iMonth = setMonth();
                        iDay = setDay();
                        snprintf(List.date, BUFF, "%s %d", abbMonth(iMonth), iDay);

                        printf("Enter your reminder: ");
                        str = (char *)malloc(BUFF+1); //create memory for string with max length of 150

                        getline(&str,&data,stdin); //read line from std input
                        fgets(str,150,stdin); //get total user input, store in str

                        snprintf(List.reminder, BUFF, "%s %s", List.date, str); 
                        setiSize();
                        printf("%d\n", iSIZE);
                        reminderStorage[iSIZE + 1] = List;

                        //printf("Testing: %s\n", reminderStorage[iSIZE+1].date);
                        fwrite(&reminderStorage[iSIZE+1],sizeof(char), sizeof(reminderStorage), file);

                        //fseek(file, 0, SEEK_END); //go to end of file
                        //lFileSize = ftell(file); //get file size
                        //rewind(file); //go to the beginning of file
                        free(str); //free memory
                }
                exit(1); //exit program
       }

        //if answer on line 151 was anything other than 'y'

        //getReminder(ab, day); //retrieve reminder at date stored in ab and int stored in day
        /*
        printf("\nWould you like to set a reminder (y/n)?\n"); 
        scanf("%c", &ans);

        if(ans == 'y')
        {
                //getiSize(file);
                iMonth = setMonth();
                iDay = setDay();	
                printf("Enter your reminder : ");
                str = (char *)malloc(BUFF+1);

                getline(&str,&data,stdin);
                fgets(str,BUFF,stdin);
                strcat(str, time);

                strcpy(&List.reminder[iDay], str);
                snprintf(sBuffer, BUFF, "%s: %s\n", ab, &List.reminder[iDay]);
                fwrite(sBuffer, sizeof(char),sizeof(sBuffer), file);

                printf("\nReminder set: \n");
                puts(sBuffer);
                setiSize();
        }
*/
        fclose(file);

        return 0;
}

char *abbMonth(int m)
{
        char *str;

        switch (m) {

                case 1:
                        str = "Jan";
                        break;
                case 2:
                        str = "Feb";
                        break;
                case 3:
                        str = "Mar";
                        break;
                case 4:
                        str = "Apr";
                        break;
                case 5:
                        str = "May";
                        break;
                case 6:
                        str = "Jun";
                        break;
                case 7:
                        str = "Jul";
                        break;
                case 8:
                        str = "Aug";
                        break;
                case 9:
                        str = "Sep";
                        break;
                case 10:
                        str = "Oct";
                        break;
                case 11:
                        str = "Nov";
                        break;
                case 12:
                        str = "Dec";
                        break;
                default :
                        str = "Date not found";
                        break;
        }
        return str;
}
