/**
 * @file array.c
 * 
 * @author Scott Chadde
 *
 * @date 1/1/2013
 *  
 * Assignment: Lab 3 
 *
 * @brief Functions for fundamental array algorithms. 
 *
 * @details The functions implemented include basic counting, 
 * summing, searching, and basic statistical methods (average,
 * median, the max, the min). Sorting is implemented via
 * bubble sort, a not very efficient sort, and insertion sort.
 *  
 * @bugs none
 *
 * @todo implement floating point versions of the functions
 */


#include "array.h"
#include <stdio.h>


/** prints out the elements of an array, one element per line
 * @param a[] the array to print
 * @param size the size or length of the array
 */
void print_array(int a[], size_t size)
{
	int i;
	
	for(i = 0; i < size; i++)
		printf("a[%d] = %d\n", i, a[i]);
}

int find_max(int a[], size_t size)
{
        int max = a[0];
        int i = 0;

        for (i = 1; i < size; i++)
        {
                if (a[i] > max) max = a[i];
        }

        return max;
}

int find_min(int a[], size_t size)
{
        int min = a[0];
        int i = 0;

        for (i = 1; i < size; i++)
        {
                if (a[i] < min) min = a[i];
        }

        return min;
}

int find_midpoint(int max, int min)
{
        return (max + min) / 2;
}

int get_count(int a[], size_t size, int operation, int x)
{
        int count = 0;
        int i;
        for (i = 0; i < size; i++)
        {
                if (operation == LT)
                {
                        if (a[i] < x)
                        {
                                count++;
                        }
                } else if (operation == LE) {
                        if (a[i] <= x)
                        {
                                count++;
                        }
                } else if (operation == EQ) {
                        if (a[i] == x)
                        {
                                count++;
                        }
                } else if (operation == GT) {
                        if (a[i] > x)
                        {
                                count++;
                        }
                } else if (operation == GE) {
                        if (a[i] >= x)
                        {
                                count++;
                        }
                }
        }

        return count;
}
