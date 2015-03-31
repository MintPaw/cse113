/**
* @file lab5.c
* @brief Keeps records on zombie encounters
* 
* @author Jeru Sanders
* @date 03/09/2015
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "zombie.h"

void get_real_char(char *c);

int main()
{
        struct Zombie zombie_list[64];
        int zombie_index = 0;
        for (;;)
        {
                char choice;

                printf("--- Zombie record keeping ---\n\n");
                printf("1. Enter new zombie information\n");
                printf("2. Display zombie information\n");
                printf("3. Return to fighting zombies (exit)\n");

                get_real_char(&choice);

                if (choice == '1')
                {
                        struct Zombie zombie;
                        char input[16];
                        printf("Was the zombie found dead? (Y/N)\n");
                        get_real_char(&choice);

                        if (choice == 'y')
                        {
                                zombie.blood = 0;
                                printf("Please enter the number of toes the zombie had: ");
                                fgets(input, 16, stdin);
                                zombie.toes = atoi(input);

                        } else if (choice == 'n') {
                                zombie.toes = 0;

                                printf("Please enter the amount of blood: "); 
                                fgets(input, 16, stdin);
                                zombie.blood = atoi(input);
                        }

                        printf("1. Monday\n");
                        printf("2. Tuesday\n");
                        printf("3. Wednesday\n");
                        printf("4. Thursday\n");
                        printf("5. Friday\n");
                        printf("6. Saturday\n");
                        printf("7. Sunday\n");
                        printf("Please choose the day this zombie was encountered: ");
                        fgets(input, 16, stdin);
                        zombie.day = atoi(input);

                        printf("Enter the time this zombie was encountered (HH:MM:SS): ");
                        fgets(input, 16, stdin);

                        sscanf(input, "%d:%d:%d", &zombie.hour, &zombie.min, &zombie.sec);

                        zombie_list[zombie_index++] = zombie;
                } else if (choice == '2') {
                        printf("#\ttoes\tblood\ttime\n");

                        int i;
                        for (i = 0; i < zombie_index; i++)
                        {
                                char time[64];
                                get_time(zombie_list[i], time);
                                printf("%d\t%d\t%0.1fml\t%s\n\n\n",
                                        i,
                                        get_toes(zombie_list[i]),
                                        get_blood(zombie_list[i]),
                                        time
                                        );
                        }
                } else {
                        return 0;
                }
        }

        return 0;
}

/**
* Gets a real character, filters things we don't want, also case insensitive
* @param c A pointer to a character to store the input
*/
void get_real_char(char *c)
{
        printf("Make a selection: ");

        char temp;
        while((temp = tolower(getchar())) != '\n')
        {
                *c = temp;
        }
}
