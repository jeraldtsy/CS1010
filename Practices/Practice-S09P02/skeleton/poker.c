// CS1010 AY2012/3 Semester 1
// PE2 Ex2: poker.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

#include <stdio.h>
#define NUMBER_OF_CARDS 5

void read_hand(int []);

int main(void) {
	int hand1[NUMBER_OF_CARDS], hand2[NUMBER_OF_CARDS]; 

	// Read in the hand of the first player
	printf("Enter the hand of player 1:\n");
	read_hand(hand1);

	// Read in the hand of the second player
	printf("Enter the hand of player 2:\n");
	read_hand(hand2);

	return 0;
}

// Reads an array of integers representing a hand
void read_hand(int hand[]) {
	int i;
	
	for (i = 0; i < NUMBER_OF_CARDS; i++) {
		scanf("%d", &hand[i]);
	}
}
