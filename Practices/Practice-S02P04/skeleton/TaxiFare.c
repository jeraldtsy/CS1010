// TaxiFare.c
// This program computes taxi fare.
#include <stdio.h>
#define INCREMENT 0.22

float computeFare(int, int, int);

int main(void) {    
	int dayType; // 0 = weekends and public holidays;
	             // 1 = weekdays and non public holidays
	int boardHour, boardMin; // hour and minute of boarding
	int boardTime;           // converted from boardHour and boardMin
	int distance;            // distance of journey

	printf("Day type: ");
	scanf("%d", &dayType);
	printf("Boarding hour and minute: ");
	scanf("%d %d", &boardHour, &boardMin);
	printf("Distance: ");
	scanf("%d", &distance);

	// complete the next line
	// boardTime = ... 
	printf("Boarding time is %d minutes\n", boardTime);

	printf("Total taxi fare is $%.2f\n", 
	       computeFare(dayType, boardTime, distance));

	return 0;
}

// Compute taxi fare based on
//   type: 0 = weekends and PH; 1 = weekdays
//   time: time passenger boarded taxi (in minutes from 0:00hr)
//   dist: distance of journey
// This function is called a stub as it returns a dummy value
float computeFare(int type, int time, int dist) {

	return 1.23;  
}

