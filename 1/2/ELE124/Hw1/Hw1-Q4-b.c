/*Q4-Now solve the same problem using functions. Use the following prototypes:
b)	void computeHomeValue (void) 
Notice that for part b, all printf/scanf should take place within the function.*/

#include <stdio.h>
#include <math.h>

void computeHomeValue(void);

int main(void) {
	computeHomeValue();
	return 0; // Successfully terminate
}

void computeHomeValue(void) {
	int popularity, size, homeValue; // Define variables without initializing
	
	printf("Enter the popularity: "); // Prompt 1
	scanf("%d", &popularity); // Enter 1

	printf("Enter the size: "); // Prompt 2
	scanf("%d", &size); // Enter 2
	
	homeValue = (pow(popularity, 3) + pow(size, 2)) * 10000; // Calculate the value

	printf("The home value is %d", homeValue); // Inform the user
}

/* PROGRAM STARTED

Enter the popularity: 4
Enter the size: 4
The home value is 800000

PROGRAM ENDED */