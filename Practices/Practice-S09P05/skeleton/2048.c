// CS1010 AY2014/5 Semester 1
// PE2 Ex2: 2048.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define SIZE 4
#define LENGTH 21

void readGrid(int [][SIZE]); 
void printGrid(int [][SIZE]); 

int main(void) {
	int grid[SIZE][SIZE], target;
	char directions[LENGTH];

	printf("Enter grid:\n");
	readGrid(grid);
	
	printf("Enter directions: ");

	printf("Enter target: ");

	printGrid(grid);

	printf("%d is formed.\n", target);
	printf("%d is not formed.\n", target);

	return 0;
}

// Read in the grid
void readGrid(int grid[][SIZE]) {
	int i,j;

	for (i=0; i<SIZE; i++)
		for (j=0; j<SIZE; j++)
			scanf("%d",&grid[i][j]);
}

// Print out the grid
void printGrid(int grid[][SIZE]) {
	int i,j;

	for (i=0; i<SIZE; i++) {
		for (j=0; j<SIZE; j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}
}

