// NRIC.c
// This program computes NRIC check code.
#include <stdio.h>

char generateCode(int);

int main(void) {    
	int number;
	char code;

	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &number);

	code = generateCode(number);

	printf("Check code is %c\n", code);

	return 0;
}

// This function generates the check code for NRIC num
char generateCode(int num) {
	char code;

	code = 'A';

	return code;
}

