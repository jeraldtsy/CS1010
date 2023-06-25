// countPrimes.c
// To count the number of primes in the range [1, limit]
// where limit is entered by user.
// Solution
#include <stdio.h>

int is_prime(int);

int main(void) {
	int limit, count;

	printf("Enter limit: ");
	scanf("%d", &limit);
	
	count = is_prime(limit);
	printf("Number of primes (1- %d): %d", limit, count);

	return 0;
}

int is_prime(int num) {
	int ans = 0; 
	int isPrime; 

	for (int i = 2; i <= num; i++) {
		isPrime = 1; 

		for (int j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				isPrime = 0; 
				break;
			}
		}
		if (isPrime == 1) {;
			ans++;
		}
	}	
	
	return ans;
}