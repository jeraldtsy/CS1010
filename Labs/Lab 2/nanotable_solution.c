#include <stdio.h>
#include <string.h>
#include <math.h>

//solution
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
	
	while (command_code != 1) {
		if (command_code == COMMAND_HELP) {
			print_help();
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

		printf("Waiting for command...\n");
		scanf("%s", tmp_command);

		command_code = check_command(tmp_command);
	}

	printf("See you!");
	
	return 0;
}


// TO BE IMPLEMENTED: simple_sum and simple_average
// Adds the total number of sums and prints the result as an integer.
int simple_sum() {
	int num, input;
	int ans = 0;
	
	printf("Please indicate the number of integers:\n");
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		if (((i + 1) % 10 == 1) && ((i + 1) != 11)) {
			printf("Please input the %dst number:\n", i + 1);
		}
		else if (((i + 1) % 10 == 2) && ((i + 1) != 12)) {
			printf("Please input the %dnd number:\n", i + 1);
		}
		else if (((i + 1) % 10 == 3) && ((i + 1) != 13)) {
			printf("Please input the %drd number:\n", i + 1);
		}
		else {
			printf("Please input the %dth number:\n", i + 1);
		}
		scanf("%d", &input);

		ans += input; 
	}

	printf("sum is %d\n", ans);
	return 0;
}
// Adds the total number of sums and prints an integer rounded to the nearest whole number
int simple_average() {
	int input;
	float num;
	float ans = 0;

	printf("Please indicate the number of integers:\n");
	scanf("%f", &num);

	for (int i = 0; i < num; i++) {
		if (((i + 1) % 10 == 1) && ((i + 1) != 11)) {
			printf("Please input the %dst number:\n", i + 1);
		}
		else if (((i + 1) % 10 == 2) && ((i + 1) != 12)) {
			printf("Please input the %dnd number:\n", i + 1);
		}
		else if (((i + 1) % 10 == 3) && ((i + 1) != 13)) {
			printf("Please input the %drd number:\n", i + 1);
		}
		else {
			printf("Please input the %dth number:\n", i + 1);
		}
		scanf("%d", &input);
		ans += input;
	}
	ans /= num;
	ans = round(ans);
		
	printf("average is %d\n", int(ans));
		

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
	if (strcmp(input, "help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input, "exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input, "sum") == 0) {
		return COMMAND_SUM;
	}
	else if (strcmp(input, "ave") == 0) {
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
