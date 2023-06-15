// NRIC.c
// This program computes NRIC check code.
// Solution
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
	int ans = 0; 
	
	for (int i = 0; i < 7; i++) {
		switch (i) {
		case 0: ans = (num % 10) * 2; 
			num /= 10; 
			break;
		case 1: ans += (num % 10) * 3;
			num /= 10;
			break;
		case 2: ans += (num % 10) * 4; 
			num /= 10;
			break; 
		case 3: ans += (num % 10) * 5; 
			num /= 10;
			break;
		case 4: ans += (num % 10) * 6; 
			num /= 10;
			break;
		case 5: ans += (num % 10) * 7;
			num /= 10;
			break;
		case 6: ans += (num % 10) * 2; 
			break; 
		}
	}
	
	ans %= 11; 
	ans = 11 - ans; 

	switch (ans) {
	case 1: code = 'A';
		break;
	case 2: code = 'B';
		break;
	case 3: code = 'C';
		break;
	case 4: code = 'D';
		break;
	case 5: code = 'E';
		break;
	case 6: code = 'F';
		break;
	case 7: code = 'G';
		break;
	case 8: code = 'H';
		break;
	case 9: code = 'I';
		break;
	case 10: code = 'Z';
		break;
	case 11: code = 'J';
	}

	return code;
}