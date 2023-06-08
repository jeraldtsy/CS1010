// echo.c

#include <stdio.h>
#define MAX_SIZE 100

int scan(int []);
void print(int [], int);
int echo(int [], int [], int, int, int);

int main(void) {
	printf("Enter number of echoes and decay percentage: ");
	printf("The sound wave with echoes added: \n");

	return 0;
}

// To add echo effects to a sound wave and return the size 
// of the resulting sound wave.
// Precond: 
int echo(int sound[], int result[], int size, int copies, int decay) {
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

