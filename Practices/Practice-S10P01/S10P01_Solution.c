// Solution
// sum_digits_recursion.c
// This program reads a non-negative integer and calls
// a recursive function to sum up all digits in that integer.
#include <stdio.h>

int sumDigits(int);

int main(void) {
	int num;

	printf("Enter a non-negative integer: ");
	scanf("%d", &num);

	printf("Sum of its digits = %d\n", sumDigits(num));

	return 0;
}

// Return sum of digits in n
// Precond: n >= 0
int sumDigits(int n) {
	int sum = 0; 

	sum += n % 10;

	n /= 10;

	if (n == 0) {
		return sum;
	}
	else {
		return (sum + sumDigits(n));
	}
}