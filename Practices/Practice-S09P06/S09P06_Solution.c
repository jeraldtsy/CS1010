// Solution
// CS1010 AY2015 / 6 Semester 1
// PE2 Ex1: panel.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define GRID_SIZE 5
#define MAX_LENGTH 30

void readGrid(int grid[][GRID_SIZE]);
void printGrid(int grid[][GRID_SIZE]);
int readSequence(int sequence[]);
void press(int grid[][GRID_SIZE], int, int []);
int allOff(int grid[][GRID_SIZE], int *);

int main(void) {
	int grid[GRID_SIZE][GRID_SIZE], sequence[MAX_LENGTH], length;
	int gridAllOff;
	int* lights;

	readGrid(grid);

	length = readSequence(sequence);
	press(grid, length, sequence);
	gridAllOff = allOff(grid, &lights);

	if (gridAllOff == 1) {
		printf("All panels are off.\n");
	}
	else {
		printf("Number of lighted panels: %d\n", lights);
		printGrid(grid);
	}
	
	return 0;
}

// Read the initial state of a grid
void readGrid(int grid[][GRID_SIZE]) {
	int i, j;

	printf("Enter grid:\n");

	for (i = 0; i < GRID_SIZE; i++)
		for (j = 0; j < GRID_SIZE; j++)
			scanf("%d", &grid[i][j]);
}

// Print the current grid
void printGrid(int grid[][GRID_SIZE]) {
	int i, j;

	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++)
			printf("%d ", grid[i][j]);
		printf("\n");
	}
}

// Read the sequence of panels to be pressed
int readSequence(int sequence[]) {
	int i, length;

	printf("Enter length of sequence: ");
	scanf("%d", &length);

	printf("Enter sequence of panels: ");

	for (i = 0; i < length; i++)
		scanf("%d", &sequence[i]);

	return length;
}

void press(int grid[][GRID_SIZE], int length, int sequence[]) {
	int row, col;
	
	for (int i = 0; i < length; i++) {
		row = sequence[i] / 5; 
		col = sequence[i] % 5;
		
		if (grid[row][col] == 0) {
			grid[row][col] = 1; 
		}
		else {
			grid[row][col] = 0;
		}

		if ((row + 1) != 5) {
			if (grid[row + 1][col] == 0) {
				grid[row + 1][col] = 1;
			}
			else {
				grid[row + 1][col] = 0;
			}
		}

		if ((row - 1) != -1) {
			if (grid[row - 1][col] == 0) {
				grid[row - 1][col] = 1;
			}
			else {
				grid[row - 1][col] = 0;
			}
		}
		
		if ((col + 1) != 5) {
			if (grid[row][col + 1] == 0) {
				grid[row][col + 1] = 1; 
			}
			else {
				grid[row][col + 1] = 0;
			}
		}

		if ((col - 1) != -1) {
			if (grid[row][col - 1] == 0) {
				grid[row][col - 1] = 1; 
			}
			else {
				grid[row][col - 1] = 0;
			}
		}
	}
}

int allOff(int grid[][GRID_SIZE], int *lights) {
	int count = 0; 
	int isOff = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (grid[i][j] == 1) {
				count++;
				isOff = 0;
			}
		}
	}

	if (isOff == 0) {
		*lights = count;
		return 0;
	}

	return 1;
}