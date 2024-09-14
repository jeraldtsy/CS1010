// Solution

#include <stdio.h>

#define MAX 1000

int input(int[]);
void printBridge(int, int[]);
void jump(int, int[]);
int checkGameState(int, int[]);

int main (void) {
	int size; 
	int arr[MAX];
	int gameState = 1;
	int numJumps = 0;

	size = input(arr);
	printBridge(size, arr);

	while (gameState == 1) {
		jump(size, arr);
		numJumps++;
		printBridge(size, arr);

		gameState = checkGameState(size, arr);
		
		if (gameState == 0) {
			printf("Oh no! It seems like the two clans of frogs are stuck\n");
		}
		else if(gameState == 2) {
			printf("Congratulations! The frogs took %d jumps to cross the bridge!\n", numJumps);
		}
	}

	return 0;
}

int input(int arr[]) {
	int size;

	printf("Please enter the length of the bridge:");
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		printf("Please insert frog at position %d:", i);
		scanf("%d", &arr[i]);
	}

	return size;
}

void printBridge(int size, int arr[]) {

	printf("Position:");
	for (int i = 0; i < size; i++) {
		printf("%d ", i);
	}
	printf("\n");
	printf("Bridge:");

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void jump(int size, int arr[]) {
	int hasJumped = 0;
	int position;

	while (hasJumped == 0) {
		printf("Move the frog at position:");
		scanf("%d", &position);
		
		//1. Space
		//2. Jump over frog
		//3. is not size
		if (arr[position] == 1) {
			if (arr[position+1] == 0) {
				arr[position] = 0;
				arr[position + 1] = 1;
				hasJumped = 1;
			}
			else if (arr[position + 2] == 0) {
				arr[position] = 0;
				arr[position + 2] = 1;
				hasJumped = 1;
			}
			else if ((arr[position + 1] != 0) && (arr[position + 2] != 0)) {
				printf("Invalid move!\n");
				hasJumped = 0;
			}
		}

		else if (arr[position] == -1) {
			if (arr[position - 1] == 0) {
				arr[position] = 0;
				arr[position - 1] = -1;
				hasJumped = 1;
			}
			else if (arr[position - 2] == 0) {
				arr[position] = 0;
				arr[position - 2] = -1;
				hasJumped = 1;
			}
			else if ((arr[position - 1] != 0) && (arr[position - 2] != 0)) {
				printf("Invalid move!\n");
				hasJumped = 0;
			}
		}
		else if (arr[position] == 0) {
			printf("Invalid move!\n");
			hasJumped = 0;
		}
	}
}

int checkGameState(int size, int arr[]) {
	//1 = can play
	// 0 = stuck
	//2 completed
	int index;
	int isCompleted = 1;

	for (int i = 0; i < size; i++) {
		if (arr[i] == 0) {
			index = i;
			break;
		}
	}

	for (int i = 0; i < index; i++) {
		if (arr[i] != -1) {
			isCompleted = 0;
		}
	}

	for (int i = (index+1); i < size; i++) {
		if (arr[i] != 1) {
			isCompleted = 0;
		}
	}

	if (isCompleted == 0) {
		for (int i = 0; i < size; i++) {
				if (arr[i] == 1) { 
					if ((i + 1 < size && arr[i + 1] == 0) || (i + 2 < size && arr[i + 2] == 0)) {
						return 1; 
					}
				} else if (arr[i] == -1) { 
					if ((i - 1 >= 0 && arr[i - 1] == 0) || (i - 2 >= 0 && arr[i - 2] == 0)) {
						return 1; 
					}
				}
			}
	}

	else {
		return 2;
	}

	return 1;
}