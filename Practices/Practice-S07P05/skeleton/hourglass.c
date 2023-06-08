/* hourglass.c
 * This program reads the durations of 2 hourglasses and a duration to measure,
 * to find the number of times to flip the hourglasses so that the total
 * number of flips is minimum.
 */

#include <stdio.h>

// Given function prototype must not be changed
int compute_flips(int, int, int, int *, int *);

int main (void) {
	int hg1, hg2;        // durations of hourglasses; assume hg1 < hg2
	int time;            // duration to measure; assume hg2 < time
	int flips1, flips2;  // number of flips needed for hourglasses

	printf("Enter 3 inputs: ");
	scanf("%d %d %d", &hg1, &hg2, &time);


	return 0;
}

