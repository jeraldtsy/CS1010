// health_screen.c
#include <stdio.h>

#define MAX_READINGS 50   // maximum number of readings

typedef struct {
	float score; // the health score
	int   freq;  // how many people with that score
} reading_t;

void printReadings(reading_t [], int);

int main(void) {
	reading_t readings[MAX_READINGS];  
	int size = 0;

	printf("Enter score and frequency (end with 0 0):\n");

	// printReadings(readings, size); // for checking

	return 0;
}

// Print array arr
void printReadings(reading_t arr[], int size) {
	int i;

	for (i=0; i<size; i++) 
		printf("%f %d\n", arr[i].score, arr[i].freq);
}

