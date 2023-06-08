// speed.c

#include <stdio.h>
#define MAX_SIZE 100

int scan(int []);
void print(int [], int);
int slowdown(int [], int [], int, int);
int speedup(int [], int [], int, int);

int main(void) {
	printf("Enter speed change: ");
	printf("The sound wave after speed change: \n");

	return 0;
}

// To slow down a sound wave and return the size of the 
// resulting sound wave.
// Precond: 
int slowdown(int sound[], int result[], int size, int change) {
	return 0;
}

// To speedup a sound wave and return the size of the 
// resulting sound wave.
// Precond: 
int speedup(int sound[], int result[], int size, int change) {
	return 0;
}

// To read in a sound wave
int scan(int sound[]) {
	printf("Enter size: ");
	printf("Enter values: \n");

	return 0;
}

// To print a sound wave
void print(int sound[], int size) {
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", sound[i]);
	printf("\n");
}

