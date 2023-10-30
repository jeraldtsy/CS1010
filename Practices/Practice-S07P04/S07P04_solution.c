// pair.c
// Solution
#include <stdio.h>
#define MAX_SIZE 10

int findPair(int[], int, int, int*, int*);

int main() {
	int size;
	int sum;
	int arr[MAX_SIZE];
	int isExists;
	int* ans1; 
	int* ans2;

	printf("Please enter the number of elements: ");
	scanf("%d", &size);

	//input the elements into array
	printf("Please enter %d integers: ", size);

	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("Please enter the target sum: ");
	scanf("%d", &sum);

	isExists = findPair(arr, size, sum, &ans1, &ans2);

	if (isExists == 0) {
		printf("No solution!\n");
	}
	else {
		printf("The pair of values are %d and %d", ans1, ans2);
	}
	return 0;
}

int findPair(int arr[], int size, int sum, int* ans1, int* ans2) {
	
	for (int i = 0; i < size; i++) {
		for (int j = (i + 1); j < size; j++) {
			if ((arr[i] + arr[j]) == sum) {
				*ans1 = arr[i];
				*ans2 = arr[j];
				return 1;
			}
		}
	}

	return 0;
}