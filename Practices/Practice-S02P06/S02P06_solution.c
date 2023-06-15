// DaysSince1Jan2017.c
// This program reads the day and month of 2017 and computes
// the number of days since 1st January 2017.
// Solution
#include <stdio.h>
#include <string.h>

int computeDays(int, int);

int main(void) {
	int day, month, ans;
	char suffix[2]; 

	printf("Enter day and month: ");
	scanf("%d %d", &day, &month);
	
	ans = computeDays(day, month);
	
	printf("Day %d of month %d is the %d day of 2017.", day, month, ans);
	
	return 0;
}

// This function computes the number of days that have elapsed 
// for the given day and month since 1st January 2017.
int computeDays(int day, int mth) {
	int ans = 0; 

	switch (mth) {
	case 2: ans = 31; 
		break;
	case 3: ans = 59;
		break;
	case 4: ans = 90;
		break;
	case 5: ans = 120; 
		break; 
	case 6: ans = 151; 
		break;
	case 7: ans = 181; 
		break;
	case 8: ans = 212; 
		break; 
	case 9: ans = 243; 
		break; 
	case 10: ans = 273; 
		break;
	case 11: ans = 304; 
		break; 
	case 12: ans = 334; 
	}
	
	ans += day; 

	return ans; 
}
