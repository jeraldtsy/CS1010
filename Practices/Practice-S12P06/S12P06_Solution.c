// Solution
#include <stdio.h>
#define MAX_PIXELS 20
#define MIN_VALUE 256
#define MAX_INPUTS 20

int main(void) {
	int n, constA, constB, constC, constD;
	int ans = 0;
	int currSubset, value, minR, minG, minB;
	int arrR[MAX_INPUTS];
	int arrG[MAX_INPUTS];
	int arrB[MAX_INPUTS];

	scanf("%d %d %d %d %d", &n, &constA, &constB, &constC, &constD);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arrR[i], &arrG[i], &arrB[i]);

	}

	for (int i = 0; i < n; i++) {
		minR = MIN_VALUE;
		minG = MIN_VALUE;
		minB = MIN_VALUE;

		for (int j = i; j < n; j++) {
			if (minG > arrG[j]) {
				minG = arrG[j];
			}
			if (minR > arrR[j]) {
				minR = arrR[j];
			}
			if (minB > arrB[j]) {
				minB = arrB[j];
			}
		}
		
		
		currSubset = 0;

		for (int j = i; j < n; j++) {
			value = constA * (arrR[j] - minR) + constB * (arrG[j] - minG) + constC * (arrB[j] - minB);
			
			if (value <= constD) {
				currSubset++;
			}
		}

		if (currSubset > ans) {
			ans = currSubset;
		}
	}

	printf("%d\n", ans);

	return 0;
}