// CS1010 AY2015/6 Semester 1
// PE2 Ex2: email.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 51

int main(void){
	char email[MAX_LENGTH];
	
	printf("Enter email address: ");
	scanf("%s", email);
	
	printf("This email address is not valid.\n");

	printf("This email address is valid but not friendly.\n");

	printf("This email address is valid and friendly.\n");

	return 0;
}