#include <stdio.h>
#include <stdlib.h>
#include "text_utils.h"

int main(void) {
	char buffer[101];
	char rev[101];
	
	printf("%s", "Enter a string: ");
	
	do {
		fgets(buffer, sizeof(buffer), stdin);
	} while (strlen(buffer) < 2);
	
	printf("Vowels: %d\nConsonants: %d\n", countVowels(buffer), countConsonants(buffer));
	
	reverseString(buffer, rev, strlen(buffer));
	printf("Reversed text: %s\n", rev);

	system("pause");
	return 0;
}