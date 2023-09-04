// magic_square.c
// To generate a magic square for nxn matrix (n is odd integer)
// Solution

#include <stdio.h>
#define MAX_SIZE 15

void printMagic(int[][MAX_SIZE], int);
void generateMagic(int[][MAX_SIZE], int);

int main(void) {
	int magic[MAX_SIZE][MAX_SIZE] = { {0} };
	int size;

	printf("Enter size of matrix: ");
	scanf("%d", &size);
	printf("%d\n", size);
	generateMagic(magic, size);
	printMagic(magic, size);

	return 0;
}

// To generate the magic square
void generateMagic(int arr[][MAX_SIZE], int size) {
	int i;
	int j;
	int tempI;
	int tempJ;
	int num = 1;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = 0;
		}
	}

	i = 0;
	j = size / 2;
	arr[i][j] = num;

	while (num < (size * size)) {
		tempI = (i - 1);
		tempJ = (j + 1); //Step 3

		if (tempI < 0) {
			tempI = (size - 1);
		}

		if (tempJ == size) {
			tempJ = 0;
		}				
		
		if (arr[tempI][tempJ] == 0) {
			arr[tempI][tempJ] = (num + 1);
			i = tempI;
			j = tempJ;
		}
		else {
			i += 1;
			if (i == size) {
				i = 0;
			}

			arr[i][j] = (num + 1);
		}
		num++;
	}
}

// To print the magic square
void printMagic(int arr[][MAX_SIZE], int size) {
	int row, col;

	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++)
			printf("%5d", arr[row][col]);
		printf("\n");
	}
}