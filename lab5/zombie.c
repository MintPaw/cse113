#include "zombie.h"
#include<stdio.h>

int get_toes(struct Zombie z)
{
        return z.toes;
}

float get_blood(struct Zombie z)
{
        return z.blood;
}

char* get_day(struct Zombie z)
{
        if (z.day == 1) return "Monday";
        if (z.day == 2) return "Tuesday";
        if (z.day == 3) return "Wednesday";
        if (z.day == 4) return "Thursday";
        if (z.day == 5) return "Friday";
        if (z.day == 6) return "Saturday";
        if (z.day == 7) return "Sunday";
        return "N/A";
}

void get_time(struct Zombie z, char *result)
{
       sprintf(result, "%d:%d:%d - %s", z.hour, z.min, z.sec, get_day(z));
}
