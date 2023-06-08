// partition.c
#include <stdio.h>

void printArray(int [], int);

int main(void) {
	int size;

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	printf("Enter %d integers: ", size);

	printf("Enter pivot: ");


	return 0;
}

// Print array arr
void printArray(int arr[], int size) {
	int i;

	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

