// box.c
// To compute the number of boxes with length, width and height
// in the range [lower,upper] whose surface area is larger than
// volume.
// Solution
#include <stdio.h>

void compute(int, int, int*);

int main(void) {
	int lower, upper;
	int* ans = 0;

	printf("Enter lower and upper limits: ");
	scanf("%d %d", &lower, &upper);

	compute(lower, upper, &ans);

	printf("Answer = %d\n", ans);

	return 0;
}

void compute(int lower, int upper, int* ans) {
	float volume;
	float surfaceArea;

	for (int i = lower; i <= upper; i++) {
		for (int j = i; j <= upper; j++) {
			for (int k = j; k <= upper; k++) {
				volume = i * j * k;
				surfaceArea = (2 * i * j) + (2 * j * k) + (2 * i * k);

				if (surfaceArea >= volume) {
					*ans += 1;
				}
			}
		}
	}
	
}