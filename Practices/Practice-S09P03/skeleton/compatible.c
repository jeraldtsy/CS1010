// CS1010 AY2013/4 Semester 1
// PE2 Ex1: compatible.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Given two names, strike off matching letters in the names,
// find the number of remaining letters in the names, and 
// determines if the names are compatible.
#include <stdio.h>

// Name has at most 35 characters
#define MAXLEN 36

// Fill in your function prototypes below


int main(void) {
	char name1[MAXLEN], name2[MAXLEN];
	int remain1,   // number of remaining characters in name1 
	    remain2;   // and name2 after matching

	printf("Enter 2 names below:\n"); // given, do not remove/change this line
	readName(name1);                  // given, do not remove/change this line
	readName(name2);                  // given, do not remove/change this line

	// Call the match() function here

	
	printf("Number of letters remaining in 1st name = %d\n", remain1);
	printf("Number of letters remaining in 2nd name = %d\n", remain2);

	printf("The names are compatible.\n");
	printf("The names are not compatible.\n");

	return 0;
}

// To students: You must write the function's description here. [1 mark]
// readName() function


// To students: You must write the function's description here. [1 mark]
// match() function


