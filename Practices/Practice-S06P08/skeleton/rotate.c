// rotate.c
#include <stdio.h>
#define MAX_SIZE 10

int scan(int [][MAX_SIZE]);
void print(int [][MAX_SIZE], int);
void rotate(int [][MAX_SIZE], int, int);

int main(void) {
	printf("Enter degree of rotation: ");
	printf("The image after rotation: \n");

	return 0;
}

void rotate(int image[][MAX_SIZE], int size, int degree) {
}

// To read in an image
int scan(int image[][MAX_SIZE]) {
	printf("Enter size: ");
	printf("Enter values: \n");
	
	return 0;
}

// To print an image
void print(int image[][MAX_SIZE], int size) {
	int row, col;

	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) 
			printf("%d ", image[row][col]);
		printf("\n");
	}
}
