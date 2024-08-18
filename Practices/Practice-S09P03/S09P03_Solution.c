// CS1010 AY2013/4 Semester 1
// PE2 Ex1: compatible.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Given two names, strike off matching letters in the names,
// find the number of remaining letters in the names, and 
// determines if the names are compatible.
// Solution
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Name has at most 35 characters
#define MAXLEN 36

// Fill in your function prototypes below

void readName (char[]);
void match(char[], char[], int*, int*);

int main(void) {
	char name1[MAXLEN], name2[MAXLEN];
	int remain1,   // number of remaining characters in name1 
	    remain2;   // and name2 after matching

	printf("Enter 2 names below:\n"); // given, do not remove/change this line
	readName(name1);                  // given, do not remove/change this line
	readName(name2);                  // given, do not remove/change this line

	// Call the match() function here
    match(name1, name2, &remain1, &remain2);
	
	printf("Number of letters remaining in 1st name = %d\n", remain1);
	printf("Number of letters remaining in 2nd name = %d\n", remain2);

    if ((remain1%2 == 0) && (remain2%2 ==0) || ((remain1%2 == 1) && (remain2%2 == 1))) {
        printf("The names are compatible.\n");
    }
	
    else {
        printf("The names are not compatible.\n");
    }

	return 0;
}

// To students: You must write the function's description here. [1 mark]
// readName() function
void readName(char arr[]) {
    fgets(arr, MAXLEN, stdin);
}

// To students: You must write the function's description here. [1 mark]
// match() function
void match(char name1[], char name2[], int* remain1, int* remain2) {

    int len1, len2, count, flag;

    len1 = strlen(name1);
    len2 = strlen(name2);

    for (int i = 0; i < len1; i++) {
        flag = 0;
        for (int j = 0; j < len2; j++) {
            if (toupper(name1[i]) == toupper(name2[j])) {
                flag = 1;
                name2[j] = '*';
            }
            if (flag == 1) {
                break;
            }
        }
        if (flag == 1) {
            name1[i] = '*';
        }
    }
    count = 0;
    for (int i = 0; i < len1; i++) {
        if (isalpha(name1[i])){
            count++;
        }
    }
    *remain1 = count; 
    count = 0; 

    for (int i = 0; i < len2; i++) {
        if (isalpha(name2[i])) {
            count++;
        }
    }

    *remain2 = count;
}