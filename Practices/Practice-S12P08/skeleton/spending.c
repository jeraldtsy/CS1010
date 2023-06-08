#include <stdio.h>
#include <string.h>
#define MAX_CUSTOMER 20
#define MAX_RECORD 100
#define MAX_LENGTH 50

typedef struct {
	int id;
	char name[MAX_LENGTH+1];
} customer_t;

typedef struct {
	int cusID;
	char category[MAX_LENGTH+1];
	int spending;
} record_t;

void printRecords(record_t records[], int);

int main(void) {
	printf("The records for are as follows: \n"); // Incomplete
	printf("No record can be found for .\n"); // Incomplete

	return 0;
}

/* Sample printf statements for readInputs
	printf("Enter number of customers: ");
	printf("Enter customers: \n");
	printf("Enter number of records: ");
	printf("Enter records: \n");
	printf("Enter name: ");
*/

void printRecords(record_t records[], int size){
	int i;
	
	for (i = 0; i < size; i++)
		printf("%s %d\n", records[i].category, records[i].spending);
}