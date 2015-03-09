#include "zombie.h"
#include<stdio.h>

/**
 * Returns the amount of toes from a zombie
 * @param z The zombie
 * @return The amount of toes
 */
int get_toes(struct Zombie z)
{
        return z.toes;
}

/**
 * Returns the amount of blood spilled from a zombie
 * @param z The zombie
 * @return The amount of blood
 */
float get_blood(struct Zombie z)
{
        return z.blood;
}

/**
 * Returns the day a zombie was encountered
 * @param z The zombie
 * @return The day it was encountered
 */
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

/**
 * Returns the date and time a zombie was encountered
 * @param z The zombie
 * @param result A string to store the result in
 */
void get_time(struct Zombie z, char *result)
{
       sprintf(result, "%s - %d:%d:%d", get_day(z), z.hour, z.min, z.sec);
}
