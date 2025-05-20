#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT_FILE_NAME "input.txt"
#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 100

typedef struct { // Data structure of the words
	char *word; // Dynamically allocated string 
	int frequency; // Frequency of the word
} WordFrequency;

struct options_t { // Data structure of the options
	int sort; // Alphabetical and frequency
	int order; // Ascending or descending
	int case_sensitive; // Case sensitivity
} opts_default = {1, 1, 1};

typedef struct options_t Options;

// Function prototypes
void incrementFreq(WordFrequency **array, int *length, char *name, Options opts); // Increments the frequency of existing words.
void appendWord(WordFrequency **array, int *length, char *name, Options opts); // Handles the registry of non-existing words.
int getSortType(void); // Returns 1 for alphabetical, 2 for frequency sort.
int getOrderType(void); // Returns 1 for ascending, 2 for descending order.
int getCaseSensitivity(void); // Sensitive for 2, 1 otherwise.
int askForNumber(void); // Forces the user to enter either 1 or 2.
void printArray(WordFrequency *array, int length, Options opts); // Prints the array with the options.
void getNextLine(FILE *inpf, char* str); // Retrieve the next line from the input file.
void string_tolower(char *str); // Acts like tolower() but for all characters in the string.

// main
int main(void) {
	FILE* inpf = fopen(INPUT_FILE_NAME, "r");
	
	if (inpf) {
		printf("%s", "The file exists.\n\n");
		
		int arrayLength = 0;
		
		Options opts = opts_default;
		opts.sort = getSortType();
		opts.order = getOrderType();
		opts.case_sensitive = getCaseSensitivity();
		
		WordFrequency *wordArray = (WordFrequency *) calloc(0, sizeof(WordFrequency));
		
    if (wordArray == NULL) {
      printf("Memory allocation failed. Exiting the program.\n");
      exit(0);
    }
    
    char line[MAX_LINE_LENGTH] = "0";
		char newLine[MAX_LINE_LENGTH] = "";
		
		getNextLine(inpf, newLine);
		while (strcmp(line, newLine)) {
			strcpy(line, newLine);
    	
    	int firstLetter = -1, lastLetter = -1; // Indices, -1 for the base case
			
    	for (int i = 0; i < strlen(newLine) + 1; i++) {
    		/* If there's an apostrophe, it could be showing
				   the possession, which contributes to the word. */
    		if (newLine[i] == '\'') continue;
    		
    		if (firstLetter != -1 && !(isalpha(newLine[i]) || isdigit(newLine[i]))) lastLetter = i - 1;
    		if (firstLetter == -1 && (isalpha(newLine[i]) || isdigit(newLine[i]))) firstLetter = i;
    		
    		if (firstLetter <= lastLetter && firstLetter != - 1) { // A word is found.
    			int wordLength = lastLetter - firstLetter + 1;
    			char word[wordLength + 1];
    			
    			for (int j = 0; j < wordLength; j++) {
    				word[j] = newLine[firstLetter + j];
					}

					word[wordLength] = '\0'; // Terminate the string.
					incrementFreq(&wordArray, &arrayLength, word, opts);
    			firstLetter = lastLetter = -1;	// Reset to -1 after the new word.
				}
			}
			
			getNextLine(inpf, newLine);
		}
		
		printArray(wordArray, arrayLength, opts);

		// Free the memory.
    for (int i = 0; i < arrayLength; i++) {
        free(wordArray[i].word);
    }
    free(wordArray);
	}
	else printf("%s", "The file does not exist.\n");
	
  fclose(inpf); // Close the file.

	system("pause");
	return 0;
}

// Functions
void incrementFreq(WordFrequency **array, int *length, char *name, Options opts) {
	if (opts.case_sensitive == 1) string_tolower(name);

	for (int i = 0; i < *length; i++) {
		if (strcmp((*array)[i].word, name) == 0) {
			(*array)[i].frequency++;
			return;
		}
	}
	
	appendWord(array, length, name, opts); // No index is found in the for loop.
}

void appendWord(WordFrequency **array, int *length, char *name, Options opts) {
	// Reallocate memory for the new word.
	WordFrequency *res = (WordFrequency *) realloc(*array, sizeof(WordFrequency) * (*(length) + 1));
	
	if (res == NULL) {
		printf("Reallocation failed. Exiting the program.\n");
		exit(0);
	}
	
	*array = res;
	
  (*array)[*length].word = malloc(strlen(name) + 1);
  if (!(*array)[*length].word) {
    printf("Memory allocation for word failed.\n");
    exit(1);
  }
  strcpy((*array)[*length].word, name);
  (*array)[*length].frequency = 1; 	// Initialize the frequency of the new word to 1.
  (*length)++;
}

void getNextLine(FILE *inpf, char *str) {
    if (!fgets(str, MAX_LINE_LENGTH, inpf)) str[0] = '\0'; // Return the immediately-terminated string.
		else str[strlen(str)] = '\0'; // Return the line without the newline character.
}

int askForNumber(void) {
	int a = 0, res = 0;
	
	while (!res || a != 1 && a != 2) {
		printf("%s", "Enter: ");
		res = scanf("%d", &a);

		while (getchar() != '\n'); // Remove unwanted characters from the stream.
	}
	puts("");
	
	return a;
}

int getSortType(void) {
	printf("%s", "Enter either 1 or 2 for the sorting of the array.\n\t1. Alphabetical\n\t2. Frequency\n");
	return askForNumber();
}

int getOrderType(void) {
	printf("%s", "Enter either 1 or 2 for the order of the sorting.\n\t1. Ascending\n\t2. Descending\n");
	return askForNumber();
}

int getCaseSensitivity(void) {
	printf("%s", "Enter either 1 or 2 for the case sensitivity.");
	printf("%s", "\n\t1. Assume every character's lowercase and uppercase are lexicographically equal.");
	printf("%s", "\n\t2. Compare their ASCII codes, regardless of the case.\n");
	return askForNumber();
}

void printArray(WordFrequency *arr, int length, Options opts) {
	opts.order = opts.order == 1 ? 1 : -1; // 1 if ascending, -1 if descending.
	// The line facilitates the code to work with the results of strcmp function.
	
	for (int i = 0; i < length - 1; i++) { // Optimized bubble sort
		int swap = 0;

		for (int j = 0; j < length - i - 1; j++) {
			char cpy1[strlen(arr[j].word)], cpy2[strlen(arr[j + 1].word)];
			strcpy(cpy1, arr[j].word);
			strcpy(cpy2, arr[j + 1].word);

			if (opts.case_sensitive == 1) {
				string_tolower(cpy1);
				string_tolower(cpy2);
			}

			int comp = opts.sort == 1 ? strcmp(cpy1, cpy2) : (arr[j].frequency > arr[j + 1].frequency ? 1 : -1);
			
			if (comp == opts.order) {
				WordFrequency temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				
				swap++;
			}
		}
		
		if (!swap) break; // If there's no swap, the array is sorted.
	}
	
	printf("Array:");

	for (int i = 0; i < length; i++) {
		if (opts.sort == 1) printf("\t\n [%d] = [word = \"%s\" frequency = %d]", i, arr[i].word, arr[i].frequency);
		else printf("\t\n [%d] = [frequency = %d word = \"%s\"]", i, arr[i].frequency, arr[i].word);
	}
	puts("");
}

void string_tolower(char *str) {
	for (int i = 0; i < strlen(str); i++) str[i] = tolower(str[i]);
}