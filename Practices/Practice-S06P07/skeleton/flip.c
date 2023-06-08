// flip.c

#include <stdio.h>
#define MAX_SIZE 10

int scan(int [][MAX_SIZE]);
void print(int [][MAX_SIZE], int);
void flipH(int [][MAX_SIZE], int);
void flipD(int [][MAX_SIZE], int);

int main(void) {
	printf("Enter direction: ");
	printf("The image after rotation: \n");
	
	// Hint: To read in a letter using scanf,
	// you may want to use " %c" to skip 
	// whitespace characters such as '\n'.
	
	return 0;
}

// To flip an image horizontally
void flipH(int image[][MAX_SIZE], int size) {
}

// To flip an image diagonally
void flipD(int image[][MAX_SIZE], int size) {
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

