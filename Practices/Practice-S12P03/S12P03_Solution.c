// Solution
// anagrams.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 60

int areAnagrams(char [], char []);

int main(void) {
	char phrase1[MAX_LENGTH+1], phrase2[MAX_LENGTH+1];
	int length;

	printf("Enter 1st phrase: ");
	fgets(phrase1, MAX_LENGTH, stdin);
	length = strlen(phrase1);
	if (phrase1[length - 1] == '\n') {
		phrase1[length - 1] = '\0';
	}

	printf("%s\n", phrase1); // print the input

	printf("Enter 2nd phrase: ");
	fgets(phrase2, MAX_LENGTH, stdin);
	length = strlen(phrase2);
	if (phrase2[length - 1] == '\n') {
		phrase2[length - 1] = '\0';
	}

	printf("%s\n", phrase2); // print the input

	if (areAnagrams(phrase1, phrase2))
		printf("They are anagrams.\n");
	else
		printf("They are not anagrams.\n");

	return 0;
}

// Return 1 if str1 and str2 are anagrams,
// otherwise return 0.
int areAnagrams(char str1[], char str2[]) {
	char temp;
	char str1NoSpace[MAX_LENGTH];
	char str2NoSpace[MAX_LENGTH];
	int index = 0; 
	int noSpaceIndex = 0;

	while (str1[index] != '\0') {
		if (isalnum(str1[index])) {
			str1NoSpace[noSpaceIndex] = tolower(str1[index]);
			noSpaceIndex++;
		}
		
		index++;
	}
	str1NoSpace[noSpaceIndex] = '\0';

	index = 0;
	noSpaceIndex = 0;

	while (str2[index] != '\0') {
		if (isalnum(str2[index])) {
			str2NoSpace[noSpaceIndex] = tolower(str2[index]);
			noSpaceIndex++;
		}
		
		index++;
	}
	str2NoSpace[noSpaceIndex] = '\0';

	if (strlen(str1NoSpace) != strlen(str2NoSpace)) {
		return 0;
	}

	for (int i = 0; i < strlen(str1NoSpace); i++) {
		for (int j = (i+1); j < strlen(str1NoSpace); j++) {
			if (str1NoSpace[i] > str1NoSpace[j]) {
				temp = str1NoSpace[i];
				str1NoSpace[i] = str1NoSpace[j];
				str1NoSpace[j] = temp;
			}
		}
	}

	for (int i = 0; i < strlen(str2NoSpace); i++) {
		for (int j = (i+1); j < strlen(str2NoSpace); j++) {
			if (str2NoSpace[i] > str2NoSpace[j]) {
				temp = str2NoSpace[i];
				str2NoSpace[i] = str2NoSpace[j];
				str2NoSpace[j] = temp;
			}
		}
	}

	for (int i = 0; i < strlen(str1NoSpace); i++) {
		if (!(str1NoSpace[i] == str2NoSpace[i])) {
			return 0;
		}
	}

	return 1;
}