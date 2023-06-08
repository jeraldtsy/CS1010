// search_pattern.c
#include <stdio.h>
#define MINE '*'      // a mine-filled square
#define FIELD_ROWS 8  // number of rows for minefield
#define FIELD_COLS 8  // number of columns for minefield
#define PAT_ROWS 2    // number of rows for pattern
#define PAT_COLS 3    // number of columns for pattern

void scan_mines(char [][FIELD_COLS+1]);
void scan_pattern(char [][PAT_COLS]);
void print_minefield(char [][FIELD_COLS+1]);
void print_pattern(char [][PAT_COLS]);
int search(char [][FIELD_COLS+1], char [][PAT_COLS]);

int main(void) {
	char minefield[FIELD_ROWS][FIELD_COLS+1];
	char pattern[PAT_ROWS][PAT_COLS];

	printf("Enter minefield:\n");
	scan_mines(minefield);
	printf("Minefield entered:\n");
	print_minefield(minefield); 

	printf("Enter search pattern:\n");
	scan_pattern(pattern);
	printf("Search pattern entered:\n");
	print_pattern(pattern); 

	printf("Answer = %d\n", search(minefield, pattern));

    return 0;
}

// Read the grid for minefield
void scan_mines(char grid[][FIELD_COLS+1]) {
	int r;

	for (r=0; r<FIELD_ROWS; r++)
		scanf("%s", grid[r]); // Alternative 
	getchar(); // to catch newline
}

// Read the pattern
void scan_pattern(char pattern[][PAT_COLS]) {
	int r, c;

	for (r=0; r<PAT_ROWS; r++) {
		for (c=0; c<PAT_COLS; c++)
			pattern[r][c] = getchar();
		getchar(); // to catch newline
	}
}

// To print the minefield
void print_minefield(char grid[][FIELD_COLS+1]) {
	int r;

	for (r=0; r<FIELD_ROWS; r++)
		printf("%s\n", grid[r]);
}

// To print the pattern
void print_pattern(char pat[][PAT_COLS]) {
	int r, c;

	for (r=0; r<PAT_ROWS; r++) {
		for (c=0; c<PAT_COLS; c++) 
			putchar(pat[r][c]);
		putchar('\n');
	}
}

// Count the number of time the pattern 
// appears in the minefield.
int search(char grid[][FIELD_COLS+1], char pattern[][PAT_COLS]) {

	return 123;
}

