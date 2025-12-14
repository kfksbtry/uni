#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

extern const char vowels[5];
extern const char consonants[21];

int search(char c, const char array[], int len);
int countVowels(const char *s);
int countConsonants(const char *s);
void reverseString(const char *src, char *dst, int len);

#endif