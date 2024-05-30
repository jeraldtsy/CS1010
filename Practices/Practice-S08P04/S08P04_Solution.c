// palindrome.c
// Solution
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 20

int isPalindrome(char [], int);

int main(void) {
    char word[MAXLEN+1];
    int index = 0;
    int wordLength;
    int flag;
    
    printf("Enter word: ");
    fgets(word, MAXLEN, stdin);
    
    wordLength = strlen(word) - 1;
    
    if (word[wordLength] == '\n') {
        word[wordLength] = '\0';
    }
    
    flag = isPalindrome(word, wordLength);
    
    if (flag == 1)
        printf("%s is a palindrome.\n", word);
    else
        printf("%s is not a palindrome.\n", word);

    return 0;
}

// Return 1 if str is a palindrome, otherwise return 0.
int isPalindrome(char str[], int length) {
    
    for (int i = 0; i < length; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }
    
    return 1;
}
