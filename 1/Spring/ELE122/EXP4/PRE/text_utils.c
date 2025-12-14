#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
const char consonants[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k',
    'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

int search(char c, const char array[], int len) {
	int found = 0;
	
	for (int i = 0; i < len; i++) {
		if (array[i] == c) {
			found++;
			break;
		}
	}
	
	return found;
}

int countVowels(const char *s) {
	int count = 0;
	
	for (int i = 0; i < strlen(s); i++) {
		if (search(tolower(s[i]), vowels, 5)) count++;
	}
	
	return count;
}

int countConsonants(const char *s) {
	int count = 0;
	
	for (int i = 0; i < strlen(s); i++) {
		if (search(tolower(s[i]), consonants, 21)) count++;
	}
	
	return count;
}

void reverseString(const char *src, char *dst, int len) {
	while (!isalpha(src[len - 1]) && len > 0) {
		len--;
	};
	
	if (len > 0) {
		*dst = src[len - 1];
		reverseString(src, (dst + 1), len - 1);
	} else *dst = '\0';
}