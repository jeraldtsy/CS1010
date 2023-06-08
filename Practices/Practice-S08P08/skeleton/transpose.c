// transpose.c

#include <stdio.h>
#define MAX_ROWS 10      // maximum number of rows
#define MAX_COLS 10     // maximum number of columns 
#define MAX_LENGTH 100   // maximum number of characters in the message & result

int encrypt(int, int, char [], char []);
int decrypt(int, int, char [], char []);

int main(void) {
	printf("Enter 1 for encryption, 2 for decryption: ");
	printf("Enter dimensions of a 2D array: ");
	printf("Enter message: ");
	
	printf("Encrypted message: %s\n", result);
	printf("Encryption failed.\n");
	printf("Decrypted message: %s\n", result);
	printf("Decryption failed.\n");
	
	return 0;
}

// Encrypt a message based on transposition algorithm
int encrypt(int rows, int cols, char message[], char result[]){
	return 0;
}

// Decrypt a message based on transposition algorithm
int decrypt(int rows, int cols, char message[], char result[]){
	return 0;
}

