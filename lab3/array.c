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

int linear_search(int a[], size_t size, int search)
{
        int i;
        for (i = 0; i < size; i++)
        {
               if (a[i] == search) return i; 
        }

        return -1;
}

void bubble_sort(int a[], size_t size)
{
        int sorted = 0;
        int i;
        int temp;
        while (!sorted)
        {
                sorted = 1;

                for (i = 1; i < size; i++)
                {
                        if (a[i - 1] > a[i])
                        {
                                sorted = 0;
                                temp = a[i];
                                a[i] = a[i - 1];
                                a[i - 1] = temp;
                        }
                }
        }
}

void insertion_sort(int a[], size_t size)
{
        int i;
        int j;
        int temp;
        int sorted = 0;
        while (!sorted)
        {
                sorted = 1;
                for (i = 1; i < size; i++)
                {
                        for (j = i; j >= 0; j--)
                        {
                                if (a[j] > a[i])
                                {
                                        sorted = 0;
                                        temp = a[i];
                                        a[i] = a[j];
                                        a[j] = temp;
                                }
                        }
                }
        }
}

void reverse(int a[], size_t size)
{
        int i;
        int temp;
        for (i = 0; i < size / 2; i++)
        {
                temp = a[i];
                a[i] = a[size - 1 - i];
                a[size - 1 - i] = temp;
        }
}

int median(int a[], size_t size)
{
        return size % 2
                ? a[size / 2] + a[(size / 2) + 1] / 2
                : a[(size + 1) / 2];
}
