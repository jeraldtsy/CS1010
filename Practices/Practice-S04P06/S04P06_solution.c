// CS1010 AY2014/5 Semester 1
// PE1 Ex1: parking.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description:
// Solution
#include <stdio.h>
#include <math.h>

double computeFee(int, int, int);

int main(void) {
	int day, timeIn, timeOut;
	double fee;

	printf("Enter day: ");
	scanf("%d", &day);

	printf("Enter time-in: ");
	scanf("%d", &timeIn);

	printf("Enter time-out: ");
	scanf("%d", &timeOut);

	fee = computeFee(day, timeIn, timeOut);
	printf("Parking fee is $%.2f.\n", fee);

	return 0;
}

double computeFee(int day, int timeIn, int timeOut) {
	float fee = 0; 
	int hours, mins;
	int tempHours, tempMins; 

	hours = (timeOut - timeIn) / 100; 
	mins = (timeOut - timeIn) % 100;
	
	//check for grace period
	if ((hours == 0) && (mins <= 10)) {
		return fee; 
	}

	//check day
	if (day == 7) {
		fee = 5; 
	}

	else if (day == 6) {
		if (timeOut <= 700) {
			fee += hours * 2.5;
		}
		else if ((timeIn <= 700) && (timeOut >= 700)) {
			tempHours = (700 - timeIn) / 100.0;
			fee += tempHours * 2.5;

			if (((tempHours * 2.5) != 7.5) && (mins != 0)) {
				fee += 2.5;
			}

			timeIn = 700;
		}
	
		hours = (timeOut - timeIn) / 100.0;
		mins = (timeOut - timeIn) % 100;


		if (timeOut > 1800) {
			tempHours = (1800 - timeIn) / 100.0;
			tempMins = (1800 - timeIn) % 100; 
			
			fee += tempHours * (2 * 1.5);
			if ((tempMins <= 30) && (tempMins != 0)) {
				fee += 1.5; 
			}
			else if (tempMins > 30) {
				fee += 3; 
			}
		}

		else if (timeOut <= 1800) {
			tempHours = (timeOut - timeIn) / 100.0; 
			tempMins = (timeOut - timeIn) % 100;

			fee += tempHours * 3; 

			if ((tempMins <= 30)) {
				fee += tempHours + 1.5; 
			}
			else if (tempMins > 30) {
				fee += tempHours + 3; 
			}
			timeIn = 1800; 
		}

		if (timeOut >= 1800) {
			fee += 7; 
		}

		if (hours >= 10) {
			fee *= 1.2; 
		}
	}
	else {
		if (timeOut <= 700) {
			fee += hours * 2;
		}
		else if ((timeIn <= 700) && (timeOut >= 700)) {
			tempHours = (700 - timeIn) / 100.0;
			fee += tempHours * 2;

			if (((tempHours * 2) != 6) && (mins != 0)) {
				fee += 2;
			}

			timeIn = 700;
		}

		hours = (timeOut - timeIn) / 100.0;
		mins = (timeOut - timeIn) % 100;

		//case 1: comes in after 7 and leaves before 6pm
		//case 2: comes in after 7 and leaves after 6pm 
		if (timeOut > 1800) {
			tempHours = (1800 - timeIn) / 100.0;
			tempMins = (1800 - timeIn) % 100;

			fee += tempHours * (2 * 1.2);

			if ((tempMins <= 30) && (tempMins != 0)) {
				fee += 1.2;
			}
			else if (tempMins > 30) {
				fee += 2.4;
			}
		}

		else if (timeOut <= 1800) {
			tempHours = (timeOut - timeIn) / 100.0;
			tempMins = (timeOut - timeIn) % 100;

			fee += tempHours * 2.4;

			if ((tempMins <= 30)) {
				fee += tempHours + 1.2;
			}
			else if (tempMins > 30) {
				fee += tempHours + 2.4;
			}
			timeIn = 1800;
		}

		if (timeOut >= 1800) {
			fee += 5;
		}

		if (hours >= 10) {
			fee *= 1.1;
		}
	}

	if (timeOut >= 2200) {
		fee += 3; 
	}

	return fee; 
}