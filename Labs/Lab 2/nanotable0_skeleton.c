#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

/* Function prototypes */
int parse_command();

int check_command(char* input);

void print_help();

int simple_sum();

int simple_average();


int main() {
	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	parse_command();

	return 0;
}

// TO BE IMPLEMENTED: this should work in a REPL style
int parse_command() {
	char tmp_command[100] = "";
	int command_code;

	printf("Waiting for command...\n");
	scanf("%s", tmp_command);

	command_code = check_command(tmp_command);    

	if (command_code == COMMAND_HELP) {
		print_help();
	}
	else if (command_code == COMMAND_EXIT) {
		printf("See you!\n");
	}
	else if (command_code == COMMAND_SUM) {
		simple_sum();
	}
	else if (command_code == COMMAND_AVE) {
		simple_average();
	}
	else {
		// others
		printf("No such command: %s, please input command again!\n", tmp_command);
	}
	return 0;
}


// TO BE IMPLEMENTED: simple_sum and simple_average
// Remember to write a description for each function
int simple_sum() {
	printf("sum is %d\n", 1);
	return 0;
}

int simple_average() {
	printf("average is %d\n", 1);
	return 0;
}

// DO NOT MODIFY THE FOLLOWING PART!

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}

