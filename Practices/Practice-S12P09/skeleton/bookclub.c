#include <stdio.h>
#include <string.h>
#define MAX_MEMBER 20
#define MAX_RECORD 100
#define MAX_RESULT 1000
#define MAX_LENGTH 50

typedef struct {
	char name[MAX_LENGTH+1];
	char title[MAX_LENGTH+1];
} result_t;

void sortResults(result_t results[], int);
void printResults(result_t results[], int);

int main(void) {
	int numRes;
	result_t results[MAX_RESULT];

	sortResults(results, numRes);
		
	printf("The results of the join are as follows: \n");
	printResults(results, numRes);
	
	return 0;
}

/* Sample printf statements for readInputs()
	printf("Enter operation of members: ");
	printf("Enter members: \n");
	printf("Enter operation of records: ");
	printf("Enter records: \n");
	printf("Enter operation: ");
*/

// Sort the results first by name and then by book title
// in alphabetical order
void sortResults(result_t results[], int size){
	int i, start, index;
	result_t temp;
  
	for (start = 0; start < size-1; start++) {
		index = start;
		for (i = start+1; i < size; i++)
			if (strcmp(results[i].name, results[index].name) < 0 || 
				(strcmp(results[i].name, results[index].name) == 0 
					&& strcmp(results[i].title, results[index].title) < 0))
				index = i;

		temp = results[start];
		results[start] = results[index];
		results[index] = temp;
	}
}

void printResults(result_t results[], int size){
	int i;
	
	for (i = 0; i < size; i++){
		printf("%s %s\n", results[i].name, results[i].title);
	}
}