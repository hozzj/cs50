/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
int mid;

bool search(int value, int values[], int n)
{
    mid = n / 2;
    
    // TODO: implement a searching algorithm
    if (value < 0)
    {
        printf("Please provide a positive number!!\n");
        return false;
    }
    else
    {
        if (value == values[mid])
        {
            return true;
        }
        else if (value > values[mid])
        {
            for (int i = 0; i < n; i += 1)
            {
                printf("mid is %d\n", mid);
                if (mid % 2)
                { 
                    mid += mid / 2 + 1;
                }
                mid += mid / 2;
                if (mid >= n)
                {
                    mid = n - 1;
                }
                if (value == values[mid])
                {
                    return true;
                }
            }
        }
        
        else if (value < values[mid])
        {
            for (int i = 0; i < n; i += 1)
            {
                if (mid % 2)
                {
                    mid -= (mid / 2 + 1);
                }
                mid /= 2;
                if (mid == 0)
                {
                    mid = n;
                }
                printf("mid is %d\n", mid);
                if (value == values[mid])
                {
                    return true;
                }
                
            }
            
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // for every element in the array
    for (int i = 0; i < n - 1; i += 1)
    {
        for (int j = i + 1; j < n; j += 1)
        {
            if (values[i] > values[j])
            {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    return;
}
