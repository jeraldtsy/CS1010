// sortModules.c
// Given an array of module codes, and an array of student
// enrolment, sort the modules in ascending order of 
// student enrolment.
#include <stdio.h>
#include <string.h>

#define MAX_MODULES 10   // maximum number of modules
#define CODE_LENGTH 7    // length of module code

typedef struct {
	char code[CODE_LENGTH+1];	// module code
	int enrolment;						// enrolment 
} module_t;

int scanModules(module_t []);
void printModules(module_t [], int);
void sortByEnrolment(module_t [], int);

int main(void) {
	module_t modules[MAX_MODULES];
	int num_modules;

	num_modules = scanModules(modules);
	sortByEnrolment(modules, num_modules);
	printModules(modules, num_modules);

	return 0;
}

// Read number of modules, and for each module, the module codes and enrolment figures.
// Return number of modules.
int scanModules(module_t modules[]) {
	int size, i;

	printf("Enter number of modules: ");
	scanf("%d", &size);

	printf("Enter module codes and student enrolment:\n");
	for (i=0; i<size; i++) 
		scanf("%s %d", modules[i].code, &modules[i].enrolment);

	return size;
}

// Print module codes and enrolment figures
void printModules(module_t modules[], int size) {
	int i;

	printf("Sorted by student enrolment:\n");
	for (i=0; i<size; i++)
		printf("%s\t%3d\n", modules[i].code, modules[i].enrolment);
}

// Sort by enrolment in each module
void sortByEnrolment(module_t modules[], int size) {

	// Fill in the code


}