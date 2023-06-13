#include <stdio.h>
#include <math.h>

//Solution
int main(void) {
	int principal, rate, numYears;
	float amount; 

	printf("Enter principal amount: ");
	scanf("%d", &principal);

	printf("Enter interest rate   : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &numYears);

	amount = (principal * (1 - pow(rate / 100.0, numYears + 1))) / (1 - (rate / 100.0));

	printf("Amount = $%.2f", amount);
	
	return 0;
}