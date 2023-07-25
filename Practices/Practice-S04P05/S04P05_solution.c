// CS1010 AY2013/4 Semester 1
// PE1 Ex1: tray.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description:
// Solution 
#include <stdio.h>

int min_unused_area(int, int, int, int);
float min_perimeter(int, int);

int main(void) {
	int trayHeight, trayWidth, slabHeight, slabWidth;
	int minArea; 
	float minPeri; 

	printf("Enter size of tray: ");
	scanf("%d %d", &trayWidth, &trayHeight);

	printf("Enter size of slab: ");
	scanf("%d %d", &slabWidth, &slabHeight);

	minArea = min_unused_area(trayWidth, trayHeight, slabWidth, slabHeight);
	printf("Minimum unused area = %d\n", minArea); 

	minPeri = min_perimeter(trayWidth, trayHeight);
	printf("Minimum perimeter after folding = %.2f\n", minPeri); // incomplete

	return 0;
}

int min_unused_area(int trayWidth, int trayHeight, int slabWidth, int slabHeight) {
	int unusedArea, trayArea, tempArea, slabArea;

	trayArea = trayWidth * trayHeight;
	slabArea = slabWidth * slabHeight; 

	tempArea = slabArea * (trayWidth / slabWidth) * (trayHeight / slabHeight);
	unusedArea = trayArea - tempArea; 

	tempArea = slabArea * (trayWidth / slabHeight) * (trayHeight / slabWidth);

	if ((trayArea - tempArea) > unusedArea) {
		return unusedArea; 
	}
	else {
		unusedArea = trayArea - tempArea; 
		return unusedArea; 
	}
}

float min_perimeter(int trayWidth, int trayHeight) {
	float perimeter, length, breadth; 

	length = trayWidth; 
	breadth = trayHeight; 

	for (int i = 0; i < 3; i++) {
		if (length > breadth) {
			length /= 2; 
		}
		else {
			breadth /= 2; 
		}
	}

	perimeter = (2 * length) + (2 * breadth);

	return perimeter; 
}