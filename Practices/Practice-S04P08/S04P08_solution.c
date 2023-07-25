// CS1010 AY2015/6 Semester 1
// PE1 Ex1: election.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description:
// Solution
#include <stdio.h>

void printSummary(float, float);

int main(void) {
	float sampleCountA = 0.0, sampleCountB = 0.0;
	float resultA, resultB; 
	int totalVoters, totalStations, stationVoters, voteA, voteB, invalidVotes; 
		
	printf("Enter number of voters in the division: ");
	scanf("%d", &totalVoters);

	printf("Enter number of stations: ");
	scanf("%d", &totalStations);

	for (int i = 1; i <= totalStations; i++) {
		printf("Enter number of voters in station %d:", i);
		scanf("%d", &stationVoters);

		printf("Enter number of votes for Team A: ");
		scanf("%d", &voteA);
		printf("Enter number of votes for Team B: ");
		scanf("%d", &voteB);
		invalidVotes = 100 - voteA - voteB; 
		
		sampleCountA += (float)voteA / (100 - invalidVotes) * (float)stationVoters / totalVoters;
		sampleCountB += (float)voteB / (100 - invalidVotes) * (float)stationVoters / totalVoters;
	}

	resultA = sampleCountA * 100; 
	resultB = sampleCountB * 100; 
	

	printf("Sample count for Team A = %.2f%%\n", resultA);
	printf("Sample count for Team B = %.2f%%\n", resultB);

	printSummary(resultA, resultB);

	return 0;
}

void printSummary(float resultA, float resultB) {
	
	if (resultA > resultB) {
		if ((resultA - resultB) < 5) {
			printf("Team A narrowly wins this election.\n");
		}
		else if (((resultA - resultB) >= 5) && ((resultA - resultB) <= 30)) {
			printf("Team A wins by a significant margin.\n");
		}
		else {
			printf("Team A wins by a landslide.\n");
		}
	}
	else if (resultB > resultA){
		if ((resultB - resultA) < 5) {
			printf("Team B narrowly wins this election.\n");
		}
		else if (((resultB - resultA) >= 5) && ((resultB - resultA) <= 30)) {
			printf("Team B wins by a significant margin.\n");
		}
		else {
			printf("Team B wins by a landslide.\n");
		}
	}
	else {
		printf("There is no winner in this election.\n");
	}
}