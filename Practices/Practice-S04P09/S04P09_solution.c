// CS1010 AY2015/6 Semester 1
// PE1 Ex2: amicable.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
// Solution 

#include <stdio.h>

void countPairs(int lower, int upper, int results[]);
int sumFactors(int number);

// Do NOT change the main function at all!
int main(void) {
	int lower, upper, results[2] = { 0 };

	printf("Enter range: ");
	scanf("%d %d", &lower, &upper);

	countPairs(lower, upper, results);

	printf("Number of full pairs: %d\n", results[0]);
	printf("Number of half pairs: %d\n", results[1]);

	return 0;
}

void countPairs(int lower, int upper, int results[]) {
	// Remember to assign the calculated number of full pairs to results[0],
	// and the calculated number of half pairs to results[1]
	int fullPairs = 0; 
	int halfPairs = 0; 
	int sum;
	
	for (int i = lower; i <= upper; i++) {
		sum = sumFactors(i); //284

		if ((sumFactors(sum) == i) && ((sum != i))) {
			if ((sum <= upper) && (sum >= lower)) {
				if (i < sum) {
					fullPairs++;
				}
			}
			else if ((sum < lower) || (sum > upper)) {
				halfPairs++;				
			}
		}
	}

	results[0] = fullPairs;
	results[1] = halfPairs;
}

int sumFactors(int number) {
	int sum = 0; 

	for (int i = 1; i <= (number / 2); i++) {
		if ((number % i) == 0) {
			sum += i; 
		}
	}
	
	return sum;
}

// Remove extra comments (including this one) after you have completed the program