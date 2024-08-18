// CS1010 AY2014/5 Semester 1
// PE2 Ex1: ngram.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
// Solution 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 101

int mostFrequentUnigram(char[], char[]);
int mostFrequentBigram(char[], char[]);

int main(void) {
	char text[MAX_SIZE], result[3];
	int option, unigramFreq, bigramFreq;

	printf("Enter text: ");
    fgets(text, MAX_SIZE, stdin);

	printf("Enter option: ");
    scanf("%d", &option);

    if (option == 1) {

        unigramFreq = mostFrequentUnigram(text, result);

        printf("Most frequent unigram: %s\n", result);
        printf("Frequency: %d\n", unigramFreq);

    }
    
    else {

        bigramFreq = mostFrequentBigram(text, result);

        printf("Most frequent bigram: %s\n", result);
	    printf("Frequency: %d\n", bigramFreq);
    }
	
	return 0;
}

int mostFrequentUnigram(char text[], char result[]) {
    char ch;
    int len, tempCount, index;
    int greatestCount = 0;

    len = strlen(text);

    for (int i = 0; i < len; i++) {
        ch = text[i];
        tempCount = 0;
        
        for (int j = 0; j < len; j++) {
            if (isspace(text[i])) {
                break;
            }
            else if (text[j] == ch) {
                tempCount++;
            }
        }

        if (tempCount > greatestCount) {
            greatestCount = tempCount;
            index = i; 
        }

        else if (tempCount == greatestCount) {
            if (text[i] < text[index]) {
                index = i;
            }
        }
    }

    result[0] = text[index];
    
    return greatestCount;
}

int mostFrequentBigram(char text[], char result[]) {
    int len, tempCount, index; 
    int greatestCount = 0;

    len = strlen(text);

    for (int i = 0; i < len; i++) {
        tempCount = 0;
        if (!(isspace(text[i]))) {
            for (int j = (i+1); j < len; j++) {
                if (text[i] == text[j]) {
                    if (((i+1) < len) && ((j+1) < len)) {
                        if (!(isspace(text[i+1]))) {
                            if (text[i+1] == text [j+1]) {
                              tempCount++;
                            }
                        }
                    }
                }
            }    
        }

        if (tempCount > greatestCount) {
            greatestCount = tempCount;
            index = i;
        }
        else if (tempCount == greatestCount) {
            if ((text[i] < text[index]) && (!(isspace(text[i])))) {
                index = i;
            }
        }
    }

    result[0] = text[index];
    result[1] = text[index + 1];

    return greatestCount + 1;
}