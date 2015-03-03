/**
* @lab4_q4.c
* @brief Returns a date with the Zodiac sign
* 
* @author Jeru Sanders
* @date 2/27/2015
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum month
{
        JAN = 1, FEB, MAR, APR, MAY, JUNE,
        JUL, AUG, SEPT, OCT, NOV, DEC
};

struct date
{
        unsigned short day;
        unsigned short month;
        unsigned short year;
};

int main()
{
        struct date user_date;
        char month_string[16];
        char year_string[16];

        void getInput()
        {
                char temp[8];

                printf("Day: ");
                fgets(temp, 8, stdin);
                user_date.day = atoi(temp);

                printf("Month (1-12): ");
                fgets(temp, 8, stdin);
                user_date.month = atoi(temp);

                printf("Year: ");
                fgets(temp, 8, stdin);
                user_date.year = atoi(temp);
        }

        void calculate()
        {
                if (user_date.month == JAN) {
                        strcpy(month_string, "January");
                        strcpy(year_string, user_date.day <= 19 ? "Capricorn" : "Aquarius");
                } else if (user_date.month == FEB) {
                        strcpy(month_string, "Febuary");
                        strcpy(year_string, user_date.day <= 19 ? "Aquarius" : "pisces");
                } else if (user_date.month == MAR) {
                        strcpy(month_string, "March");
                        strcpy(year_string, user_date.day <= 20 ? "Pisces" : "Aries");
                } else if (user_date.month == APR) {
                        strcpy(month_string, "April");
                        strcpy(year_string, user_date.day <= 20 ? "Aries" : "Taurus");
                } else if (user_date.month == MAY) {
                        strcpy(month_string, "May");
                        strcpy(year_string, user_date.day <= 21 ? "Taurus" : "Gemini");
                } else if (user_date.month == JUNE) {
                        strcpy(month_string, "June");
                        strcpy(year_string, user_date.day <= 21 ? "Gemini" : "Cancer");
                } else if (user_date.month == JUL) {
                        strcpy(month_string, "July");
                        strcpy(year_string, user_date.day <= 22 ? "Cancer" : "Leo");
                } else if (user_date.month == AUG) {
                        strcpy(month_string, "August");
                        strcpy(year_string, user_date.day <= 22 ? "Leo" : "Virgo");
                } else if (user_date.month == SEPT) {
                        strcpy(month_string, "September");
                        strcpy(year_string, user_date.day <= 23 ? "Virgo" : "Libra");
                } else if (user_date.month == OCT) {
                        strcpy(month_string, "October");
                        strcpy(year_string, user_date.day <= 24 ? "Libra" : "Scorpio");
                } else if (user_date.month == NOV) {
                        strcpy(month_string, "November");
                        strcpy(year_string, user_date.day <= 23 ? "Scorpio" : "Sagittarius");
                }

                printf("%s %hu, %s\n\n", month_string, user_date.day, year_string);
        }

        while (1)
        {
                char choice[8];
                printf("1. Enter date\n2. Exit\nChoice: ");
                fgets(choice, 8, stdin);
                if (choice[0] == '2') {
                        break;
                }

                getInput();
                calculate();
        }


        return 0;
}
