// Solution
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

int checkEmail (char []);

int main(void){
	char email[MAX_LENGTH];
	int isValid = 0; 

	printf("Enter email address: ");
	scanf("%s", email);
	
    isValid = checkEmail(email);

    if (isValid == 0) {
        printf("This email address is not valid.\n");
    }

    else if (isValid == 1) {
        printf("This email address is valid but not friendly.\n");
    }
    else {
	    printf("This email address is valid and friendly.\n");
    }

	return 0;
}

int checkEmail(char email[]) {
    char local[MAX_LENGTH] = "";
    char domain[MAX_LENGTH] = "";
    int index = 0, domainIndex = 0, length, pos = 0, count = 0;
    int isValid = 1;
    int isFriendly = 1; 

    while (email[index] != '@') {
        local[index] += email[index];
        index++;
    }

    index++;

    while (email[index] != '\0') {
        domain[domainIndex] += email[index];
        domainIndex++;
        index++;
    }

    length = strlen(local);

    for (int i = 0; i < length; i++) {
        if ((!(isalnum(local[i])) && (local[i] != '.'))) {
            return 0;
        }
    }

    if ((length <3) || (length >21)) {
        isValid = 0;
        return 0;
    }

    if ((isalpha(local[0]) == 0)) {
        isValid = 0;
        return 0;
    }

    if ((strcmp(domain, "u.nus.edu")) != 0){
        isValid = 0;
        return 0;
    }

    index = 0;

    while (local[index] != '\0') {
        if (isdigit(local[index])) {
            pos = index;
            while (isdigit(local[pos])) {
                count++;
                pos++;
            }
            if (count == 7) {
                isFriendly = 0;
            }
            index = pos;
        }

        index++;
    }
    

    if ((isValid == 1) && (isFriendly == 0)) {
        return 1;
    }
    else if ((isValid == 1) && (isFriendly == 1)){
        return 2;
    }

    return 0;
}