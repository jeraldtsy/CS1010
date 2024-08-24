// largest_pair.c
// Read a positive integer and determine the largest digit pair
// in the integer.
#include <stdio.h>

int largest_digit_pair(int, int);

int main(void) {
	int num;

	printf("Enter positive integer: ");
	scanf("%d", &num);

	printf("Largest pair of digits in %d is %d\n", num, largest_digit_pair(num, 0));
	return 0;
}

// Find the largest digit pair in n
// Precond: n > 0
int largest_digit_pair(int n, int largest) {
	int ans; 

	ans = n % 100; 
	n /= 100;

	if (ans > largest) {
			largest = ans;
	}
	
	if (n != 0) {
		return largest_digit_pair(n, largest);  
	}
	else {
		return largest;
	}
}