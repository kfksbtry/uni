#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIGNAL_SIZE 100
#define MIN_NUM 0
#define MAX_NUM 100

/* Signal processing */
void generateSignal(int signal[]);
void cleanSignal(int signal[]);

/* Subsidiary functions */
int getMin(int signal[]);
int getMax(int signal[]);
float getAverage(int signal[]);

/* Start */
int main(void) {
	srand(time(NULL));
	int signal[SIGNAL_SIZE] = {0};
	
	
	generateSignal(signal);

	printf("%s", "Original signal\n");
	for (int i = 0; i < SIGNAL_SIZE; i++) {
		printf("signal[%d] = %d\n", i, signal[i]);
	}
	puts("");


	cleanSignal(signal);
	
	printf("%s", "Cleaned signal\n");
	for (int i = 0; i < SIGNAL_SIZE; i++) {
		printf("signal[%d] = %d\n", i, signal[i]);
	}
	puts("");
	
	
	printf("Max: %d, Min: %d, Average: %f\n\n", getMax(signal), getMin(signal), getAverage(signal));

	system("pause");
	return 0;
}

/* Functions */
void generateSignal(int signal[]) {
	int increment = 0;
	
	/* Assign -1's randomly except the endpoints */
	for(int increment = 0; increment < 10; increment++) {
		int randomNum = increment * 10 + rand() % 8 + 1;
		signal[randomNum] = -1;
	}
	
	/* Assign other numbers */
	for (int i = 0; i < SIGNAL_SIZE; i++) {
		if (signal[i] != -1) signal[i] = rand() % 101;
	}
}

void cleanSignal(int signal[]) {
	for (int i = 0; i < SIGNAL_SIZE; i++) {
		if (signal[i] == -1) {
			signal[i] = (signal[i - 1] + signal[i + 1]) / 2;
		}
	}
}

int getMin(int signal[]) {
	int min = MAX_NUM;
	
	for (int i = 0; i < SIGNAL_SIZE; i++) {
		if (signal[i] < min) min = signal[i];
	}
	
	return min;
}

int getMax(int signal[]) {
	int max = MIN_NUM;
	
	for (int i = 0; i < SIGNAL_SIZE; i++) {
		if (signal[i] > max) max = signal[i];
	}
	
	return max;
}

float getAverage(int signal[]) {
	int sum = 0;
	
	for (int i = 0; i < SIGNAL_SIZE; i++) sum += signal[i];
	
	return (float) sum / SIGNAL_SIZE;
}