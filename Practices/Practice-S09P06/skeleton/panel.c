// CS1010 AY2015/6 Semester 1
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

int main(void) {
	int grid[GRID_SIZE][GRID_SIZE], sequence[MAX_LENGTH], length;

	readGrid(grid);

	length = readSequence(sequence);
	
	printf("All panels are off.\n");
	
	printf("Number of lighted panels: \n"); // Incomplete
	
	printGrid(grid);
	
	return 0;
}

// Read the initial state of a grid
void readGrid(int grid[][GRID_SIZE]) {
	int i,j;
	
	printf("Enter grid:\n");
	
	for (i=0; i<GRID_SIZE; i++)
		for (j=0; j<GRID_SIZE; j++)
			scanf("%d", &grid[i][j]);
}

// Print the current grid
void printGrid(int grid[][GRID_SIZE]) {
	int i,j;
	
	for (i=0; i<GRID_SIZE; i++){
		for (j=0; j<GRID_SIZE; j++)
			printf("%d ", grid[i][j]);
		printf("\n");
	}
}

// Read the sequence of panels to be pressed
int readSequence(int sequence[]) {
	int i,length;
	
	printf("Enter length of sequence: ");
	scanf("%d", &length);
	
	printf("Enter sequence of panels: ");

	for (i=0; i<length; i++)
		scanf("%d", &sequence[i]);
		
	return length;
}