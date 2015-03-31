/**
* @file difference.c
* @brief Figures out the amount of sundays (1 Jan 1901 to 31 Dec 2000)
*       1 Jan 1900 was a Monday.
*       Thirty days has September,
*       April, June and November.
*       All the rest have thirty-one,
*       Saving February alone,
*       Which has twenty-eight, rain or shine.
*       And on leap years, twenty-nine.
*       A leap year occurs on any year evenly divisible by 4,
*       but not on a century unless it is divisible by 400.
* 
* @author Jeru Sanders
* @date 03/09/2015
*/

#include<stdio.h>

struct date
{
        int day;
        int month;
        int year;
};

int main()
{
        struct date start_date;
        struct date end_date;

        start_date.day = 1;
        start_date.month = 1;
        start_date.year = 1901;

        end_date.day = 31;
        end_date.month = 12;
        end_date.year = 2000;

        int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int is_leap;

        int current_day_of_week = 1;
        int sundays = 0;
        int year;
        for (year = 0; start_date.year + year < end_date.year; year++)
        {
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                {
                        is_leap = 1;
                } else {
                        is_leap = 0;
                }

                int month;
                for (month = 0; month < 12; month++)
                {
                        int day;
                        for (day = is_leap && month == 2 ? -1 : 0; day < days_per_month[month]; day++)
                        {
                               current_day_of_week++; 
                               if (current_day_of_week == 8)
                               {
                                       sundays++;
                                       current_day_of_week = 1;
                               }
                        }
                }
        }

        printf("It's %d\n", sundays);

        return 0;
}
