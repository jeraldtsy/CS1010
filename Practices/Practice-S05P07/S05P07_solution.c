// echo.c

#include <stdio.h>
#define MAX_SIZE 100

int scan(int[]);
void print(int[], int);
int echo(int[], int[], int, int, int);

int main(void) {
	int copies;
	int decay;
	int size;
	int arr[MAX_SIZE];
	int result[MAX_SIZE * MAX_SIZE];

	size = scan(arr);

	printf("Enter number of echoes and decay percentage: ");
	scanf("%d %d", &copies, &decay);

	size = echo(arr, result, size, copies, decay);

	printf("The sound wave with echoes added: \n");
	print(result, size);

	return 0;
}

// To add echo effects to a sound wave and return the size 
// of the resulting sound wave.
// Precond: 
int echo(int sound[], int result[], int size, int copies, int decay) {
	float decayValue;
	int resultSize = 0;

	for (int i = 0; i <= copies; i++) {
		for (int j = 0; j < size; j++) {
			result[j + (i * size)] = sound[j];
			resultSize++;
		}
	}
	for (int i = 1; i <= copies; i++) {
		for (int j = 0; j < size; j++) {
			decayValue = (decay / 100.0) * (result[j + ((i - 1) * size)]);
			result[j + (i * size)] = result[j + (i - 1) * size] - decayValue;
		}
	}

	return resultSize;
}

// To read in a sound wave
int scan(int sound[]) {
	int size;

	printf("Enter size: ");
	scanf("%d", &size);

	printf("Enter values: \n");
	for (int i = 0; i < size; i++) {
		scanf("%d", &sound[i]);
	}

	return size;
}

// To print a sound wave
void print(int sound[], int size) {
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", sound[i]);
	printf("\n");
}