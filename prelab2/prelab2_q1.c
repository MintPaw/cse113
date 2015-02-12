#include <stdio.h>
int main ()
{
        /* Get a user defined integer */
        int input = 0;
        printf("Enter an integer: ");
        scanf("%d", &input);

        /* Perform an action based based on the input */
        if (input == 1) {
                printf (" First is the worst .\n");
        }
        else if (input == 2) {
                printf("Second is the best. ");
                printf("Because it ’s the first prime! ");
        } else if (input == 5) {
                printf("I was walking down the street the other day when I saw my best friend Jeff. I walked up to him and mentioned that I had the craziest dream the other night. Jeff listened as I told him that the dream consisted of just one thing. A huge glowing number '5'. It was made of gold and sparkled with shiny diamonds. Jeff's curiosity was peaked. I went on to say that the first thing that I did in the morning was to grab the daily racing digest and look up the 5th race.\n");
                printf("Jeff raised an eyebrow. I told him that the #5 horse in the 5th race was named 'The 5th Element.' Jeff started grinning. Then I told him point-by-point what I did that entire day.\n");
                printf("I ate 5 bowls of cereal for breakfast and drank 5 cups of coffee\n");
                printf("I went for a 5 mile jog to clear my head\n");
                printf("I took a 5 minute shower to rinse off\n");
                printf("I dressed in the 5th suit I found in my closet\n");
                printf("I sat in my car for 5 minutes before starting it\n");
                printf("I drove to the racetrack and parked in the 5th stall in the 5th row\n");
                printf("I entered through the 5th admissions gate\n");
                printf("I bought 5 programs\n");
                printf("I went to the 5th betting window and bet $555 on the 5th horse in the 5th race\n");
                printf("I went and sat in the 5th row of the bleachers making sure there were 5 people sitting on both sides of me.\n");
                printf("I settled in and waited for the race to start.\n");
                printf("'Well,' said Jeff. 'Did your horse win\?\?'\n");
                printf("I frowned at Jeff and said, 'Stupid horse came in 5th.'\n");
        }
        else {
                printf("I can’t sing about %d.\n", input);
        }

        /* Terminates the program */
        return 0;
}
