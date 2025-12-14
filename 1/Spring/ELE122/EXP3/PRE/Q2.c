/*
| C Program
| Last updated:   03/05/2025 17:16 +3

| Question:       Sort integers.
| Description:    This program should be run on C99 mode or later.

| Author info
	Baturay KAFKAS
	2240357068
	Electrical & Electronics Engineering
*/

#include <stdio.h>

void sortIntegers(int *nums, int len);

int main(void) {
	int num;
	
	printf("Enter the number of integers to be sorted: ");
	scanf("%d", &num);
	
	int array[num];
	
	printf("Enter the list of integers.\n");
	
	for (int i = 0; i < num; i++) {
		scanf("%d", array + i);
	}
	
	sortIntegers(array, num);
	
	printf("\nThe result:\n");
	
	for (int i = 0; i < num; i++) {
		printf("array[%d] = %d\n", i, *(array + i));
	}
		
	return 0;
}

void sortIntegers(int *nums, int len) {
	for (int i = 0; i < len - 1; i++) {
		int swap = 0;

		for (int j = 0; j < len - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
				
				swap++;
			}
		}
		
		if (!swap) break;
	}
}