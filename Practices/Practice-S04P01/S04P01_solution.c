// CS1010 AY2011/2 Semester 1 
// PE1 Ex1: century.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:
// Solution
#include <stdio.h>

int printCentury (int);
void printOrdinal(int, int); 

int main(void)
{
	int year; // user's input
	int century; 

	printf("Enter year: ");
	scanf("%d", &year);

	century = printCentury(year);
	printOrdinal(year, century);

	return 0;
}

int printCentury(int year) {
	int century; 

	century = (year / 100) + 1; 

	return century;
}

void printOrdinal(int year, int century) {
	int isPrinted = 0; 

	if ((century % 10) == 1) {
		if ((century % 100) != 11) {
			printf("The year %d falls in the %dst century.", year, century);
			isPrinted = 1; 
		}
	}

	else if ((century % 10) == 2) {
		if ((century % 100) != 12) {
			printf("The year %d falls in the %dnd century.", year, century);
			isPrinted = 1; 
		}
	}

	else if ((century % 10) == 3) {
		if ((century % 100) != 13) {
			printf("The year %d falls in the %drd century.", year, century);
			isPrinted = 1; 
		}
	}

	if (isPrinted == 0) {
		printf("The year %d falls in the %dth century.", year, century);
	}
}