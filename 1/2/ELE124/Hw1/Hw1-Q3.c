/*Q3-The housing prices in a particular neighborhood are related to the popularity of the land and the size of the house through the following relationship:
homeValue= ( popularity3 + size2 ) * 10000
For example, if the popularity of the neighborhood is 5 and the size of the house is 2, the minimum value for your house should be 1290000 TL.

Write a C program that gets the values of popularity and size from the user and computes & prints the value of homeValue.

A sample run is as follows:
Enter popularity: 5
Enter size: 2
Home value is: 1290000*/

// Program that calculates the value of a  house in terms of its popularity and size.

#include <stdio.h>
#include <math.h>

int main(void) {
	int popularity, size, homeValue; // Define variables without initializing
	
	printf("Enter the popularity: "); // Prompt 1
	scanf("%d", &popularity); // Enter 1
	
	printf("Enter the size: "); // Prompt 2
	scanf("%d", &size); // Enter 2
	
	homeValue = (pow(popularity, 3) + pow(size, 2)) * 10000; // Calculate the value
	
	printf("The home value is %d", homeValue); // Inform the user
	
	return 0; // Successfully terminate
}

/* PROGRAM STARTED

Enter the popularity: 4
Enter the size: 3
The home value is 730000

PROGRAM ENDED */
