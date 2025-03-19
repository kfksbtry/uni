// Only works in Windows.

#include <windows.h>

// startCounter: the square root of the number you want to start the test with.
// endCounter: the square root of the number, number that will terminate the test.
// num: The number whose square root is to be found.

void test(unsigned long long int startCounter, unsigned long long int endCounter, unsigned long long int num) {
	unsigned long long int c = startCounter;
	unsigned long long int e = endCounter;

	unsigned long long int index = c * c;	
	unsigned long long int n_endFor = e * e;

	unsigned long long int last = c - 1;

	printf("%s\n", "Range test start!");
	
	for (unsigned long long int i = index; i < n_endFor; i++) {
		unsigned long long int temp = mySqrt(i);
		
		if (temp - last > 1) { // Check whether the consecutive sqrts have difference no more than 1.
			printf("Error catch for the number: %d, last: %d\n", i, last);
			// If prints, there's something wrong with the algorithm.
		} else if (temp - last == 1) { // Case: temp is a perfect square.
			if (c * c != i)  {
				printf("Error! Index: %llu Counter: %llu\n", i, c); // Check whether the counter squared gives i.
			}
			
			c++;
		}
		
		last = temp;
	}

	printf("%s\n\n", "Range test end!");

    LARGE_INTEGER f;
    LARGE_INTEGER t1, t2;
    double eTime;
	unsigned long long int n = num;

    QueryPerformanceFrequency(&f);
    
    printf("%s\n", "One-time calculation test start!");
    QueryPerformanceCounter(&t1);
	unsigned long long int a = mySqrt(n);
    QueryPerformanceCounter(&t2);
    printf("Square root: %llu\n", a);
    printf("%s\n", "One-time calculation test end!");

    eTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / f.QuadPart;
    printf("Time elapsed: %f ms.\n\n", eTime);
}