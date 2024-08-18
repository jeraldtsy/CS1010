// CS1010 AY2014/5 Semester 1
// PE2 Ex2: 2048.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
// Solution

#include <stdio.h>
#include <string.h>
#define SIZE 4
#define LENGTH 21

void readGrid(int [][SIZE]); 
void printGrid(int [][SIZE]);
void play(int [][SIZE], char[]);
void moveUp(int [][SIZE], char);
void moveLeft(int [][SIZE], char);
int exists(int [][SIZE], int);

int main(void) {
	int grid[SIZE][SIZE], target, isFormed; 
	char directions[LENGTH];

	printf("Enter grid:\n");
	readGrid(grid);
	
	printf("Enter directions: ");
    scanf("%s", directions);

	printf("Enter target: ");
    scanf("%d", &target);

    play(grid, directions);
	printGrid(grid);
    isFormed = exists(grid, target);

    if (isFormed == 1) {
    	printf("%d is formed.\n", target);
    }
    else {
	    printf("%d is not formed.\n", target);
    }

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

void play(int grid[][SIZE], char directions[]) {
    int len; 
    char ch; 

    len = strlen(directions);

    for (int i = 0; i < len; i++) {
        ch = directions[i];

        if (ch == 'U') {
            moveUp(grid, ch);
        }
        
        else if (ch == 'L'){
            moveLeft(grid, ch);
        }
    }
}
void moveUp(int grid[][SIZE], char ch) { 
    //flush to the top
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                for (int k = i; k < 4; k++) {
                    if (grid[k][j] != 0) {
                        grid[i][j] = grid[k][j];
                        grid[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == grid[i+1][j]) {
                grid[i][j] *= 2;
                grid[i+1][j] = 0;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                for (int k = i; k < 4; k++) {
                    if (grid[k][j] != 0) {
                        grid[i][j] = grid[k][j];
                        grid[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void moveLeft(int grid[][SIZE], char ch) {
    //flush to the left
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                for (int k = j; k < 4; k++) {
                    if (grid[i][k] != 0) {
                        grid[i][j] = grid[i][k];
                        grid[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    //Merge
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == grid[i][j+1]) {
                grid[i][j] *= 2;
                grid[i][j+1] = 0;
            }
        }
    }

    //flush to the left
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                for (int k = j; k < 4; k++) {
                    if (grid[i][k] != 0) {
                        grid[i][j] = grid[i][k];
                        grid[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

}

int exists(int grid[][SIZE], int target) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == target) {
                return 1;
            }
        }
    }
    return 0;
}