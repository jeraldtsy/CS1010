#include <stdio.h>

//Solution
int main(void) {

	int max_slabs, trayLength, trayBreadth, slabLength, slabBreadth, temp;

	printf("Enter dimension of tray: ");
	scanf("%d %d", &trayLength, &trayBreadth);

	printf("Enter dimension of slab: ");
	scanf("%d %d", &slabLength, &slabBreadth); 

	temp = (trayLength / slabLength) * (trayBreadth / slabBreadth);
	max_slabs = temp; 

	temp = (trayLength / slabBreadth) * (trayBreadth / slabLength);
	
	if (temp > max_slabs) {
		max_slabs = temp; 
	}

	printf("Maximum number of slabs = %d\n", max_slabs);
	
	return 0;
}