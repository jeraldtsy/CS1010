/**********************************************************
Program: presents.c
************************************************************/

#include <stdio.h>

??? present_on_day(???);
??? present_thru_days(???);

// The main program is called with an integer argument
// denoting the "n-th" day on which the number of presents
// will be determined.
int main(void) {
	int n;

    printf("Please enter the number of days: ");
	scanf("%d", &n);

	printf("You have entered the number of days as: %d\n", n);

	if (n == 1) {
		printf("The number of present received on day 1 is %d.\n", ???);

		printf("The number of present received in 1 day is %d.\n", ???);
	}
	else { // Here, n > 1 
		printf("The number of presents received on day %d is %d.\n", n, ???);

		printf("The number of presents received in %d days is %d.\n", n, ???);
	}
	return 0;
}

// This function determines the number of presents to be received 
// on the n-th day.
// Pre-condition: n >= 1
??? present_on_day(???) {

}

// This function determines the number of presents to be received
// throughout n days.
// Pre-condition: n >= 1
??? present_thru_days(???) {

}

