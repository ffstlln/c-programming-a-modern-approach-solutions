/*
* C programming: A Modern Approach. Chapter 03, Project 06
* Date: January 2023
* Author: ffstlln
* Description: Modification of the Section 3.2 addfrac.c program to allow 
* entering both fractions at the same time
*/

#include <stdio.h>

int main(void)
{
    int num1, denom1, num2, denom2;

    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d / %d + %d / %d", &num1, &denom1, &num2, &denom2);


    printf("The sum is %d/%d\n", num1 * denom2 + num2 * denom1, denom1 * denom2);

    return 0;
}
