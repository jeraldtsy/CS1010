/**********************************************************
Program: presents.c
************************************************************/

// Solution
#include <stdio.h>

int present_on_day(int);
int present_thru_days(int);

// The main program is called with an integer argument
// denoting the "n-th" day on which the number of presents
// will be determined.
int main(void) {
	int n;
	int dayPresent; 
	int totalPresent;

    printf("Please enter the number of days: ");
	scanf("%d", &n);

	printf("You have entered the number of days as: %d\n", n);

	dayPresent = present_on_day(n);
	totalPresent = present_thru_days(n);

	if (n == 1) {
		printf("The number of present received on day 1 is 1.\n");
	}
	else { // Here, n > 1 
		printf("The number of presents received on day %d is %d.\n", n, dayPresent);

		printf("The number of presents received in %d days is %d.\n", n, totalPresent);
	}
	return 0;
}

// This function determines the number of presents to be received 
// on the n-th day.
// Pre-condition: n >= 1
int present_on_day(int n) {
	if (n != 0) {
		return (n + present_on_day(n-1));
	}
	else {
		return 0;
	}
}

// This function determines the number of presents to be received
// throughout n days.
// Pre-condition: n >= 1
int present_thru_days(int n) {
	int ans = 0;
	while (n != 0) {
		ans += present_on_day(n);
		n--;
	}
	return ans;
}