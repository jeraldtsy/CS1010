// Solution
// cap.c
// Read a student's results and compute his CAP.
// This is a skeleton program for students.

#include <stdio.h>
#include <string.h>
#define MAX_MODULES 50

typedef struct {
    char modCode[7];
    char grade[2];
    int modCredit;
} result_t;

typedef struct {
    char name[30];
    result_t results[50];
} student_t;

void print_results(student_t, int);
float compute_cap(student_t, int);

int main(void) {
	student_t student;
	int num_modules, i;

	printf("Enter student's name: ");
    fgets(student.name, 30, stdin);

	printf("Enter number of modules taken: ");
    scanf("%d", &num_modules);

	printf("Enter results of %d modules:\n", num_modules);
    for (int i = 0; i < num_modules; i++) {
        scanf("%s", student.results[i].modCode);
        scanf("%s", student.results[i].grade);
        scanf("%d", &student.results[i].modCredit);
    }

	// print_results(student, num_modules); // for checking

	printf("CAP = %.2f\n", compute_cap(student, num_modules));

	return 0;
}

// Print results of the student
void print_results(student_t student, int num_modules) {
	/*int i;

	printf("Student's name: %s\n", student.name);
	for (i=0; i<num_modules; i++)
		printf("  %-7s %-2s %d\n", student.results[i].module_code,
				student.results[i].grade, student.results[i].mc);
*/
}

// Compute CAP of student.
// This is a stub.
float compute_cap(student_t student, int num_modules) {
    float cap = 0; 
    float gradePoint = 0;
    float currScore = 0;
    int totalCredit = 0;
    
    for (int i = 0; i < num_modules; i++) {
        totalCredit += student.results[i].modCredit;
        
        if (((strcmp(student.results[i].grade, "A+")) == 0) || ((strcmp(student.results[i].grade, "A") == 0))) {
            gradePoint = 5;
        }
        else if ((strcmp(student.results[i].grade, "A-") == 0)) {
            gradePoint = 4.5;
        }
        else if ((strcmp(student.results[i].grade, "B+") == 0)) {
            gradePoint = 4.0;
        }
        else if ((strcmp(student.results[i].grade, "B") == 0)) {
            gradePoint = 3.5;
        }
        else if ((strcmp(student.results[i].grade, "B-") == 0)) {
            gradePoint = 3.0;
        }
        else if ((strcmp(student.results[i].grade, "C+") == 0)) {
            gradePoint = 2.5;
        }
        else if ((strcmp(student.results[i].grade, "C") == 0)) {
            gradePoint = 2.0;
        }
        else if ((strcmp(student.results[i].grade, "D+") == 0)) {
            gradePoint = 1.5;
        }
        else if ((strcmp(student.results[i].grade, "D") == 0)) {
            gradePoint = 1.0;
        }
        else {
            gradePoint = 0;
        }
        
        currScore += gradePoint * student.results[i].modCredit;
    }

    cap = (currScore / totalCredit);

	return cap;
}