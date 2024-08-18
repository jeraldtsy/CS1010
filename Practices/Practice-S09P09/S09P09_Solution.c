// Solution
// CS1010 AY2015/6 Semester 2 PE2 Ex2
//
// nato.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>
#define MAXLEN 101

int decrypt(char []);

int main(void) {
    int isDecrypted = 0;
	char name[MAXLEN];

    printf("Enter name in NATO alphabet: ");
    scanf("%s", name);

    isDecrypted = decrypt(name);

    if (isDecrypted == 1) {
	    printf("Decrypted name: %s\n", name);
    }
    else {
	    printf("The given name cannot be decrypted.\n");
    }

	return 0;
}

int decrypt(char name[]){
    char ch;
    int index = 0, length, pos, count = 0;
    int isDecrypted = 1;
    char decrypted[MAXLEN];
	char alphabet[26][MAXLEN] = {
		"ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO",
		"FOXTROT", "GOLF", "HOTEL", "INDIA", "JULIETT",
		"KILO", "LIMA", "MIKE", "NOVEMBER", "OSCAR",
		"PAPA", "QUEBEC", "ROMEO", "SIERRA", "TANGO",
		"UNIFORM", "VICTOR", "WHISKEY", "XRAY", "YANKEE",
		"ZULU"};
    
    while (name[index] != '\0') {
        ch = name[index];
        for (int i = 0; i < 26; i++) {
            if (alphabet[i][0] == ch) {
                length = strlen(alphabet[i]);
                pos = i;
                break;
            }
        }

        for (int j = 0; j < length; j++) {
            if (name[index + j] != alphabet[pos][j]) {
                isDecrypted = 0;
                return 0;
            }
            if (isDecrypted == 1) {
                ch = alphabet[pos][0];
            }
        }
        decrypted[count] += ch;
        count++;
        index += length;
    }

    strcpy(name, decrypted);
			
    return 1;
}