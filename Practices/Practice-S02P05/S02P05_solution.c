// AscendingDigits.c
// This program reads 3 positive integers and outputs "Yes" if
// the hundreds digits are in ascending order, or "No" otherwise.
// Solution
#include <stdio.h>

int preProcessing(int);
int isAscending(int, int, int);

int main(void) {
	int num1, num2, num3, flag; 
	
	printf("Enter 3 positive integers:");
	scanf("%d %d %d", &num1, &num2, &num3);
	printf("The integers are %d, %d and %d\n", num1, num2, num3);

	num1 = preProcessing(num1);
	num2 = preProcessing(num2);
	num3 = preProcessing(num3);

	flag = isAscending(num1, num2, num3);

	if (flag == 1) {
		printf("Yes");
	}
	else {
		printf("No");
	}

	return 0;
}

// This function returns 1 if the digits at the hundredth position
// of the 3 parameters are in ascending order, or 0 otherwise.
int isAscending(int num1, int num2, int num3) {
	if ((num1 < num2) && (num2 < num3)) {
		return true; 
	}
	
	return false; 
}

// This function preprocesses the user's input and returns the digit of the hundredth position
int preProcessing(int num) {
	int ans; 

	num /= 100; 
	ans = num % 10;
	
	return ans;
}