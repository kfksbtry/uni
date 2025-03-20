// Only works in Windows.
// Insert this code in Q1.c file.

#include <windows.h>

// startCounter: the square root of the number you want to start the test with.
// endCounter: the square root of the number, the number that will terminate the test.
// num: The number whose square root is to be found.

void test(unsigned long long int counter, unsigned long long int endFor, unsigned long long int num) {
	unsigned long long int c = counter;  // Enter the square root of the number you want to start the test with.
	unsigned long long int e = endFor;  // Enter the square root of the number whose square will terminate the test.

	unsigned long long int index = c * c;	
    unsigned long long int n_endFor = e * e;  // Enter the number whose square root will terminate the test.

    unsigned long long int last = c - 1;
	
    LARGE_INTEGER F;
    LARGE_INTEGER T1, T2;
    double ETime;

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

    LARGE_INTEGER f;
    LARGE_INTEGER t1, t2;
    double eTime;

    QueryPerformanceFrequency(&f);
    
    printf("%s\n", "One-time calculation test start!");
    QueryPerformanceCounter(&t1);
    unsigned long long int a = mySqrt(num);
    QueryPerformanceCounter(&t2);
    printf("Square root: %llu\n", a);
    printf("%s\n", "One-time calculation test end!");

    eTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / f.QuadPart;
    printf("Time elapsed: %f ms.\n\n", eTime);
}
