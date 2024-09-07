// Solution

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

typedef struct {
	int id;
	char name[MAX_LENGTH + 1];
} member_t;

typedef struct {
	int memID;
	char title[MAX_LENGTH + 1];
} record_t;

void sortResults(result_t results[], int);
void printResults(result_t results[], int);
void readInputs(member_t members[], record_t records[], result_t results[]);
void innerJoin(member_t members[], record_t records[], result_t results[], int, int);
void leftJoin(member_t members[], record_t records[], result_t results[], int, int);

int main(void) {
	int numRes;
	result_t results[MAX_RESULT];
	member_t members[MAX_MEMBER];
	record_t records[MAX_RECORD];
	readInputs(members, records, results);
	sortResults(results, numRes);
		
	printf("The results of the join are as follows: \n");
	printResults(results, numRes);
	
	return 0;
}

void readInputs(member_t members[], record_t records[], result_t results[]) {
	int numMembers, numRecords, operation;

	printf("Enter number of members: ");
	scanf("%d", &numMembers);

	printf("Enter members: \n");
	for (int i = 0; i < numMembers; i++) {
		scanf("%d %s", &members[i].id, &members[i].name);
	}

	printf("Enter number of records:");
	scanf("%d", &numRecords);

	printf("Enter records: \n");
	for (int i = 0; i < numRecords; i++) {
		scanf("%d %s", &records[i].memID, &records[i].title);
	}
	printf("Enter operation: ");
	scanf("%d", &operation);

	if (operation == 1) {
		innerJoin(members, records, results, numMembers, numRecords);
	}
	else {
		leftJoin(members, records, results, numMembers, numRecords);
	}

}

void innerJoin(member_t members[], record_t records[], result_t results[], int numMembers, int numRecords) {
	char searchName[MAX_LENGTH + 1];
	int searchID;
	int index = 0;

	for (int i = 0; i < numMembers; i++) {
		searchID = members[i].id;

		for (int j = 0; j < numRecords; j++) {
			if (searchID == records[j].memID) {
				strcpy(results[index].name, members[i].name);
				strcpy(results[index].title, records[j].title);
				index++;
			}
		}
	}
	sortResults(results, index);

	printf("The results of the join are as follows:\n");
	printResults(results, index);

}

void leftJoin(member_t members[], record_t records[], result_t results[], int numMembers, int numRecords) {
	char searchName[MAX_LENGTH + 1];
	int searchID;
	int index = 0;
	int flag;

	for (int i = 0; i < numMembers; i++) {
		searchID = members[i].id;
		flag = 0;
		for (int j = 0; j < numRecords; j++) {
			for (int k = 0; k < numRecords; k++) {
				if (searchID == records[k].memID) {
					flag = 1;
					break;
				}
			}
			if ((flag == 1) && (searchID == records[j].memID)) {
				strcpy(results[index].name, members[i].name);
				strcpy(results[index].title, records[j].title);
				index++;
			}
		}
		if (flag == 0) {
			strcpy(results[index].name, members[i].name);
			strcpy(results[index].title, "***");
			index++;
		}
	}

	sortResults(results, index);

	printf("The results of the join are as follows:\n");
	printResults(results, index);
}
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