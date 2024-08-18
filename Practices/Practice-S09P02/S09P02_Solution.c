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
void type_and_keycard_ranks(int[], int *, int *);
int who_wins(int, int, int, int);

int main(void) {
	int hand1[NUMBER_OF_CARDS], hand2[NUMBER_OF_CARDS];
	int handRank1, handRank2, keyCard1, keyCard2;
	int winner; 

	// Read in the hand of the first player
	printf("Enter the hand of player 1:\n");
	read_hand(hand1);

	// Read in the hand of the second player
	printf("Enter the hand of player 2:\n");
	read_hand(hand2);

	type_and_keycard_ranks(hand1, &handRank1, &keyCard1);
	type_and_keycard_ranks(hand2, &handRank2, &keyCard2);

	printf("Player 1 has a hand of type rank %d and key card rank %d\n", handRank1, keyCard1);
	printf("Player 2 has a hand of type rank %d and key card rank %d\n", handRank2, keyCard2);

	winner = who_wins(handRank1, handRank2, keyCard1, keyCard2);

	if (winner == 1) {
		printf("Player 1 wins.");
	}
	else if (winner == 2) {
		printf("Player 2 wins.");
	}
	else {
		printf("There is a draw.");
	}


	return 0;
}

// Reads an array of integers representing a hand
void read_hand(int hand[]) {
	int i;
	
	for (i = 0; i < NUMBER_OF_CARDS; i++) {
		scanf("%d", &hand[i]);
	}
}

void type_and_keycard_ranks(int hand[], int * handRank, int * keyCard) {
	int count = 1;
	int tempCount, index = 0;
	int greatestValue = 0, tempValue; 
	// find mostRepeats
	// find index 
	for (int i = 0; i < 5; i++) {
		tempCount = 1;
		for (int j =(i+1); j < 5; j++) {
			if (hand[i] == hand[j]) {
				tempCount++;
			}
		}
		if (tempCount >= count) {
			count = tempCount; 
			tempValue = hand[i];
			if (tempValue == 1) {
				greatestValue = 14;
			}
			else if (tempValue > greatestValue) {
				greatestValue = tempValue;
			}
			index = i; 
		}
	}

	if (count != 1) {
		*handRank = count;
		*keyCard = hand[index] - 1;
	}
	else {
		*handRank = 1;

		 for (int i = 0; i < 5; i++) {
			if (hand[i] > greatestValue) {
				greatestValue = hand[i];
			}
		 }
		 *keyCard = greatestValue - 1;

	}

	if (*keyCard == 0) {
		*keyCard = 13;
	}
 }

 int who_wins(int handRank1, int handRank2, int keyCard1, int keyCard2) {
	if (handRank1 > handRank2) {
		return 1;
	}
	else if (handRank2 > handRank1) {
		return 2;
	}
	else {
		if (keyCard1 > keyCard2) {
			return 1;
		}
		else if (keyCard2 > keyCard1) {
			return 2;
		}
	}

	return 0;
 }