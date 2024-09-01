// Solution
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

void print_intervals(interval_t [], int);
int computeLongest(interval_t [], int);
int computeConcurrent(interval_t [], int);
int computeFreeLessons(interval_t[], int);

int main(void) {
	int n; // number of intervals
	interval_t intervals[MAX_INTERVALS];
    int longestLesson;
    int conCurrent;
    int freePeriods;

	printf("Enter number of intervals: ");
	scanf("%d", &n);

    printf("Enter %d intervals:\n", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &intervals[i].start);
        scanf("%d", &intervals[i].finish);
    }

    longestLesson = computeLongest(intervals, n);
    freePeriods = computeFreeLessons(intervals, n);
    conCurrent = computeConcurrent(intervals, n);

    printf("Duration of longest lesson = %d\n", longestLesson);
    printf("Number of free periods = %d\n", freePeriods);
    printf("Most number of concurrent lessons = %d\n", conCurrent);

	return 0;
}


int computeLongest(interval_t intervals[], int size) {
    int ans = 0;

    for (int i = 0; i < size; i++) {
        if ((intervals[i].finish - intervals[i].start) > ans) {
            ans = (intervals[i].finish - intervals[i].start);
        }
    }

    return ans;
}

int computeFreeLessons(interval_t intervals[], int size) {
    int start = LATEST_FINISH;
    int finish = 0;
    int count = 0;
    int endLastInterval;
    int tempStart, tempFinish;

    for (int i = 0; i < size; i++) {
        if (intervals[i].start < start) {
            start = intervals[i].start;
        }
        if (intervals[i].finish > finish) {
            finish = intervals[i].finish;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = (i+1); j < size; j++) {
            if (intervals[i].start > intervals[j].start) {
                tempStart = intervals[i].start;
                tempFinish = intervals[i].finish;
                intervals[i].start = intervals[j].start;
                intervals[i].finish = intervals[j].finish;
                intervals[j].start = tempStart;
                intervals[j].finish = tempFinish;
            }
        }
    }
    
    endLastInterval = intervals[0].finish;

    for (int i = 1; i < size; i++) {
        if (intervals[i].start > endLastInterval) {
            count++;
        }
        if (intervals[i].finish > endLastInterval) {
            endLastInterval = intervals[i].finish;
        }

    }

    return count;
}

int computeConcurrent(interval_t intervals[], int size) {
    int ans = 1;
    int isCounted;
    int count;

    for (int i = 0; i < size; i++) {
        count = 1;
        for (int j = (i+1); j < size; j++) {
            isCounted = 0;
            if (isCounted == 0) {
                if ((intervals[j].start >= intervals[i].start) && (intervals[j].start < intervals[i].finish)) {
                    count++;
                    isCounted = 1;
                }
            }
            if (isCounted == 0) {
                if ((intervals[j].finish > intervals[i].start) && (intervals[j].finish <= intervals[i].finish)) {
                    count++;
                    isCounted = 1;
                }
            }
        }
        if (count > ans) {
            ans = count;
        }
    }
    
    return ans;
}

// Print the interval array arr
void print_intervals(interval_t intervals[], int size) {
	int i;

	for (i=0; i<size; i++) 
		printf("%d %d\n", intervals[i].start, intervals[i].finish);
}