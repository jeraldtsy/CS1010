// schedule.c
// This program reads a schedule of lessons, and computes
// the longest lesson, the number of free periods, and the
// most number of concurrent lessons.
// This is a skeleton program for students.

#include <stdio.h>
#define MAX_INTERVALS 20
#define LATEST_FINISH 1000

typedef struct {
	int start, finish;
} interval_t;

void print_intervals(interval_t [], int) ;

int main(void) {
	int n; // number of intervals
	interval_t intervals[MAX_INTERVALS];

	printf("Enter number of intervals: ");
	scanf("%d", &n);

	return 0;
}

// Print the interval array arr
void print_intervals(interval_t intervals[], int size) {
	int i;

	for (i=0; i<size; i++) 
		printf("%d %d\n", intervals[i].start, intervals[i].finish);
}

