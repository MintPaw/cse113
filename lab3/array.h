/**
 * @file array.h
 * 
 * @author Scott Chadde
 *
 * @date 1/1/2013
 *  
 * Assignment: Lab 3 
 *
 * @brief header file for array.c
 *
 * @details see array.c for details
 *  
 * @bugs none
 *
 * @todo add floating point versions of the functions
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#define LT 0
#define LE 1
#define EQ 2
#define GT 3
#define GE 4

#include <stdlib.h> 		/* for size_t declaration */

/* function declarations go here */
void print_array(int a[], size_t size);
int find_max(int a[], size_t size);
int find_min(int a[], size_t size);
int find_midpoint(int max, int min);
int get_count(int a[], size_t size, int operation, int x);
int linear_search(int a[], size_t size, int search);
void bubble_sort(int a[], size_t size);
void insertion_sort(int a[], size_t size);
void reverse(int a[], size_t size);

#endif

