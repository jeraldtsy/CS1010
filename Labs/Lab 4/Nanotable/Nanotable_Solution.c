// Solution
/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 * <Type your program description here>
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100

/* Function prototypes */
void print_help();
int insert_table(int [], int [], int);
int calculateSum(int [], int);
float calculateAverage(int, int);
void rankScores(int [], int [], int);

int main(void) {
  
  // The string for input command, do not modify...
  char input[MAX_COMMAND_LENGTH];

  // TO BE IMPLEMENTED
  // How to represent the table and other information...
  int arrStudentID[MAX_COMMAND_LENGTH];
  int arrStudentScore[MAX_COMMAND_LENGTH];
  int size = 0;
  int sum;
  float ave;

  // print welcome information
  printf("Welcome to Nanotable!\n");
  printf("Type \"help\" for more information...\n");

  while (TRUE) {
    printf("Waiting for command...\n");
    scanf("%s", input);
		
    if (strcmp(input,"help") == 0) {
      print_help();
    } else if (strcmp(input,"exit") == 0){
      printf("See you!\n");
      break;
    } else if (strcmp(input,"sum") == 0) {
      if (size == 0) {
		printf("The table is empty\n");
      } else {
		sum = calculateSum(arrStudentScore, size);
	printf("The sum of score is %d\n", sum);
      }
    } else if (strcmp(input,"ave") == 0) {
      if (size == 0) {
	printf("The table is empty\n");
      } else {
		ave = calculateAverage(sum, size);
	printf("The average of score is %.2f\n", ave);
      }
    } else if (strcmp(input,"insert") == 0) {
      // TO BE IMPLEMENTED
	  size = insert_table(arrStudentID, arrStudentScore, size);

    } else if (strcmp(input,"init") == 0) {
      	size = 0;
		printf("Initializing table...\n");
    } else if (strcmp(input,"rank") == 0) {
      if (size == 0) {        
	printf("The table is empty\n");
      } else {
		rankScores(arrStudentID, arrStudentScore, size);
      }
    } else {
      printf("No such command: %s, please input command again!\n", input);
    }
  }
  return 0;
}

// This function prints the help information
void print_help() {
  printf("Commands available: insert, init, sum, ave, rank, help, exit\n");
}

int insert_table(int arrStudentID[], int arrStudentScore[], int size) {
	printf("Please input the student's ID...\n");
	scanf("%d", &arrStudentID[size]);

	printf("Please input the student's score...\n");
	scanf("%d", &arrStudentScore[size]);

	size++;

	return size;
}

int calculateSum(int arrStudentScore[], int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += arrStudentScore[i];
	}
	return sum;
}

float calculateAverage(int sum, int size) {
	float ave;

	ave = sum / size; 

	return ave;
}

void rankScores(int arrStudentID[], int arrStudentScore[], int size) {
	int input;
	int tempScore;
	int tempID;

	for (int i = 0; i < size; i++) {
		for (int j = (i+1); j < size; j++) {
			if (arrStudentScore[j] > arrStudentScore[i]) {
				tempScore = arrStudentScore[j];
				arrStudentScore[j] = arrStudentScore[i];
				arrStudentScore[i] = tempScore;

				tempID = arrStudentID[j];
				arrStudentID[j] = arrStudentID[i];
				arrStudentID[i] = tempID;
			}		
		}
	}

	while (TRUE) {
		printf("Please input the rank (1 - %d)...\n", size);
		scanf("%d", &input);

		if (input > size) {
			printf("Invalid rank: %d\n", input);
		}
		else {
			printf("ID : %d, Score: %d\n", arrStudentID[input - 1], arrStudentScore[input - 1]);
			break;
		}
	}
}