#include <stdio.h>
#include <math.h>

//Solution
int main(void) {

	int length, width, height, surfaceArea; 
	float diagonal; 

	printf("Enter length: ");
	scanf("%d", &length); 

	printf("Enter width : ");
	scanf("%d", &width); 

	printf("Enter height: ");
	scanf("%d", &height); 

	surfaceArea = (2 * length * width) + (2 * width * height) + (2 * height * length);
	diagonal = sqrt(pow(height, 2) + pow(sqrt(pow(length, 2) + pow(width, 2)), 2));

	printf("Surface area = %d\n", surfaceArea);
	printf("Diagonal = %.2f", diagonal);

	return 0;
}