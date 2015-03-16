#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
#include "string.h"

int main(void)
{
        struct Student students[2];

        for (;;)
        {
                create_menu();
                char choice;
                get_real_char(&choice);

                if (choice == '1')
                {
                        printf("It's %d\n", get_specific_even_number());
                } else if (choice == '2') {
                        int a1[12] = {22, 43, 52, 66, 102, 98, 44, 987, 363, 233, 5, 1};
                        int max = a1[0];
                        int min = a1[0];
                        int average = 0;
                        int i;
                        for (i = 0; i < 12; i++)
                        {
                                if (a1[i] > max)
                                {
                                        max = a1[i];
                                }
                                
                                if (a1[i] < min)
                                {
                                        min = a1[i];
                                }

                                average += a1[i];
                        }

                        average /= 12;

                        printf("Min: %d\nMax: %d\nAverage: %d\n", min, max, average);
                } else if (choice == '3') {
                        print_enum();
                } else if (choice == '4') {
                        students[0] = set_student_data();
                        students[1] = set_student_data();
                } else if (choice == '5') {
                        printf("id, grade1, grade2, average\n");
                        int i;
                        for (i = 0; i < 2; i++)
                        {
                                printf("\n%d, %d, %d, %0.1f\n",
                                        students[i].id, 
                                        students[i].grade1, 
                                        students[i].grade2, 
                                        students[i].average);
                        }
                } else if (choice == '6') {
                        return 0;
                }
        }

        return 0;
}

