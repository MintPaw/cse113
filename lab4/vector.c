#include<stdio.h>

/* Place all of your functions here for your Array Problems */

void multiply_array(int array[], int size, int multiplier)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array[i] *= multiplier;
        }
}

void add_array(int array[], int size, int adder)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array[i] += adder;
        }
}

void add_arrays(int array1[], int array2[], int array3[], int size)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array3[i] = array1[i] + array2[i];
        }
}

void multiply_arrays(int array1[], int array2[], int array3[], int size)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array3[i] = array1[i] * array2[i];
        }
}

void inversemul_arrays(int array1[], int array2[], int array3[], int size)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array3[i] = array1[i] * array2[size - i];
        }
}
