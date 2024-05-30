// rot.c
// Solution

#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 80

void encryptMsg(char [], char []);
void decryptMsg(char [], char []);

int main(void) {
    int option;
    char msg[MAX_LENGTH];
    char result[MAX_LENGTH];
    
    printf("Enter 1 for encryption, 2 for decryption: ");
    scanf("%d", &option);
    
    printf("Enter message: ");
    scanf("%s", msg);
    
    if (option == 1) {
        encryptMsg(msg, result);
    }
    else {
        decryptMsg(msg, result);
    }
    
    return 0;
}

// Encrypt a message based on transpose-13 algorithm
void encryptMsg(char message[], char result[]){
    int index = 0;
    
    while (message[index] != '\0') {
    
        if (isupper(message[index])) {
            if (((message[index] + 13) > 90)){
                result[index] = ((message[index] + 13) - 91) + 65;
            }
            else {
                result[index] = message[index] + 13;
            }
        }
        else {
            if ((message[index] + 13) > 122) {
                result[index] = ((message[index] + 13) - 123) + 97;
            }
            else {
                result[index] = message[index] + 13;
            }
        }
        index++;
    }
    
    printf("Encrypted message: %s\n", result);
}

// Decrypt a message based on transpose-13 algorithm
void decryptMsg(char message[], char result[]){
    int index = 0;
    
    while (message[index] != '\0') {
        
        if (isupper(message[index])) {
            if (((message[index] - 13) < 65)){
                result[index] = 91 - (65 - (message[index] - 13));
            }
            else {
                result[index] = message[index] - 13;
            }
        }
        else {
            if ((message[index] - 13) < 97) {
                result[index] = 123 - (97 - (message[index] - 13));
            }
            else {
                result[index] = message[index] - 13;
            }
        }

        index++;
    }
    
    printf("Decrypted message: %s\n", result);
}
