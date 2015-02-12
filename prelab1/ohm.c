#include<stdio.h>

float volts(float amps, float ohms);
float amps(float volts, float ohms);
float ohms(float volts, float amps);

int main()
{
        printf("V = 120, I = 15; %lf\n", ohms(120, 15));
        printf("I = 1, R = 4000; %lf\n", volts(1, 4000));
        printf("V = 15, R = 1000; %lf\n", amps(15, 1000));
        return 0;
}

float volts(float amps, float ohms)
{
        return amps * ohms;
}

float amps(float volts, float ohms)
{
        return volts / ohms;
}

float ohms(float volts, float amps)
{
        return volts / amps;
}
