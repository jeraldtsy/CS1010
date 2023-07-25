// CS1010 AY2015/6 Semester 2 PE1 Ex1
//
// line.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
// Solution

#include <stdio.h>

int determineType(int, int, int, int, int, int, int, int);
float computeK(int, int, int, int);
void printMessage(int);

int main(void) {
	int xA, yA; 
	int xB, yB; 
	int xC, yC; 
	int xD, yD;
	int type;
	
	printf("Enter the coordinates of A: ");
	scanf("%d %d", &xA, &yA);

	printf("Enter the coordinates of B: ");
	scanf("%d %d", &xB, &yB);

	printf("Enter the coordinates of C: ");
	scanf("%d %d", &xC, &yC);

	printf("Enter the coordinates of D: ");
	scanf("%d %d", &xD, &yD);

	type = determineType(xA, yA, xB, yB, xC, yC, xD, yD);
	printMessage(type);

	return 0;
}

int determineType(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD) {
	float kAB, kCD, kAC; 

	kAB = computeK(xA, yA, xB, yB);
	kCD = computeK(xC, yC, xD, yD);

	if (kAB != kCD) {
		return 1; 
	}
	else {
		kAC = computeK(xA, yA, xC, yC);

		if ((kAB == kCD) && (kAB != kAC)) {
			return 0; 
		}
		else {
			return 2; 
		}
	}
}


float computeK(int x1, int y1, int x2, int y2) {
	float k; 

	k = ((float)(y1 - y2)) / ((float)(x1 - x2));
	return k;
}


void printMessage(int type) {

	if (type == 0) {
		printf("The two lines are parallel.\n");
	}
	else if (type == 1) {
		printf("The two lines are intersecting.\n");
	}
	else {
		printf("The two lines are overlapping.\n");
	}
}
