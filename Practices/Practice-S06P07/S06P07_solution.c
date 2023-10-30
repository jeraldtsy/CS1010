#include <stdio.h>
#define MAX_SIZE 10

int scan(int[][MAX_SIZE]);
void print(int[][MAX_SIZE], int);
void flipH(int[][MAX_SIZE], int);
void flipD(int[][MAX_SIZE], int);

int main(void) {
	int size = 0;
	int image[MAX_SIZE][MAX_SIZE];
	char c;

	size = scan(image, size);

	printf("Enter direction: ");
	scanf(" %c", &c);
	
	if (c == 'h') {
		flipH(image, size);
	}
	else {
		flipD(image, size);
	}

	printf("The image after rotation: \n");
	print(image, size);
	// Hint: To read in a letter using scanf,
	// you may want to use " %c" to skip 
	// whitespace characters such as '\n'.

	return 0;
}

// To flip an image horizontally
void flipH(int image[][MAX_SIZE], int size) {
	int temp;

	for (int i = 0; i < (size/2); i++) {
		for (int j = 0; j < size; j++) {
			temp = image[i][j];
			image[i][j] = image[(size - 1) - i][j];
			image[(size - 1) - i][j] = temp; 
		}
	}
}

// To flip an image diagonally
void flipD(int image[][MAX_SIZE], int size) {
	int temp;

	for (int i = 0; i < size; i++) {
		for (int j = (i+1); j < size; j++) {
			temp = image[i][j];
			image[i][j] = image[j][i];
			image[j][i] = temp; 

		}
	}
}

// To read in an image
int scan(int image[][MAX_SIZE]) {
	int size; 

	printf("Enter size: ");
	scanf("%d", &size);

	printf("Enter values: \n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &image[i][j]);
		}
	}

	return size;
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