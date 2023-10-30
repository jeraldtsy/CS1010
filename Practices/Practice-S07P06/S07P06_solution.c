// triangleIncenter.c
// This program computes the incenter of a triangle
// given the coordinates of three vertices.
// Solution
#include <stdio.h>
#include <math.h>

void calculateIncenter(float, float, float, float, float, float, float *, float *);

int main(void) {
	float x1, y1;   // coordinates of 1st vertex
	float x2, y2;    // coordinates of 2nd vertex
	float x3, y3;   // coordinates of 3rd vertex
	float xIn, yIn;  // coordinates of incenter


	printf("Coordinates of 1st vertex: ");
	scanf("%f %f", &x1, &y1);
	printf("Coordinates of 2nd vertex: ");
	scanf("%f %f", &x2, &y2);
	printf("Coordinates of 3rd vertex: ");
	scanf("%f %f", &x3, &y3);

	calculateIncenter(x1, y1, x2, y2, x3, y3, &xIn, &yIn);

	printf("Coordinates of incenter = (%.2f, %.2f)\n", xIn, yIn);

	return 0;
}

void calculateIncenter(float x1, float y1, float x2, float y2, float x3, float y3, float* xIn, float* yIn) {
	float distA;
	float distB;
	float distC;

	distA = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	distB = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	distC = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));

	*xIn = ((distB * x1) + (distC * x2) + (distA * x3)) / (distA + distB + distC);
	*yIn = ((distB * y1) + (distC * y2) + (distA * y3)) / (distA + distB + distC);
}