/*
| C Program
| Last updated:   03/05/2025 17:47 +3

| Question:       Check whether a string is a palindrome or not.
| Goal:           Remove all the non-alphanumeric characters in the string.

| Author info
	Baturay KAFKAS
	2240357068
	Electrical & Electronics Engineering
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int isPalindrome(char str[]);

int main(void) {
	char inpstr[MAX_LEN];

	printf("%s", "Please enter any string: ");
	fgets(inpstr, sizeof(inpstr), stdin);

	printf("The string %s a palindrome.", isPalindrome(inpstr) ? "is" : "is not");

	return 0;
}

int isPalindrome(char str[]) {
	int state = 1;
	
	for(int i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
		
	for (int i = strlen(str) - 1; i > 0; i--) {
		if (!isalnum(str[i])) {
			for (int j = 0; str[j] != '\0'; j++) {
				str[i + j] = str[i + j + 1];
			}
		}
	}
	
	for (int i = 0; i < strlen(str) / 2; i++) {
		if (str[i] != str[strlen(str) - i - 1]) {
			state = 0;
			break;
		}
	}

	return state;
}