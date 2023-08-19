/**
 * rabbit.c
 * A rabbit can jump at most 50 centimetres. It needs to cross a
 * river, with rocks positioned in a straight line in the river.
 * The program computes the minimum number of jumps for the rabbit
 * to cross to the other side of the river.
 */
// Solution

#include <stdio.h>

int countJumps(int[], int);

int main(void) {
	int num_rocks;            // including opposite bank
	int arr[20];
	int jumps;
	
	printf("Enter number of rocks: ");
	scanf("%d", &num_rocks);

	for (int i = 0; i < num_rocks; i++) {
		scanf("%d", &arr[i]);
	}

	jumps = countJumps(arr, num_rocks);
	printf("%d\n", jumps);

	return 0;
}

// Counts the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
// Precond: size > 0
int countJumps(int rocks[], int size) {
	int jumps = 0; 
	int curr = 0; 

	for (int i = 0; i < size; i++) {
		 
		if ((rocks[i] - curr > (curr +50))) {		
			return -1; 
		}


		if ((rocks[i + 1] - rocks[i] > 50)) {
			return -1; 
		} 

		if (rocks[i + 1] == (curr + 50)) {
			jumps++;
			curr = rocks[i+1];
		}
		else if (rocks[i+1] > (curr + 50)) {
			jumps++; 
			curr = rocks[i];			
		}
		
	}

	if (curr == rocks[size - 1]) {
		return jumps; 
	}

	return (jumps+1); // this is just a stub; replace it with the correct value
}