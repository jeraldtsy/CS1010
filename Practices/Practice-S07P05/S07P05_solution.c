/* hourglass.c
 * This program reads the durations of 2 hourglasses and a duration to measure,
 * to find the number of times to flip the hourglasses so that the total
 * number of flips is minimum.
 */

#include <stdio.h>
#include <limits.h>

 // Given function prototype must not be changed
int compute_flips(int, int, int, int*, int*);

int main(void) {
	int hg1, hg2;        // durations of hourglasses; assume hg1 < hg2
	int time;            // duration to measure; assume hg2 < time
	int* flips1;
	int* flips2;  // number of flips needed for hourglasses
	int isPossible;

	printf("Enter 3 inputs: ");
	scanf("%d %d %d", &hg1, &hg2, &time);

	isPossible = compute_flips(hg1, hg2, time, &flips1, &flips2);

	if (isPossible == 1) {
		printf("Possible!\n");
		printf("%d flip(s) for %d-minute hourglass and %d flip(s) for %d-minute hourglass.\n", flips1, hg1, flips2, hg2);
	}
	else {
		printf("Impossible!\n");
	}


	return 0;
}

int compute_flips(int hg1, int hg2, int time, int* flips1, int* flips2) {
	int tempFlips = INT_MAX;
	int isPossible = 0;
	int diff; 
	int tempFlip1;
	int tempFlip2;

	tempFlip2 = time / hg2;
		
	while (tempFlip2!= -1) {
		diff = time - (hg2 * tempFlip2);

		if (diff % hg1 == 0) {
			tempFlip1 = diff / hg1;

			if ((tempFlip1 + tempFlip2) < tempFlips) {
				tempFlips = *flips1 + tempFlip2;
				*flips1 = tempFlip1;
				*flips2 = tempFlip2;
				isPossible = 1;
			}
		}
		tempFlip2--;
	}

	return isPossible;
}