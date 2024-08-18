// CS1010 AY2012/3 Semester 1 PE2 Ex1
//
// password.c
// This program checks whether a new password satisfies
// corresponding rules or not.
//
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Solution

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN 15

// function prototypes
int isValidPassword(char[], char[], char[], char[]);

// main function complete, not to be changed!
int main(void) {
	char domain[LEN + 1], userID[LEN + 1],
	oldPasswd[LEN + 1], newPasswd[LEN + 1], confirmPasswd[LEN + 1];

	printf("Domain: ");
	scanf("%s", domain);

	printf("UserID: ");
	scanf("%s", userID);

	printf("Old password: ");
	scanf("%s", oldPasswd);

	printf("New password: ");
	scanf("%s", newPasswd);

	printf("Confirm new password: ");
	scanf("%s", confirmPasswd);

	if (isValidPassword(userID, oldPasswd, newPasswd, confirmPasswd))
		printf("Password changed successfully!\n");
	else
		printf("Error: Invalid userID or password!\n");

	return 0;
}

// Check whether a new password is valid
int isValidPassword(char userID[], char oldPasswd[], char newPasswd[], char confirmPasswd[]) {
	// 1. New password must be at least 8 characters in length
	// 2. New password must be complex
	// 3. The new password must not contain UserID
	// 4. The confirmation for the new password must match the new password.
	// 5. The new password must not be the same as old password. 

	int length; 
	int hasUpper = 0; 
	int hasLower = 0; 
	int strCmpResult;
	char tempString[LEN] = "";
	char tempString2[LEN] = "";

	length = strlen(newPasswd);

	if (length < 8) {
		return 0; 
	}

	for (int i = 0; i < length; i++) {
		if ((hasUpper != 1) && (isupper(newPasswd[i]))) {
			hasUpper = 1;
		}
		if ((hasLower != 1) && (islower(newPasswd[i]))) {
			hasLower = 1; 
		}
		if (!((isalnum(newPasswd[i]) || (newPasswd[i] == '_')))) {
			return 0;
		}
	}

	if ((hasUpper == 0) || (hasLower == 0)) {
		printf("not complex");
		return 0;
	}
	
	strcpy(tempString, newPasswd);
	for (int i = 0; i < length; i++) {
		tempString[i] = tolower(tempString[i]);
	}

	strcpy(tempString2, oldPasswd);
	for (int i = 0; i < length; i++) {
		tempString2[i] = tolower(tempString2[i]);
	}

	strCmpResult = strcmp(tempString, tempString2);

	if (strCmpResult == 0) {
		return 0;
	}

	strCmpResult = strcmp(newPasswd, confirmPasswd);

	if (strCmpResult != 0) {
		return 0;
	}

	strCmpResult = strcmp(oldPasswd, newPasswd);

	if (strCmpResult == 0) {
		return 0;
	}

	return 1; 
}

// You may write additional functions below if needed.
// However every function must be preceeded with a function description.