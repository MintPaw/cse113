#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

struct Student
{
        int id;
        int grade1;
        int grade2;
        float average;
};

void get_real_char(char *c);
void create_menu();
int get_specific_even_number();
void print_enum();
struct Student set_student_data();

#endif
