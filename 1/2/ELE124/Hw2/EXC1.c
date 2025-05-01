#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float aRandomNumber;
	
    for (int i = 0; i < 50; i++) {
        aRandomNumber = rand() % 2000;
        printf("Rand modulo 2000 gives %.2f\n", aRandomNumber);
        aRandomNumber = aRandomNumber / 100;
        printf("We divide by 100 to get %.2f\n\n", aRandomNumber);
    }
    
    system("pause");
}