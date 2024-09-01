// Solution
// points.c
// Read points data and find the area of the smallest
// circle that encloses all the points.
// This is a skeleton program for students.

#include <stdio.h>
#include <math.h>
#define MAX_POINTS 10
#define PI 3.14159

typedef struct {
	int x;
	int y;
} point_t;

int read_points(point_t[]);
void print_points(point_t[], int);
float circle_area(point_t[], int);

int main(void) {
	point_t points[MAX_POINTS];
	int size;

	size = read_points(points);
	
	printf("Area of smallest circle = %.2f\n",
		circle_area(points, size));

	return 0;
}

// Read input data
// Return the number of points read
int read_points(point_t points[]) {
	int size; 

	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		scanf("%d", &points[i].x);
		scanf("%d", &points[i].y);
	}

	return size;
}

// Print points data
void print_points(point_t points[], int size) {
	int i;

	for (i = 0; i < size; i++)
		printf("(%d, %d)\n", points[i].x, points[i].y);
}

// Compute area of the smallest circle that encloses
// all the points.
// This is a stub.
float circle_area(point_t points[], int size) {
	int greatestX = 0; 
	int greatestY = 0;
	int indexX, indexY;
	float radius;

	for (int i = 0; i < size; i++) {
		if (abs(points[i].x) > greatestX) {
			greatestX = abs(points[i].x);
			indexX = i;
		}

		if (abs(points[i].y) > greatestY) {
			greatestY = abs(points[i].y);
			indexY = i;
		}
	}

	if (greatestX >= greatestY) {
		radius = sqrt(((points[indexX].x) * (points[indexX].x)) + ((points[indexX].y) * (points[indexX].y)));
	}
	else {
		radius = sqrt(((points[indexY].x) * (points[indexY].x)) + ((points[indexY].y) * (points[indexY].y)));
	}
	return PI * radius * radius;
}