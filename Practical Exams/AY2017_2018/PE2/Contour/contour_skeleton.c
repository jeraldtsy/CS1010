// CS1010 AY2017/8 Semester 1
// PE2 Ex2: contour.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 12
#define MAX_COL 12

void getPeaksValleys (int [][MAX_COL], int [][MAX_COL], int, int, int *, int *);
void getHikeTrail(int [][MAX_COL], int [][MAX_COL], int, int);
void scanArray(int [][MAX_COL], int, int);
void printArray(int [][MAX_COL], int, int);

int main(void) {
	int map[MAX_ROW][MAX_COL];
	int hike [MAX_ROW][MAX_COL];
	int peaksandvalleys [MAX_ROW][MAX_COL];
	int nopeaks, novalleys;
	int row, col;

	printf("Enter no of rows and cols:");
	scanf("%d %d", &row, &col);
	printf ("Enter the data:\n");
	scanArray(source, row, col);


	return 0;
}

void getPeaksValleys(int map[][MAX_COL], int peaksandvalleys[][MAX_COL], int row, int col, int *nopeaks, int *novalleys) {


}

void getHikeTrail(int map[][MAX_COL], int hike[][MAX_COL], int row, int col) {


}

// function that reads in the data for the contour map
void scanArray(int array[][MAX_COL], int row, int col) {
	int r,c;
	for (r = 0; r < row; r++) 
		for (c = 0; c < col; c++) 
			scanf("%d", &array[r][c]);
}

// function that takes in and prints the 2D map 
void printArray(int array[][MAX_COL], int row, int col) {
	int r,c;
	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) 
			printf("%d ", array[r][c]);
		printf("\n");
	}
}
