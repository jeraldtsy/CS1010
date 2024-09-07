// Solution

#include <stdio.h>
#include <string.h>
#define MAX_CUSTOMER 20
#define MAX_RECORD 100
#define MAX_LENGTH 50

typedef struct {
	int id;
	char name[MAX_LENGTH + 1];
} customer_t;

typedef struct {
	int cusID;
	char category[MAX_LENGTH + 1];
	int spending;
} record_t;

typedef struct {
	char category[MAX_LENGTH + 1];
	int spending;
} customerSearch_t;

void printRecords(record_t records[], int);
void readInputs(customer_t customers[], record_t record[], customerSearch_t customerSearch[]);
void findRecords(customer_t customers[], record_t record[], customerSearch_t customerSearch[], int, int, char[]);
void sortRecords(customerSearch_t customerSearch[], int);

int main(void) {
	customer_t customers[MAX_CUSTOMER];
	record_t record[MAX_RECORD];
	customerSearch_t customerSearch[MAX_RECORD];

	readInputs(customers, record, customerSearch);

	return 0;
}

void readInputs(customer_t customers[], record_t record[], customerSearch_t customerSearch[]) {
	int numCustomers, numRecords, searchID = -1;
	char searchName[MAX_LENGTH + 1];

	printf("Enter number of customers: ");
	scanf("%d", &numCustomers);

	printf("Enter customers:\n");

	for (int i = 0; i < numCustomers; i++) {
		scanf("%d", &customers[i].id);
		scanf("%s", &customers[i].name);
	}

	printf("Enter number of records: ");
	scanf("%d", &numRecords);

	printf("Enter records: \n");
	for (int i = 0; i < numRecords; i++) {
		scanf("%d", &record[i].cusID);
		scanf("%s", &record[i].category);
		scanf("%d", &record[i].spending);
	}

	printf("Enter name: ");
	scanf("%s", &searchName);

	for (int i = 0; i < numCustomers; i++) {
		if ((strcmp(searchName, customers[i].name) == 0)) {
			searchID = customers[i].id;
		}
	}
	
	findRecords(customers, record, customerSearch, numRecords, searchID, searchName);
}

void findRecords(customer_t customers[], record_t record[], customerSearch_t customerSearch[], int numRecords, int searchID, char searchName[]) {
	int index = 0;

	for (int i = 0; i < numRecords; i++) {
		if (searchID == record[i].cusID) {
			strcpy(customerSearch[index].category, record[i].category);
			customerSearch[index].spending = record[i].spending;
			index++;
		}
	}

	if ((searchID == -1) || index == 0) {
		printf("No record can be found for %s.", searchName);
	}
	else {
		printf("The records for %s are as follows:\n", searchName);
		sortRecords(customerSearch, index);
		printRecords(customerSearch, index);
	}
}

void sortRecords(customerSearch_t customerSearch[], int size) {
	int tempSpending;
	char tempCategory[MAX_LENGTH + 1];

	for (int i = 0; i < size; i++) {
		for (int j = (i + 1); j < size; j++) {
			if (customerSearch[j].spending > customerSearch[i].spending) {
				tempSpending = customerSearch[i].spending;
				customerSearch[i].spending = customerSearch[j].spending;
				customerSearch[j].spending = tempSpending;

				strcpy(tempCategory, customerSearch[i].category);
				strcpy(customerSearch[i].category, customerSearch[j].category);
				strcpy(customerSearch[j].category, tempCategory);
			}
		}
	}
}

void printRecords(customerSearch_t customerSearch[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%s %d\n", customerSearch[i].category, customerSearch[i].spending);
	}	
}