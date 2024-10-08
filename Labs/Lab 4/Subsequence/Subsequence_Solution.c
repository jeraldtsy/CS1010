// Solution
/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex2
 * subsequence.c
 * This program reads in a list of integers and find the
 * k-interval subsequence with the largest sum.
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#include <limits.h>

int scan_list(int[]);
void sum_subsequence(int[], int, int[]);

int main(void) {
	int list[10], size; // array and actual number of elements entered
	int answers[3];     // stores the required answers

	size = scan_list(list);

	sum_subsequence(list, size, answers);

	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
		answers[0], answers[1], answers[2]);

	return 0;
}

// Read in elements for the array arr and returns the 
// number of elements read.
// Postcond: i > 0
int scan_list(int arr[]) {
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num > 1) ? "s" : "");
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	return num;
}

// Write a description for this function below
// ...
// ...
//   ans[0] = maximum sum of solution subsequence
//   ans[1] = interval k of the solution subsequence
//   ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[]) {

	int greatestSum = INT_MIN, ansInterval = 10;
	int currentSum, startPos = 0;

	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < i; j++) {
			currentSum = 0;
			for (int k = j; k < size; k+= i) {
				currentSum += arr[k];
			}

			if (currentSum > greatestSum) {
				greatestSum = currentSum;
				ansInterval = i;
				startPos = j;
				
			}
			else if (currentSum >= greatestSum) {
				if (i < ansInterval) {
					ansInterval = i;
					startPos = j;
				}
			}
		}
	}

	ans[0] = greatestSum;
	ans[1] = ansInterval;
	ans[2] = startPos;

}