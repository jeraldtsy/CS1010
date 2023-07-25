// CS1010 AY2015/6 Semester 2 PE1 Ex2
//
// skip.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description:
// Solution

#include <stdio.h>

int skipCount(int, int, int);
int countOddDigits(int);

int main(void) {
	int startPos, endPos, lower, upper;

	// Insert appropriate statements for reading the inputs.
	printf("Enter starting position: ");
	scanf("%d", &startPos);

	printf("Enter lower bound and upper bound: ");
	scanf("%d %d", &lower, &upper);

	endPos = skipCount(startPos, lower, upper);

	printf("The ending position is %d.\n", endPos);

	return 0;
}

int skipCount(int startPos, int lower, int upper) {
	
	int numSkips; 

	for (int i = lower; i <= upper; i++) {
		numSkips = countOddDigits(i);

		if (numSkips != 0) {
			while (numSkips != 0) {
				startPos++;
				if (startPos >= 6) {
					startPos %= 5;
				}
				numSkips--;
			}
		}
		startPos++;	
		if (startPos >= 6) {
			startPos %= 5;
		}
	}

	return startPos;  // stub
}

int countOddDigits(int num) {
	int digits = 0; 
	int currDigit; 

	while (num != 0) {
		currDigit = num % 10; 
		if ((currDigit % 2) != 0) {
			digits++;
		}
		num /= 10;
	}
	return digits;
}