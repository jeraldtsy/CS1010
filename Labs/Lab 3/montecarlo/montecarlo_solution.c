/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex4
 * montecarlo.c
 * <Type your name here>
 * <Type your discussion group here>
 * <Fill in a description of this program>
 * Solution
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 // Given function prototype must not be changed
int throwDarts(int);

int main(void) {
	int darts_total,   // number of darts to be thrown
		darts_inside;  // number of darts inside quadrant
	double ans; 

	srand(time(NULL));

	printf("How many darts? ");
	scanf("%d", &darts_total);

	darts_inside = throwDarts(darts_total);
	ans = (4.0000 * darts_inside) / darts_total; 

	printf("Darts landed inside unit circle's quadrant = %d\n", darts_inside);
	printf("Approximated pi = %.4f", ans);

	return 0;
}

int throwDarts(int totalDarts) {
	int inCircle = 0; 
	double x, y; 

	for (int i = 1; i < totalDarts; i++) {
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;

		if (x * x + y * y <= 1)
			inCircle++;
	}
	return inCircle;
}