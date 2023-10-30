/**
 * pyramid.c
 * This program computes the maximum-value path
 * in a triangular matrix.
 */
// Solution

#include <stdio.h>
#define MAX_ROWS 10

int maxPathValue(int[][MAX_ROWS], int);
int scanTriangularArray(int[][MAX_ROWS]);
void printTriangularArray(int[][MAX_ROWS], int);

int main(void) {
	int size; // number of rows
	int table[MAX_ROWS][MAX_ROWS];
	int r, c;

	size = scanTriangularArray(table);
	//printTriangularArray(table, size);   // for checking

	printf("Maximum path value = %d\n", maxPathValue(table, size));

	return 0;
}

// Compute the path that gives the maximum value
int maxPathValue(int arr[][MAX_ROWS], int size) {
	for (int row = size - 2; row >= 0; row--) {

		for (int col = 0; col <= row; col++) {

			int leftPathValue = arr[row + 1][col];
			int rightPathValue = arr[row + 1][col + 1];

			if (leftPathValue > rightPathValue) {
				arr[row][col] += leftPathValue;
			}
			else {
				arr[row][col] += rightPathValue;
			}
		}
	}

	return arr[0][0];
}

// Read data into 2-dimensional triangular array arr,
// and return the number of rows.
int scanTriangularArray(int arr[][MAX_ROWS]) {
	int rows; 
	
	printf("Enter number of rows: ");
	scanf("%d", &rows);

	printf("Enter values for array:\n");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (j > i) {
				break;
			}
			else {
				scanf("%d", &arr[i][j]);
			}
		}
	}

	return rows;
}

// Print elements in the 2-dimensional triangular array arr.
// For checking purpose.
void printTriangularArray(int arr[][MAX_ROWS], int size) {
	int r, c;

	for (r = 0; r < size; r++) {
		for (c = 0; c <= r; c++) {
			printf("%d\t", arr[r][c]);
		}
		printf("\n");
	}
}