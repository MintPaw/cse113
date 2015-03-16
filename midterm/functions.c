#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Student
{
        int id;
        int grade1;
        int grade2;
        float average;
};

enum movie_snacks
{
        POPCORN, SKITTLES, MNMS = 7, SODA,
        HOTTAMALES, KETTLECORN = 2
};

void get_real_char(char *c)
{
        printf("Make a selection: ");

        char temp;
        while((temp = tolower(getchar())) != '\n')
        {
                *c = temp;
        }
}

void create_menu()
{
        printf("\n\n1. Even number\n2. Max, min, average\n3. Enum\n");
        printf("4. Enter student data\n5. Display student data\n");
        printf("6. Exit\n");
}

int get_specific_even_number()
{
        int n = 0;
        int i;
        for (i = 2; ; i += 2)
        {
                if (i % 4 == 0 && i % 10 != 0)
                {
                        n++;
                        if (n == 45)
                        {
                                return i;
                        }
                }
        }
}

void print_enum()
{
        printf("POPCORN = %d\n", POPCORN);
        printf("SKITTLES = %d\n", SKITTLES);
        printf("MNMS = %d\n", MNMS);
        printf("SODA = %d\n", SODA);
        printf("HOTTAMALES = %d\n", HOTTAMALES);
        printf("KETTLECORN = %d\n", KETTLECORN);
}

struct Student set_student_data()
{
        char input[8];
        
        printf("Give student data\nid: ");
        fgets(input, 8, stdin);
        int id = atoi(input);

        printf("Grade 1: ");
        fgets(input, 8, stdin);
        int grade1 = atoi(input);

        printf("Grade 2: ");
        fgets(input, 8, stdin);
        int grade2 = atoi(input);

        float average = (grade1 + grade2) / 2.0;
        
        return (struct Student) {id, grade1, grade2, average};
}
