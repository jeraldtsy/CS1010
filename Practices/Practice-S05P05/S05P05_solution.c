#include <stdio.h>
#define MAX_SLICES 20

int maxCherries(int[], int);

int main() {
	int arr[MAX_SLICES]; 
	int size;

	printf("Enter number of slices: ");
	scanf("%d", &size); 

	printf("Enter numbers of cherries: ");
	
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	printf("The maximum number of cherries Alice can get is %d.\n", maxCherries(arr, size)); 


	return 0;
}

int maxCherries(int arr[], int size) {
	int ans = 0; 
	int aliceSlices = 1; 
	int aliceCherries = 0; 
	int bobCherries; 
	int startIndex = 0;
	int totalCherries = 0; 
	int temp;

	for (int i = 0; i < size; i++) {
		totalCherries += arr[i];
	}

	while (aliceSlices != size) {
		for (int i = startIndex; i < size; i++) {
			aliceCherries = 0;

			for (int j = 0; j < aliceSlices; j++) {
				if ((i+j) >= size) {
					aliceCherries += arr[(i + j) % size];
				}
				else {
					aliceCherries += arr[i + j];
				}
			}

			bobCherries = totalCherries - aliceCherries;

			if (aliceCherries > bobCherries) {
				temp = aliceCherries;
				aliceCherries = bobCherries; 
				bobCherries = temp;
			}

			if (aliceCherries > ans) {
				ans = aliceCherries;
			}
		}
		aliceSlices++;
	}

	return ans; 
}