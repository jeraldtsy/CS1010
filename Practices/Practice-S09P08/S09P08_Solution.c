// Solution
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
int detonate(int [][MAX_SIZE], int [][MAX_SIZE], int, int *);

int main(void) {
	int field[MAX_SIZE][MAX_SIZE], aftermath[MAX_SIZE][MAX_SIZE];
	int size, safeArea; 
    int *maxDmg;
	
	size = readField(field);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            aftermath[i][j] = 0;
        }
    }
	safeArea = detonate(field, aftermath, size, &maxDmg);

	printf("Aftermath: \n");
	printField(aftermath, size);
	
	printf("Maximum damage: %d\n", maxDmg);
	printf("Number of safe areas: %d\n", safeArea); 

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

int detonate(int field[][MAX_SIZE], int aftermath[][MAX_SIZE], int size, int *maxDmg) {
    int safeArea = 0, Dmg= 0;
    int currDmg;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (field[i][j] != 0) {
                currDmg = field[i][j];

                while (currDmg != 1) {
                    //North
                    if ((i - (currDmg - 1)) >= 0) {
                        aftermath[i - (currDmg - 1)][j]++;
                    }
                    //South
                    if ((i + (currDmg - 1)) < size) {
                        aftermath[i + (currDmg - 1)][j]++;
                    }
                    //West
                    if ((j - (currDmg - 1)) >= 0) {
                        aftermath[i][j - (currDmg - 1)]++;
                    }
                    //East
                    if ((j + (currDmg - 1)) < size) {
                        aftermath[i][j + (currDmg - 1)]++;
                    }
                    currDmg--;
                }

                if (currDmg == 1) {
                    aftermath[i][j]++;
                    currDmg--;
                }
            }
        }
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (aftermath[i][j] == 0) {
                safeArea++;
            }
            else {
                if (aftermath[i][j] > Dmg) {
                    Dmg = aftermath[i][j];
                }
            }
        }
    }

    *maxDmg = Dmg;

    return safeArea;


}
