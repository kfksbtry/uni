/*Q4-Now solve the same problem using functions. Use the following prototypes:
a)	int computeHomeValue (int popularity, int size)*/

#include <stdio.h>

int computeHomeValue(int popularity, int size); // Function to compute the value of the home.

int main(void) {
	int popularity, size; // Declare variables without initializing
	
	printf("Enter the popularity: "); // Prompt 1
	scanf("%d", &popularity); // Enter 1
	
	printf("Enter the size: "); // Prompt 2
	scanf("%d", &size); // Enter 2
		
	printf("The home value is %d", computeHomeValue(popularity, size)); // Inform the user
	
	return 0; // Successfully terminate
}

int computeHomeValue(int popularity, int size) {
	return (popularity * popularity * popularity + size * size) * 10000; // Calculate the value
}

/* PROGRAM STARTED

Enter the popularity: 6
Enter the size: 2
The home value is 2200000

PROGRAM ENDED */