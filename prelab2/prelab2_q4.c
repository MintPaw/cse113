/* 9 errors found */

/* Needs to be 'stdio.h' */
#include <stdio>

/* Needs to be 'int main()' or needs to return void */
void main()
{
        /* Needs to be 'int input' or scan needs to be searching for %c */
        char input;

        printf("Enter a character: \n");
        /* Needs to be either '%c' or '%d' depending on the above error */
        /* Also needs to pass input be reference rather than by value */
        scanf("%f", input);

        switch (input) {
        /* These need to be straight quotes, other examples in the pdf didn't have this problem so I assume it's an error */
        case ’a’:
                printf("A is for apple .\n"); 
                /* Needs break */
        case ’b’;
                /* '/n' needs to be '\n' */
                printf("B is for Banana !/n");
                break;
        default:
                /* '%d' needs to be either '%c' or '%i' depending on above errors */
                printf("The letter %d isn’t important!\n", input);
        }

        return 0;
}
