// anagrams.c
#include <stdio.h>
#define MAX_LENGTH 60

int areAnagrams(char [], char []);

int main(void) {
	char phrase1[MAX_LENGTH+1], phrase2[MAX_LENGTH+1];

	printf("Enter 1st phrase: ");

	printf("%s", phrase1); // print the input

	printf("Enter 2nd phrase: ");

	printf("%s", phrase2); // print the input

	if (areAnagrams(phrase1, phrase2))
		printf("They are anagrams.\n");
	else
		printf("They are not anagrams.\n");

	return 0;
}

// Return 1 if str1 and str2 are anagrams,
// otherwise return 0.
int areAnagrams(char str1[], char str2[]) {

	return 1;
}

