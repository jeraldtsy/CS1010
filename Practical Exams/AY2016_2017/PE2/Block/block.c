// CS1010 AY2016/7 Semester 1
// PE2 Ex2: block.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

#include <stdio.h>
#define MAX_SIZE 10
#define MAX_NUM_INDEXES 20

void printGrid(int [][MAX_SIZE], int);

int main(void) {
	int grid[MAX_SIZE][MAX_SIZE], size;
	
	printf("Game completed.\n");		
	printf("Score: \n"); // Incomplete
	printf("Number of blocks left: \n"); // Incomplete
	printf("Unable to complete game.\n");	
	
	printf("Final state of the grid: \n");
	printGrid(grid, size);

	return 0;
}

// Print the grid
void printGrid(int grid[][MAX_SIZE], int size){
	int i, j;
	
	for (i = 0; i < size; i++){
		for (j = 0; j< size; j++)
			printf("%d ", grid[i][j]);
		printf("\n");
	}
}

/* Sample printf statements for readInputs()
printf("Enter size of grid: ");
printf("Enter grid: \n");
printf("Enter number of indexes: ");
printf("Enter indexes: ");
*/