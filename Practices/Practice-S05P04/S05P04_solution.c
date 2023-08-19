// partition.c
// Solution
#include <stdio.h>

void printArray(int[], int);
void partition(int[], int, int);

int main(void) {
	int size;
	int arr[20];
	int pivot;

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	printf("Enter %d integers: ", size);

	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter pivot: ");
	scanf("%d", &pivot);

	partition(arr, size, pivot);
	printArray(arr, size);

	return 0;
}

void partition(int arr[], int size, int pivot) {
	int temp;
	
	for (int i = 0; i < size; i++) {
		if (arr[i] >= pivot) {
			for (int j = (i + 1); j < size; j++) {
				if (arr[j] < pivot) {
					temp = arr[i]; 
					arr[i] = arr[j];
					arr[j] = temp; 
				}
			}
		}
	}
}


// Print array arr
void printArray(int arr[], int size) {
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}