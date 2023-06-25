// check_order.c 
// Repeatedly reads positive integer, until the input value 
// is zero, or the data are not in increasing order.
// Solution

#include <stdio.h>

int main(void) {
	int num;
	int temp = 0;
	int isFalse = 0;

	printf("Enter positive integer: ");
	scanf("%d", &num);

	while (num != 0) {

		if (temp >= num) {
			printf("Data are not in increasing order.\n");
			isFalse = 1; 
			break;
		}
		else {
			temp = num;
			printf("Enter positive integer: ");
			scanf("%d", &num);

		}
	}

	if (isFalse == 0) {
		printf("Data are in increasing order.\n");
	}

	return 0;
}