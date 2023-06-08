// palindrome.c
#include <stdio.h>
#define MAXLEN 20

int isPalindrome(char []);

int main(void) {
	char word[MAXLEN+1];

	printf("Enter word: ");

	if (isPalindrome(word))
		printf(" is a palindrome.\n");
	else
		printf(" is not a palindrome.\n");

	return 0;
}

// Return 1 if str is a palindrome, otherwise return 0.
int isPalindrome(char str[]) {


	return 0;
}

