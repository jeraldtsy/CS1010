// health_screen.c
#include <stdio.h>

#define MAX_READINGS 50   // maximum number of readings

typedef struct {
	float score; // the health score
	int   freq;  // how many people with that score
} reading_t;

void printReadings(reading_t [], int);
int checkReadings(reading_t [], int);

int main(void) {
	reading_t readings[MAX_READINGS];  
	int size = 0;
    int ans, freqScan;
    float scoreScan;

	printf("Enter score and frequency (end with 0 0):\n");
    scanf("%f", &scoreScan);
    scanf("%d", &freqScan);

    while ((freqScan != 0) && (scoreScan != 0)) {
        if (size == MAX_READINGS) {
            break;
        }
        readings[size].score = scoreScan;
        readings[size].freq = freqScan;

        scanf("%f", &scoreScan);
        scanf("%d", &freqScan);
        size++;
    }

	//printReadings(readings, size); // for checking
    ans = checkReadings(readings, size);

    printf("Number of unique readings = %d\n", ans);

	return 0;
}

// Print array arr
void printReadings(reading_t arr[], int size) {
	int i;

	for (i=0; i<size; i++) 
		printf("%f %d\n", arr[i].score, arr[i].freq);
}

int checkReadings(reading_t arr[], int size) {
    int count = 0;
    int isUnique;

    for (int i = 0; i < size; i++) {
        isUnique = 1;
        for (int j = (i+1); j < size; j++) {
            if (arr[i].score == arr[j].score){
                isUnique = 0;
                break;
            }
        }

        if (isUnique == 1) {
            count++;
        }
    }

    return count; 
}