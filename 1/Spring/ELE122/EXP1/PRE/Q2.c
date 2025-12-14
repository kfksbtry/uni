/*
| C Program
| Goal:         Return the GCD of two integers.
| Description:  This program uses the Euclidean algorithm.
                The function is recursive.
| Student info
	Baturay KAFKAS
	2240357068
	Electrical & Electronics Engineering
*/

#include <stdio.h>

int GCD(int, int);

int main(void) {
	int a, b;
	
	printf("Enter two integers: ");
	scanf("%d%d", &a, &b);
	
	int c = GCD(a, b);
	printf("GCD of %d and %d: %d", a, b, c);
	
	return 0;
}

// Remember: a = bq+r
// gcd(a, b) = gcd(b, r)

int GCD(int a, int b) {
	if ((a % b) == 0) return b;
	
	return GCD(b, a % b);
}