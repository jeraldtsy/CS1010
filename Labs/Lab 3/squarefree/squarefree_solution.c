/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex2
 * square_free.c
 * <Type your name here>
 * <Type your discussion group here>
 * <Fill in a description of this program>
 * Solution
 */

int computeNotSquareFree(int, int);

#include <stdio.h>

int main(void) {
	int lower1, upper1, lower2, upper2, set1, set2;

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);

	set1 = ((upper1 + 1 - lower1) - computeNotSquareFree(lower1, upper1));
	set2 = ((upper2 + 1 - lower2) - computeNotSquareFree(lower2, upper2));

	if (set1 > set2) {
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower1, upper1, set1);
	}
	else if (set2 > set1) {
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower2, upper2, set2);
	}
	else {
		printf("Both ranges have the same number of square-free numbers: %d\n", set1);
	}

	return 0;
}

// Write at least another function (of your own choice) to compute
// some results. You may add other functions you deem necessary.
int computeNotSquareFree(int lower, int upper) {
	int ans = 0; 
	int num; 
	int divider; 
	int flag; 

	for (int i = lower; i <= upper; i++) {
		num = i; 
		divider = 2;
		flag = 0; 

		while (num != 1) {
			if (num % divider == 0) {
				num /= divider;
			}
			if (num % divider == 0) {
				flag = 1;
				break;
			}
			divider++;
	}

		if (flag == 1) {
			ans++;
		}
	}
	return ans; 
}