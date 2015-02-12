#include<stdio.h>

float find_interior_angles(float angle1, float angle2);

int main()
{
        printf("Tringle with angles 45, 45, the third angle is %lf\n", find_interior_angles(45, 45));
        printf("Tringle with angles 30, 60, the third angle is %lf\n", find_interior_angles(30, 60));
        return 0;
}

float find_interior_angles(float angle1, float angle2)
{
        return 180 - angle1 - angle2;
}
