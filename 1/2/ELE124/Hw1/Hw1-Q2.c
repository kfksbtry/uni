// Q2-Find and correct the mistake(s) in the following C program, then run the program with integer1 = 4 and integer2 = 5.
	
/* Addition program */
#include <stdio.h>

/* function main begins program execution */
int main(void) {
   int integer1; /* first number to be input by user | we need a semicolon here*/
   int integer2; /* second number to be input by user | we need a semicolon here*/
   int sum;      /* variable in which sum will be stored | we need to change the variable name*/ 

   printf("Enter first integer\n"); /* prompt | we need double quotes here*/
   scanf("%d", &integer1);        /* read an integer */

   printf("Enter second integer\n"); /* prompt */
   scanf("%d", &integer2);           /* read an integer */
   
   sum = integer1 + integer2; /* assign total to sum */

   printf("Sum is %d\n", sum); /* print sum */
   return 0; /* indicate that program ended successfully */

} /* end function main */

/* PROGRAM STARTED

Enter first integer
4
Enter second integer
5
Sum is 9

PROGRAM ENDED */