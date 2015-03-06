#ifndef ZOMBIE_H_
#define ZOMBIE_H_

struct Zombie
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

int get_toes(struct Zombie z);
float get_blood(struct Zombie z);
char* get_day(struct Zombie z);
void get_time(struct Zombie z, char *result);

float get_blood();

#endif
