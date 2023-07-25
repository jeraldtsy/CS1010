// CS1010 AY2011/2 Semester 1 
// PE1 Ex2: winners.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:
// Solution
#include <stdio.h>

int checkFactor(int, int);
int checkDigit(int, int);

int main(void)
{
	int divide, digit, num, isFactor, hasDigit;
	int ans = 0;

	printf("Enter factor-digit: ");
	scanf("%d", &divide);
	printf("Enter must-have-digit: ");
	scanf("%d", &digit);
	printf("Enter number of participants: ");
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		isFactor = checkFactor(i, divide);
		hasDigit = checkDigit(i, digit);

		if ((isFactor == 1) && (hasDigit == 1)) {
			ans++;
		}
	}

	printf("Number of winners: %d", ans);
	return 0;
}


int checkFactor(int num, int divide) {

	if ((num % divide) == 0) {
		return 1; 
	}

	return 0; 
}

int checkDigit(int num, int digit) {
	int currDigit; 

	while (num > 0) {
		currDigit = num % 10; 

		if (currDigit == digit) {
			return 1; 
		}

		num /= 10;
	}

	return 0; 
}