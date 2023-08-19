// speed.c
// Solution

#include <stdio.h>
#define MAX_SIZE 100

int scan(int[]);
void print(int[], int);
int slowdown(int[], int[], int, int);
int speedup(int[], int[], int, int);

int main(void) {
	int size;
	int speedChange;
	int sound[MAX_SIZE];
	int result[MAX_SIZE * MAX_SIZE];

	size = scan(sound);

	printf("Enter speed change: ");
	scanf("%d", &speedChange);

	if (speedChange < 0) {
		size = slowdown(sound, result, size, speedChange);
	}
	else {
		size = speedup(sound, result, size, speedChange);
	}

	printf("The sound wave after speed change: \n");
	print(result, size);

	return 0;
}

// To slow down a sound wave and return the size of the 
// resulting sound wave.
// Precond: 
int slowdown(int sound[], int result[], int size, int change) {
	change *= -1;
	int resultSize = 0;
	int flag = 0; 
	for (int i = 0; i < change; i++) {
		for (int j = 0; j < size; j++) {
			result[j + (i * size)] = sound[j];
			resultSize++;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < change; j++) {
			result[(i*change) + j] = sound[i];
		}
	}
	return resultSize;
}

// To speedup a sound wave and return the size of the 
// resulting sound wave.
// Precond: 
int speedup(int sound[], int result[], int size, int change) {
	int resultSize = size/change;
	int element = 0;


	for (int i = 0; i < resultSize; i++) {
		for (int j = 0; j < change; j++) {
			element += sound[j + (i*change)];
		}
		element /= change;
		result[i] = element;
		element = 0;
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
}// speed.c
// Solution

#include <stdio.h>
#define MAX_SIZE 100

int scan(int[]);
void print(int[], int);
int slowdown(int[], int[], int, int);
int speedup(int[], int[], int, int);

int main(void) {
	int size;
	int speedChange;
	int sound[MAX_SIZE];
	int result[MAX_SIZE * MAX_SIZE];

	size = scan(sound);

	printf("Enter speed change: ");
	scanf("%d", &speedChange);

	if (speedChange < 0) {
		size = slowdown(sound, result, size, speedChange);
	}
	else {
		size = speedup(sound, result, size, speedChange);
	}

	printf("The sound wave after speed change: \n");
	print(result, size);

	return 0;
}

// To slow down a sound wave and return the size of the 
// resulting sound wave.
// Precond: 
int slowdown(int sound[], int result[], int size, int change) {
	change *= -1;
	int resultSize = 0;
	int flag = 0; 
	for (int i = 0; i < change; i++) {
		for (int j = 0; j < size; j++) {
			result[j + (i * size)] = sound[j];
			resultSize++;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < change; j++) {
			result[(i*change) + j] = sound[i];
		}
	}
	return resultSize;
}

// To speedup a sound wave and return the size of the 
// resulting sound wave.
// Precond: 
int speedup(int sound[], int result[], int size, int change) {
	int resultSize = size/change;
	int element = 0;


	for (int i = 0; i < resultSize; i++) {
		for (int j = 0; j < change; j++) {
			element += sound[j + (i*change)];
		}
		element /= change;
		result[i] = element;
		element = 0;
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