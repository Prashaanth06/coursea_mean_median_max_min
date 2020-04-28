/******************************************************************************
* @file <stats.c>  
* Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/

/******************************************
 * @author: Prashaanth Rajendran
 * @date: Edited April 2020 
 *

* Description: A simple C program to order the list provided in 
			          a particular order and perform various stastical calculations
			          and report analysis of,
				            -maximum
                    -minimum
                    -mean
                    -median
******************************************/

/******************************************************************************	
 *Function:print_statistics
 *Description: A function that prints the statistics of an array including minimum, maximum, mean, and median.
 * Parameters: no arguments
 * Return: no return type
*******************************************************************************/	
 
/******************************************************************************	
 *Function:print_array
 *Description: Given an array of data and a length, prints the array to the screen.
 * Parameters: no arguments
 * Return: no return type
*******************************************************************************/

/******************************************************************************	
 *Function:find_median
 *Description: This function provides the median of the given array.
 * Parameters:no arguments
 * Return: no return type
*******************************************************************************/

/******************************************************************************	
 *Function: find_mean
 *Description: This function provides the mean of the given array.
 * Parameters: no arguments
 * Return: no return type
*******************************************************************************/

/******************************************************************************	
 *Function: find_maximum
 *Description: Given an array of data and a length, returns the maximum.
 * Parameters: no arguments
 * Return: no return type
*******************************************************************************/

/******************************************************************************	
 *Function: find_minimum
 *Description: Given an array of data and a length, returns the minimum
 * Parameters: no arguments
 * Return:no return type
*******************************************************************************/

/******************************************************************************	
 *Function: sort_array
 *Description: Given an array of data and a length, sorts the array from largest to smallest.
 * Parameters: no arguments
 * Return: no return type
*******************************************************************************/
#include <stdio.h>
#include <limits.h>
#include "stats.h"
  

/* Size of the Data Set */
#define SIZE (40)
int i=0;
int j=0;

/* Variables for mean function */
float sum=0;
float x=0;

/* Variables for Median */
float y=0;
int t;

/* Variables for Maximum number and Minimum number */
int first, second;

unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

void find_mean()
{
  for(i=0;i<SIZE;i++)
  {
  sum=sum+test[i];
  }
 x=(float)sum/(float)SIZE;
 printf("Mean\t= %f \n",x);
}

void find_median()
{
   for(i=0;i<SIZE;i++)
  {
  for(j=i+1;j<SIZE;j++)
   {
   if(test[i]>test[j])
    {
    t=test[i];
    test[i]=test[j];
    test[j]=t;
    }
   }
  }
 if(SIZE%2==0)
 y=(float)(test[SIZE/2]+test[(SIZE-1)/2])/2;
 else
 y=test[(SIZE-1)/2];
 printf("Median\t= %f \n",y);
}

void print_array()
{
for(i=0;i<SIZE;i++)
{
  printf("Entry number %d is %d \n",i,test[i]);
}
}

void find_maximum()
{
 /* There should be atleast two elements */
    if (SIZE < 2) 
    { 
        printf(" Invalid Input "); 
        return; 
    } 
  
    first = second = INT_MIN; 
    for (i = 0; i < SIZE ; i ++) 
    { 
        /* If current element is greater than first 
           then update both first and second */
        if (test[i] > first) 
        { 
            second = first; 
            first = test[i]; 
        } 
  
        /* If arr[i] is in between first and  
           second then update second  */
        else if (test[i] > second && test[i] != first) 
            second = test[i]; 
    } 
    if (second == INT_MIN) 
        printf("There is no second largest element\n"); 
    else
        printf("The largest element is %d \n", first); 
}

void find_minimum()
{
/* There should be atleast two elements */
    if (SIZE < 2) 
    { 
        printf(" Invalid Input "); 
        return; 
    } 
  
    first = second = INT_MAX; 
    for (i = 0; i < SIZE ; i ++) 
    { 
        /* If current element is greater than first 
           then update both first and second */
        if (test[i] < first) 
        { 
            second = first; 
            first = test[i]; 
        } 
  
        /* If arr[i] is in between first and  
           second then update second  */
        else if (test[i] < second && test[i] != first) 
            second = test[i]; 
    } 
    if (second == INT_MAX) 
        printf("There is no second largest element\n"); 
    else
        printf("The smallest element is %d \n", first); 
}

void sort_array()
{
  printf("The numbers are arranged in descending order \n");
 for(i=0;i<SIZE;i++)
  {
  for(j=i+1;j<SIZE;j++)
   {
   if(test[i]<test[j])
    {
    t=test[i];
    test[i]=test[j];
    test[j]=t;
    }
   }
   printf("%d\n", test[i]);
  }         
}

void print_statistics()
{
  printf(" The various analysis on the array has been made");
printf("\n");
find_mean();
printf("\n");
find_median();
printf("\n");
find_maximum();
printf("\n");
find_minimum();
printf("\n");
}

void main() {

/*printf("\nMean is printed\n");
find_mean();

printf("\nMedian is printed\n");
find_median();*/

printf("\nArray entries are printed\n");
print_array();

/*printf("\nMinimum:\n");
find_minimum();

printf("\nMaximum:\n");
find_maximum();*/

printf("\nSorting the array\n");
sort_array();

printf("\nStatistics\n");
print_statistics();

}

/* Add other Implementation File Code Here */
