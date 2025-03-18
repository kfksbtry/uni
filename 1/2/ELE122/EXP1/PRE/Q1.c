/*
| C Program
| Goal:         Return the integer part of the square root of an integer.
| Description:  This program will ask the user to input an integer, and the user will see the integer part of the square root they input.
                The input will be processed by a function. A function attempts to find the square root of the given integer with double-type numbers.
                It may produce incorrect results above 2^63.
                Due to the limitation of double-type numbers, the function will halt the process of finding the subsequent digits.
                Then the function will only return the integer part. The integer will be output in the main function.
| Student info
	Baturay KAFKAS
	2240357068
	Electrical & Electronics Engineering
*/

#define SIGNIFICANT_DIGITS 15 // The number of digits to be calculated due to limitations.

#include <stdio.h>

unsigned long long int mySqrt(unsigned long long int);

int main(void) {
	unsigned long long int num, sqrt_num;

	printf("%s", "Please enter an integer: ");
	scanf("%llu", &num);

	sqrt_num = mySqrt(num);
	printf("The integer part of the square root of the number: %llu", sqrt_num);
	
	return 0;
}

unsigned long long int mySqrt(unsigned long long int num) {
	if (num == 0) { // Special case
		return 0;
	}

	int location = 1;           // Indicate which digit is being checked, ones: 1, tens: 2, tenths: -1, hundredths, -2, dot: 0 ...
	int leftToDot = 1;          // The number of digits left to the dot.
	
	double compareNum = 1.0;    // The amount we will increment or decrement for the value of _sqrt
	double _sqrt = 0.0;         // The number we want to find, in double.
	
	while (location >= (leftToDot - SIGNIFICANT_DIGITS + 1)) {
		if (location == 0) { // If location = 0, it is the dot.
			location--;
			
			continue;
		}
				
		for (int i = 0; i <= 9; i++) {
			_sqrt += compareNum;

			if (_sqrt * _sqrt > num) {
				_sqrt -= compareNum;
				location--;
				compareNum /= 10.0;

				break;
			} else if (_sqrt * _sqrt == num) {
				return _sqrt;
			}
			
			if (i == 9) { // Once the number of digits left the dot found in the root, the value of location will always decrement.
				compareNum *= 10.0;
				_sqrt = compareNum;
				location++;
				leftToDot++;
			}
		}
	}	
	
	return _sqrt;
}
