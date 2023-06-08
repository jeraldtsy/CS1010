// triangleCentroid.c
// This program computes the centroid (G) of a triangle
// given the coordinates of three vertices.
#include <stdio.h>

void centroid(float, float, float, float, float, float, float *, float *);

int main(void) {
	float x1, y1,    // coordinates of 1st vertex
				x2, y2,    // coordinates of 2nd vertex
				x3, y3,    // coordinates of 3rd vertex
				xG, yG;    // coordinates of centroid

	printf("Coordinates of 1st vertex: ");
	printf("Coordinates of 2nd vertex: ");
	printf("Coordinates of 3rd vertex: ");

	printf("Coordinates of centroid = (%.2f, %.2f)\n");

	return  0;
}

