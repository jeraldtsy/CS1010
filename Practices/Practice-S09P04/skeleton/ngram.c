// CS1010 AY2014/5 Semester 1
// PE2 Ex1: ngram.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define MAX_SIZE 101

int main(void) {
	char text[MAX_SIZE], result[3];
	int option, unigramFreq, bigramFreq;

	printf("Enter text: ");
	printf("Enter option: ");

	printf("Most frequent unigram: %s\n", result);
	printf("Frequency: %d\n", unigramFreq);

	printf("Most frequent bigram: %s\n", result);
	printf("Frequency: %d\n", bigramFreq);
	
	return 0;
}

