#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
  
	float aRandomNumber;
  
	for (int i = 0; i < 50; i++) {
		aRandomNumber = rand() % 2001;
		printf("Rand modulo 2001 gives %7.2f, ", aRandomNumber);
		aRandomNumber = aRandomNumber / 100;
		printf("we divide by 100 to get %5.2f\n", aRandomNumber);
	}
  
	system("pause");
}