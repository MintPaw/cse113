#ifndef ZOMBIE_H_
#define ZOMBIE_H_

struct zombie
{
        char dead;
        enum { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY,
                FRIDAY, SATURDAY, SUNDAY } day;
        int toes;
        float blood;
        int hour;
        int min;
        int sec;
};

float get_blood();

#endif
