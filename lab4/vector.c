#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Place all of your functions here for your Array Problems */

/**
* Multiplies an array by an integer
* @param array The array to multiply
* @param size The size of the array
* @param multiplier The integer to multiply the array by
*/
void multiply_array(int array[], int size, int multiplier)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array[i] *= multiplier;
        }
}

/**
* Adds an integer to an array 
* @param array The array to add to
* @param size The size of the array
* @param adder The integer to add to the array by
*/
void add_array(int array[], int size, int adder)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array[i] += adder;
        }
}

/**
* Adds together two arrays
* @param array1 The first array to add
* @param array2 The second array to add
* @param array3 The array to store the answer
* @param size The size of the array
*/
void add_arrays(int array1[], int array2[], int array3[], int size)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array3[i] = array1[i] + array2[i];
        }
}

/**
* Multiplies together two arrays
* @param array1 The first array to multiply
* @param array2 The second array to multiply
* @param array3 The array to store the answer
* @param size The size of the array
*/
void multiply_arrays(int array1[], int array2[], int array3[], int size)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array3[i] = array1[i] * array2[i];
        }
}

/**
* Multiplies together two arrays inversly
* @param array1 The first array to multiply
* @param array2 The second array to multiply
* @param array3 The array to store the answer
* @param size The size of the array
*/
void inversemul_arrays(int array1[], int array2[], int array3[], int size)
{
        int i;
        for (i = 0; i < size; i++)
        {
                array3[i] = array1[i] * array2[size - i - 1];
        }
}

/**
* Generates an array filled with random integers between 0 and x
* @param a An arrat
* @param x The upper bounds to the random integer
*/
void generate_array(int a[], int x)
{
        int i;
        for (i = 0; i < 10; i++)
        {
                a[i] = random() % x;
        }
}
