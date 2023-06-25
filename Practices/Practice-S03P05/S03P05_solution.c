// countNumbers.c
// To count the number of integers in the range [limit1, limit2]
// which are not divisible by divisor1 and divisor2
// Solution
#include <stdio.h>

int count_numbers(int, int, int, int);

int main(void) {
	int divisor1, divisor2, limit1, limit2, isValid = 0, ans;

	while (isValid == 0) {

		printf("Enter 2 divisors: ");
		scanf("%d %d", &divisor1, &divisor2);

		if ((divisor1 <= 0) || (divisor2 <= 0) || (divisor1 == divisor2)) {
			isValid = 0;
		}
		else {
			isValid = 1; 
		}

	}

	isValid = 0;

	while (isValid == 0) {
		printf("Enter lower and upper limits: ");
		scanf("%d %d", &limit1, &limit2);

		if ((limit1 <= 0) || (limit2 <= 0) || (limit2 <= limit1)) {
			isValid = 0;
		}
		else {
			isValid = 1;
		}

	}
	
	ans = count_numbers(divisor1, divisor2, limit1, limit2);

	printf("Answer = %d\n", ans);

	return 0;
}

int count_numbers(int divisor1, int divisor2, int limit1, int limit2) {
	int ans = 0;
	int isDivisible;

	for (int i = limit1; i <= limit2; i++) {
		isDivisible = 0;

		if (((i % divisor1) == 0) || ((i % divisor2) == 0)) {
			isDivisible = 1;
		}

		if (isDivisible == 0) {
			ans++;
		}
	}

	return ans;
}