// CS1010 AY2012/3 Semester 1
// PE1 Ex2: ucard.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:
// Solution

#include <stdio.h>

int isValid(int);
void printBranch(int);

int main(void) {
	int uCardNo;
	int validCard; 

	printf("Enter uCard Number: ");
	scanf("%d", &uCardNo);

	validCard = isValid(uCardNo);
	
	if (validCard == 1) {
		printf("Valid\n");
		printBranch(uCardNo);
	}
	else {
		printf("Invalid\n");
	}

	return 0;
}

int isValid(int num) {
	int sum = 0; 
	int checkDigit = 1; 
	int tempNum; 

	while (num != 0) {

		if (checkDigit % 2 == 1) {
			sum += (num % 10); 
		}
		else {
			tempNum = (num % 10) * 2; 

			if (tempNum >= 10) {
				while (tempNum > 0) {
					sum += (tempNum % 10); 
					tempNum /= 10; 
				}
			}
			else {
				sum += tempNum; 
			}
		}
		checkDigit++; 
		num /= 10; 
	}

	printf("The check number is %d\n", sum);

	if (sum % 7 == 0) {
		return 1; 
	}
	else {
		return 0;
	}
}

void printBranch(int num) {

	while (num >= 100) {
		num /= 100;
	}

	if ((num >= 31) && (num <= 35)) {
		printf("Issued by East branch");
	}
	else if ((num >= 51) && (num <= 55)) {
		printf("Issued by West branch");
	}
	else {
		printf("Issued by Central branch");
	}
}