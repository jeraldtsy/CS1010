/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex3
 * bisection.c
 * <Type your name here>
 * <Type your discussion group here>
 * <Fill in a description of this program>
 * Solution
 */

#include <stdio.h>
#include <math.h>

 // Given function prototype must not be changed
double polynomial(double, int, int, int, int);

int main(void) {
	int c3, c2, c1, c0, iteration = 0;      // coefficients of polynomial
	double a, b, pA, pB, previousA, previousB;    // function values at endpoints
	double m = 0, pM = 0;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);
	
	while (1) {	
		pA = polynomial(a, c3, c2, c1, c0);
		pB = polynomial(b, c3, c2, c1, c0);
		m = (a + b) / 2.0;

		pM = polynomial(m, c3, c2, c1, c0);
		iteration++;

		if (pM > 0) {
			previousB = b; 
			b = m;
			printf("#%d: a = %lf; b = %lf; m = %lf; p(a) = %lf; p(b) = %lf; p(m) = %lf\n", iteration, a, previousB, m, pA, pB, pM);

			if (fabs(b - previousB) < 0.0001) {
				pB = polynomial(b, c3, c2, c1, c0);
				m = (a + b) / 2.0;
				pM = polynomial(m, c3, c2, c1, c0);
				break;
			}
		}
		else {
			previousA = a; 
			a = m;
			printf("#%d: a = %lf; b = %lf; m = %lf; p(a) = %lf; p(b) = %lf; p(m) = %lf\n", iteration, previousA, b, m, pA, pB, pM);

			if (fabs(a - previousA) < 0.0001) {
				pA = polynomial(a, c3, c2, c1, c0);
				m = (a + b) / 2.0;
				pM = polynomial(m, c3, c2, c1, c0);
				break;
			}
		}
	}

	printf("#%d: a = %lf; b = %lf; m = %lf; p(a) = %lf; p(b) = %lf; p(m) = %lf\n", iteration + 1, a, b, m, pA, pB, pM);
	printf("root = %lf\n", m);
	printf("p(root) = %lf\n", pM);

	return 0;
}

double polynomial(double endpoint, int c3, int c2, int c1, int c0) {
	double ans; 

	ans = c3* pow(endpoint, 3) + c2 * pow(endpoint, 2) + c1 * endpoint + c0;

	return ans;
}