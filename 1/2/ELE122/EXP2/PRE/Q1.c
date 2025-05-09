/*
| C Program
| Last updated:   14/04/2025 18:22 +3

| Question:
            Write a C program that asks the user to enter a number n between 1 and 20. The program 
            will then print a number pattern in the form of a right-angled triangle using a for or while 
            loop. 
            If n is even, the pattern should be printed with ascending numbers starting from 1. 
            If n is odd, the pattern should be printed with descending numbers starting from n. 

| Author info
	Baturay KAFKAS
	2240357068
	Electrical & Electronics Engineering
*/

#include <stdio.h>

int main(void) {
	short num;
	
	printf("Enter an integer between 1 and 20, including both: ");
	scanf("%d", &num);
	
	if (num >= 1 && num <= 20) {
		for (short i = 1; i <= num; i++) {
			printf("\n");

			for (short j = 1; j <= i; j++) printf("%d ", num % 2 == 0 ? j : num - j + 1);
		}
	}
	else printf("The number's not in the interval.");

    return 0;
}