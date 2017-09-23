#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <assert.h>

/***************************/
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

int main(int argc, char *argv[])
{

}
