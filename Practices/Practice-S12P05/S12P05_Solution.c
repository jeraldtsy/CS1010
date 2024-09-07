// Solution
// prize.c
#include <stdio.h>
#define MAX_SIZE 300

typedef struct {
	int id; // The student number
	int scores[MAX_SIZE]; // The test scores of the student
	int prize; // Whether the student has received a prize
} student_t;

void printSequence(student_t [], int, int);

int main(void){
	int numStudents;
	int numWeeks;
	student_t student[MAX_SIZE];

	printf("Enter number of students:");
	scanf("%d", &numStudents);

	printf("Enter number of weeks:");
	scanf("%d", &numWeeks);

	printf("Enter scores:\n");

	for (int i = 0; i < numStudents; i++) {
		student[i].id = numStudents + 1;
		student[i].prize = 0;
		for (int j = 0; j < numWeeks; j++) {
			scanf("%d", &student[i].scores[j]);
		}
	}

	printSequence(student, numStudents, numWeeks);

	return 0;
}

void printSequence(student_t student[], int numStudents, int numWeeks) {
	int greatest;
	int index;

	printf("The prize sequence is:\n");

	for (int i = 0; i < numWeeks; i++) {
		greatest = -1;
		index = -1;
		for (int j = 0; j < numStudents; j++) {
			if (student[j].prize == 0) {
				if (student[j].scores[i] > greatest) {
					greatest = student[j].scores[i];
					index = j;
				}
			}
		}
		printf("%d ", (index + 1));
		student[index].prize = 1;
	}
	printf("\n");
}