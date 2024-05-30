// pig_latin.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 80
#define MAX 999

void convert(char [], char []);

int main(void) {
    char str[LENGTH];
    char dest[MAX];
    
    printf("Enter sentence: ");
    fgets(str, LENGTH, stdin);
    
    convert(str, dest);
    printf("\nConverted: %s\n", dest);

    return 0;
}

// Convert src into pig-latin in dest
void convert(char src[], char dest[]) {
    int index = 0;
    int destIndex = 0;
    int consoIndex = 0;
    
    while (src[index] != '\0') {
        if (src[index] == '\n') {
            src[index] = '\0';
        }
        index++;
    }
    index = 0;
    
    while (src[index] != '\0') {
        if (src[index] == 'a' || src[index] == 'e' || src[index] == 'i' || src[index] == 'o' || src[index] == 'u') {
            while (!(isspace(src[index]))) {
                dest[destIndex] = src[index];
                index++;
                destIndex++;
            }
            strcat(dest, "way ");
            index++;
            destIndex += 4;
            
        }
        else {
            consoIndex = index;
            while (!(isspace(src[index]))){
                if (isspace(src[index+1]) || (src[index+1] == '\0')) {
                    dest[destIndex] = src[consoIndex];
                    index++;
                    break;
                }
                dest[destIndex] = src[index+1];
                index++;
                destIndex++;
            }
            
            strcat(dest, "ay ");
            index++;
            destIndex += 4;
        }
    }
}
