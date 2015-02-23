 /**
 * @file lab3.c
 * 
 * @author Scott Chadde
 *
 * @date 1/1/2013
 *  
 * Assignment: Lab 3 
 *
 * @brief a program that tests the functions in array.c
 *
 * @details 
 *  
 * @bugs none
 *
 * @todo none
 */

#include <stdio.h>
#include "array.h"

void print_summary(int a[], size_t size);

int main(void)
{
	int a[] = {9, 7, 5, 3, 2, 77, 8, 12, 4, 5, 11};

        int test1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int test2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int test3[] = {5, 7, 8, 4, 3, 10, 1, 4, 4, 5};

        printf("find_max works: %s\n", find_max(test1, 10) == 10 ? "yes" : "no");
        printf("find_max works: %s\n", find_max(test2, 10) == 10 ? "yes" : "no");
        printf("find_max works: %s\n", find_max(test3, 10) == 10 ? "yes" : "no");
        printf("find_min works: %s\n", find_min(test1, 10) == 1 ? "yes" : "no");
        printf("find_min works: %s\n", find_min(test2, 10) == 1 ? "yes" : "no");
        printf("find_min works: %s\n", find_min(test3, 10) == 1 ? "yes" : "no");
        printf("find_midpoint works: %s\n", find_midpoint(2, 10) == 6 ? "yes" : "no");
        printf("get_count works: %s\n", get_count(test1, 10, LT, 5) == 4 ? "yes" : "no");
        printf("get_count works: %s\n", get_count(test1, 10, LE, 5) == 5 ? "yes" : "no");
        printf("get_count works: %s\n", get_count(test1, 10, EQ, 5) == 1 ? "yes" : "no");
        printf("get_count works: %s\n", get_count(test1, 10, GT, 5) == 5 ? "yes" : "no");
        printf("get_count works: %s\n", get_count(test1, 10, GE, 5) == 6 ? "yes" : "no");
        printf("\n");

        size_t size = sizeof(a) / sizeof(a[0]);

	print_array(a, size);
        print_summary(a, size);

	return 0;
}

void print_summary(int a[], size_t size)
{
        int max = find_max(a, size);
        int min = find_min(a, size);

        printf("size of array = %zu\nmax element = %d\nmin element = %d\nmidpoint = %d\n", size, max, min, find_midpoint(max, min));
        printf("midpoint%s found in array\n", linear_search(a, size, find_midpoint(max, min)) != -1 ? "" : " not");

        printf("\nBubble sorted:\n");
        bubble_sort(a, size);
        print_array(a, size);        

        printf("\nReversed:\n");
        reverse(a, size);
        print_array(a, size);        

        printf("\nInsert sorted:\n");
        insertion_sort(a, size);
        print_array(a, size);        
}
