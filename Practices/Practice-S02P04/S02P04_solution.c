// TaxiFare.c
// This program computes taxi fare.
// Solution
#include <stdio.h>
#define INCREMENT 0.22

float computeFare(int, int, int);

int main(void) {
	int dayType;			 // 0 = weekends and public holidays;
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

	boardTime = (boardHour * 60) + boardMin; 
	printf("Boarding time is %d minutes\n", boardTime);

	printf("Total taxi fare is $%.2f\n",
		computeFare(dayType, boardTime, distance));

	return 0;
}

// Compute taxi fare based on
//   type: 0 = weekends and PH; 1 = weekdays
//   time: time passenger boarded taxi (in minutes from 0:00hr)
//   dist: distance of journey
float computeFare(int type, int time, int dist) {
	float ans = 3.40; 
	dist = dist - 1000; 

	
	if ((dist > 0) && (dist <= 9200)){
		if ((dist % 400) != 0) {
			ans += ((dist / 400) + 1) * INCREMENT;
		}
		else {
			ans += (dist / 400) * INCREMENT;
		}

		dist = 0;
	}
	else if (dist > 9200) {
		ans += (9200 / 400) * INCREMENT; 
		dist -= 9200; 
	}
	
	if (dist > 0) {
		if ((dist % 350) != 0) {
			ans += ((dist / 350) + 1) * INCREMENT; 
		}
		else {
			ans += (dist / 350) * INCREMENT; 
		}	
	}
	
	time /= 60; 
	if (type == 0) {
		if ((time >= 0) && (time <= 6)) {
			ans += (ans / 2);
		}
		
		if ((time >= 18) && (time <= 24)) {
			ans += (ans / 4);
		}
	}

	else {
		if ((time >= 0) && (time <= 6)) {
			ans += (ans / 2);
		}
		if ((time >= 6) && (time <= 9.5)) {
			ans += (ans / 4);
		}
		if ((time >= 18) && (time <= 24)) {
			ans += (ans / 4);
		}
	}

	return ans;
}