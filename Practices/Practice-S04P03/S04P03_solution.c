// CS1010 AY2012/3 Semester 1
// PE1 Ex1: sat.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:
// Solution
#include <stdio.h>

float computeSAT(int, int);
void printMessage(float, int, int, int);

#define mathMagic 0.095
#define verbalMagic 0.003
#define general 50.241

int main(void) {

	int verbal, math, writing; // user's input
	float score; 

	printf("Enter scores: ");
	scanf("%d %d %d", &verbal, &math, &writing);

	score = computeSAT(verbal, math);
	printMessage(score, verbal, math, writing);

	return 0;

}

float computeSAT(int verbal, int math) {
	return ((verbal * verbalMagic) + (math * mathMagic) + general);
}

void printMessage(float score, int verbal, int math, int writing) {
	int total = verbal + math + writing; 

	if (total >= 2200) {
		printf("The SAT score is in the 99 percentile.\n");
	}
	else if ((total < 2200) && (total >= 2000)) {
		printf("The SAT score is in the 95 percentile.\n");
	}
	else if ((total < 2000) && (total >= 1500)) {
		printf("The SAT score is in the 50 percentile.\n");
	}
	else {
		printf("The SAT score is in the 10 percentile.\n");
	}

	printf("The IQ score is %.2f\n", score); 

	if ((((verbal > 600) && (math > 600) && (writing > 600)) || (score >= 120))) {
		printf("Wow, this is amazing!");
	}
}