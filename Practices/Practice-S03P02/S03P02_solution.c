// validate.c
// To read age from user, until the 
// age entered is valid (1 - 100).
// Solution
#include <stdio.h>

int main(void) {
	int age;
	int attempt = 1; 

	printf("Enter age:");
	scanf("%d", &age);

	while ((age < 1) || (age > 100)) {
		printf("Enter age:");
		scanf("%d", &age);

		attempt++;
	}

	printf("Your age is %d.\n", age);
	printf("Number of attempts = %d\n", attempt);

	return 0;
}
