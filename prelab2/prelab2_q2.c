#include <stdio.h>
int main ()
{
        /* Gets a users defined integer */
        int input = 0;
        printf("Enter an integer: ");
        scanf("%d", &input);

        /* Make a choice based on the integer */
        switch(input) {
                case 1:
                        printf("One is the loneliest number.\n");
                        break;
                case 3:
                        printf("Three is just as bad as one. ");
                        printf("But worse. Because it’s 3!\n");
                        break;
                case 7:
                        printf("Why is 6 afraid of bla bla bla...\n"); 
                        break;
                default:
                        printf("I can’t sing about %d.\n", input);
        }

        /* Terminates the program */
        return 0;
}
