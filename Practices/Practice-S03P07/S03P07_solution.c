// multiples5or7.c 
// Reads a positive integer num and count the number
// of multiples of 5 or 7 in the range [1, num].
// Solution

#include <stdio.h>

int count_multiples(int);

int main(void) {
	int num;

	printf("Enter positive integer: ");
	scanf("%d", &num);
	
	printf("There are %d multiples of 5 or 7 in [1, %d].", count_multiples(num), num);

	return 0;
}

// Precond: value > 0
int count_multiples(int value) {
    int isMultiple = 0; 
    
    for (int i = 1; i <= value; i++) {
        if ((i % 5) == 0) {
            isMultiple++;
        }
        
        else if ((i % 7) == 0) {
            isMultiple++;
        }
    }
    
    return isMultiple; 
}