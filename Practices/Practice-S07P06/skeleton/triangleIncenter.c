// triangleIncenter.c
// This program computes the incenter of a triangle
// given the coordinates of three vertices.
#include <stdio.h>

int main(void) {
	float x1, y1,    // coordinates of 1st vertex
				x2, y2,    // coordinates of 2nd vertex
				x3, y3,    // coordinates of 3rd vertex
				xIn, yIn;  // coordinates of incenter

	printf("Coordinates of 1st vertex: ");
	scanf("%f %f", &x1, &y1);
	printf("Coordinates of 2nd vertex: ");
	scanf("%f %f", &x2, &y2);
	printf("Coordinates of 3rd vertex: ");
	scanf("%f %f", &x3, &y3);

	printf("Coordinates of incenter = (%.2f, %.2f)\n", xIn, yIn);

	return  0;
}

