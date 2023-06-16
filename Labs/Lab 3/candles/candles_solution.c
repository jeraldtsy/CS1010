/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * <Fill in a description of this program>
 * <Type your name here>
 * <Type your discussion group here>
 * Solution
 */ 

#include <stdio.h>

 // Write your function prototype below (and remove this comment!)

int count_candles(int, int);

int main(void) {
	int numCandles; 
	int requiredResiduals; 
	int numBurnt; 

	printf("Enter number of candles and number of residuals to make a new candle: ");
	scanf("%d %d", &numCandles, &requiredResiduals);

	numBurnt = count_candles(numCandles, requiredResiduals);

	printf("Total candles burnt = %d\n", numBurnt);

	return 0;
}

// Add your function below (and remove this comment!)
// Every function should be preceded with a comment
// that describes what the function does.
// Also include the precondition for this function.
int count_candles(int numCandles, int requiredResiduals) {
	int numBurnt = 0; 

	while (numCandles != 0) {
		if (numCandles >= requiredResiduals) {
			numCandles = numCandles - requiredResiduals;
			numCandles += 1; 
			numBurnt += requiredResiduals;
		}
		else {
			numBurnt += numCandles; 
			numCandles = 0; 
		}
	}
	return numBurnt;
}