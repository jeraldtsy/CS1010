// Solution

#include <stdio.h>
#include <string.h>
#define MAX_ROWS 10      // maximum number of rows
#define MAX_COLS 10     // maximum number of columns 
#define MAX_LENGTH 100   // maximum number of characters in the message & result

int encrypt(int, int, char [], char [], char [][MAX_COLS]);
int decrypt(int, int, char [], char [], char [][MAX_COLS]);

int main(void) {
    
    int choice;
    int rows; 
    int cols;
    int length; 
    int isDone;
    char msg[MAX_LENGTH];
    char result[MAX_LENGTH];
    char arr[MAX_ROWS][MAX_COLS];
    
	printf("Enter 1 for encryption, 2 for decryption: ");
	scanf("%d", &choice);
	
	printf("Enter dimensions of a 2D array: ");
	scanf("%d %d", &rows, &cols);
	
	for (int i = 0; i < rows; i++) {
	    for (int j = 0; j < cols; j++) {
	        arr[i][j] = '@';
	    }
	}
	
	printf("Enter message: ");
	scanf("%s", &msg);
	
	if (choice == 1) {
	    isDone = encrypt(rows, cols, msg, result, arr);
	    if (isDone == 1) {
	         printf("Encrypted message: %s\n", result);
	    }
	    else {
	        printf("Encryption failed");
	    }
	}
	else {
	    isDone = decrypt(rows, cols, msg, result, arr);
	    if (isDone == 1) {
	         printf("Decrypted message: %s\n", result);
	    }
	    else {
	        printf("Decryption failed");
	    }
	    
	}

	return 0;
}

// Encrypt a message based on transposition algorithm
int encrypt(int rows, int cols, char message[], char result[], char arr [][MAX_COLS]){
    int index = 0;
    if (strlen(message) > (rows * cols)) {
        return 0;
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (index < ((rows * cols) - 1)) {
                arr[i][j] = message[index];
            }
            index++;
        }
    }
    
    index = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result[index] = arr[j][i];
            index++;
        }
        
    }
    
	return 1;
}

// Decrypt a message based on transposition algorithm
int decrypt(int rows, int cols, char message[], char result[], char arr [][MAX_COLS]){
	int index = 0;
    if (strlen(message) < (rows * cols)) {
        return 0;
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (index < ((rows * cols) - 1)) {
                arr[i][j] = message[index];
            }
            index++;
        }
    }
    index = 0;
    
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (arr[j][i] != '@') {
                result[index] = arr[j][i];
                index++;
            }
        }
    }
    
	return 1;
}