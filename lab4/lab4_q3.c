/**
* @lab4_q3.c
* @brief Calculated distances between points
* 
* @author Jeru Sanders
* @date 2/27/2015 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Point
{
        double x;
        double y;
};

int main()
{
        char temp1[8];
        char temp2[8];

        printf("X1: ");
        fgets(temp1, 8, stdin);
        
        printf("Y1: ");
        fgets(temp2, 8, stdin);

        struct Point p1 = { atoi(temp1), atoi(temp2) };

        printf("X2: ");
        fgets(temp1, 8, stdin);

        printf("Y2: ");
        fgets(temp1, 8, stdin);

        struct Point p2 = { atoi(temp1), atoi(temp2) };

        printf("\nEuclidean distance: %lf\n", sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p2.y)));
        printf("Manhatten distance: %d\n", abs(p2.x - p1.x) + abs(p2.y - p1.y));

        return 0;
}
