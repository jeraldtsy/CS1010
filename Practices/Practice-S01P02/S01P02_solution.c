#include <stdio.h>
#include <math.h>

//solution
int main(void) {

	int hours, minutes;
	float temperature, timeInMinutes;  

	// Get the hours and minutes
	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hours, &minutes);

	timeInMinutes = hours + (minutes / 60.0); 
		
	temperature = ((4 * pow(timeInMinutes, 10)) / ((pow(timeInMinutes, 9)) + 2)) - 20; 
	printf("Temperature in freezer = %.2f", temperature);

	return 0;
}