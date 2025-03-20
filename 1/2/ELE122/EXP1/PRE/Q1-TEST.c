// Only works in Windows.
// Insert this code in Q1.c file.

#include <stdio.h>
#include <windows.h>

// startCounter: the square root of the number you want to start the test with.
// endCounter: the square root of the number, the number that will terminate the test.
// num: The number whose square root is to be found.

void test(unsigned long long int startCounter, unsigned long long int endCounter, unsigned long long int num) {
	unsigned long long int c = startCounter, e = endCounter;
	unsigned long long int index = c * c, n_endFor = e * e;
    unsigned long long int last = c - 1;
	
    LARGE_INTEGER f, F;
    LARGE_INTEGER t1, t2, T1, T2;
	double eTime, ETime;

    QueryPerformanceFrequency(&F);
    printf("Range test start! First number: %llu\n", index);

    QueryPerformanceCounter(&T1);
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
    QueryPerformanceCounter(&T2);

    ETime = (T2.QuadPart - T1.QuadPart) * 1000.0 / F.QuadPart;
    printf("Range test end! Last number: %llu\n", n_endFor);
    printf("Time elapsed: %f ms.\n\n", ETime);

    QueryPerformanceFrequency(&f);
    printf("%s\n", "One-time calculation test start!");

    QueryPerformanceCounter(&t1);
    unsigned long long int a = mySqrt(num);
    QueryPerformanceCounter(&t2);

    printf("%s\n", "One-time calculation test end!");
	printf("Square root: %llu\n", a);

	eTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / f.QuadPart;
    printf("Time elapsed: %f ms.\n\n", eTime);
}