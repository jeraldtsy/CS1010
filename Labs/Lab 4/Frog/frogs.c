/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex3
 * frogs.c
 * <Type your program description here>
 * <Type your name here>
 * <Type your discussion group here>
 */
#include <stdio.h>

int jump(int, int, int[]);
void printBridge(int, int[]);
int checkGameState(int, int[]);

int main(void) {

	int bridge[1000];
	int i;
	int lengthOfBridge;
	int position;

	int numMoves = 0;
	int gameState;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthOfBridge);

 	for (i=0; i<lengthOfBridge; i++) {
		int frogType;

		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);

		bridge[i] = frogType;
	}

	printf("Input completed\n");
	printBridge(lengthOfBridge, bridge);

	printf("Please start moving the frogs\n");

	/** Insert your code below **/


	return 0;
}

//This function is provided for you
/**
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 **/
void printBridge(int size, int bridge[]) {

	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}

