// primeTest.c
// To check if a number is prime.
// Solution
#include <stdio.h>

int is_prime(int);

int main(void) {
	int value;

	printf("Enter a positive integer: ");
	scanf("%d", &value);

	if (is_prime(value))
		printf("%d is a prime.\n", value);
	else
		printf("%d is not a prime.\n", value);

	return 0;
}

// Write a description for this function,
// and fill in the precondition below.
// Precond: check if a given number is prime
// Return : int = 1(True) int = 0 (False)

int is_prime(int n) {

	if (n == 1) {
		return 0; 
	}
	else {
		for (int i = 2; i < (n / 2); i++) {
			if (n % i == 0) {
				return 0;
			}
		}
	}
	return 1; 
}
