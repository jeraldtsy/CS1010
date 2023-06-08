// CS1010 AY2015/6 Semester 2 PE2 Ex1
//
// minefield.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define MAX_SIZE 10

int readField(int [][MAX_SIZE]);
void printField(int [][MAX_SIZE], int);

int main(void) {
	int field[MAX_SIZE][MAX_SIZE], aftermath[MAX_SIZE][MAX_SIZE];
	int size;
	
	size = readField(field);
	
	printf("Aftermath: \n");
	printField(aftermath, size);
	
	printf("Maximum damage: \n"); // Incomplete
	printf("Number of safe areas: \n"); // Incomplete

	return 0;
}

// Read in a minefield
// Do NOT modify this function!
int readField(int field[][MAX_SIZE]) {
	int i,j, size;
	
	printf("Enter size: \n");
	scanf("%d", &size);
	
	printf("Enter minefield: \n");
	for (i=0; i<size; i++)
		for (j=0; j<size; j++)
			scanf("%d", &field[i][j]);
		
	return size;
}

// Print a minefield
// Do NOT modify this function!
void printField(int field[][MAX_SIZE], int size) {
	int i,j;
	
	for (i=0; i<size; i++){
		for (j=0; j<size; j++)
			printf("%d ", field[i][j]);
		printf("\n");
	}
}
