/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex1
 * square.c
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#define MAXSIZE 9

int scanSquare(int [][MAXSIZE]);

int main(void) { 
	// Use the following printf statements 
	// for printing the output.
	printf("It is a semi-magic square.\n");  
	printf("It is not a semi-magic square.\n");

	return 0;
}

// Read in size of square and values in the square. 
// Return the size of square.
int scanSquare(int square[][MAXSIZE]) {
	int r, c, size;

	printf("Enter size of square: ");
	scanf("%d", &size);

	printf("Enter values in the square: \n");
	for (r=0; r<size; r++) {
		for (c=0; c<size; c++) {
			scanf("%d", &square[r][c]);
		}
	}

	return size;
}

