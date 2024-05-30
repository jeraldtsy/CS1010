// countWords.c
#include <stdio.h>
#include <ctype.h>
#define LENGTH 50

int word_count(char []);

int main(void) {
    char sentence[LENGTH];
    
    printf("Enter a sentence with at most %d characters:\n", LENGTH);
    fgets(sentence, LENGTH, stdin);

    printf("Sentence = %s\n", sentence);
    
    printf("Word count = %d\n", word_count(sentence));
    
    return 0;
}

// Count the number of words in str
int word_count(char str[]) {
    
    int ans = 0;
    int index = 0;
    
    
    while (str[index] != '\0') {
        
        if(isalpha(str[index])) {
            ans++;
            while ((!isspace(str[index]))) {
                index++;
            }
        }
        else {
            index++;
        }
    }
    return ans;
}
