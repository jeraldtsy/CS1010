// CS1010 AY2014/5 Semester 1
// PE1 Ex2: happy.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description:
// Solution
#include <stdio.h>
#include <math.h>

int computeHappyNumbers(int, int);

int main(void) {
	int lower1, upper1, lower2, upper2, number1, number2;

	printf("Enter first range: ");
	scanf("%d %d", &lower1, &upper1);

	printf("Enter second range: ");
	scanf("%d %d", &lower2, &upper2);
	
	number1 = computeHappyNumbers(lower1, upper1);
	number2 = computeHappyNumbers(lower2, upper2);

	printf("The numbers of happy numbers in the two ranges are: %d %d\n", number1, number2);

	if (number1 > number2) {
		printf("There are more happy numbers in the first range.\n");
	}

	else if (number2 > number1) {
		printf("There are more happy numbers in the second range.\n");
	}

	else {
		printf("The numbers of happy numbers in both ranges are the same.\n");
	}

	return 0;
}

int computeHappyNumbers(int lower, int upper) {
	int ans = 0; 
	int num, sum, endNum;

	for (int i = lower; i <= upper; i++) {
		sum = 0;
		num = i;
		endNum = 0; 

		while (endNum == 0) {
			while (num != 0) {
				sum += pow(num % 10, 2);
				num /= 10;
			}

			switch (sum) {
			case 1: ans++;
				endNum = 1; 
				break;
			case 0:
			case 4:
			case 16:
			case 20:
			case 37:
			case 42:
			case 58:
			case 89:
			case 145: endNum = 1;
				break;
			default: num = sum; 
				sum = 0; 
				break;
			}
		}
		
	}

	return ans; 
}