// validPath.c
#include <stdio.h>
#include <string.h>

#define SIZE 6     // size (number of rows and columns) of maze
#define WALL 0
#define CELL 1
#define MAX_PATHLEN 10

void readMaze(int [][SIZE], int);
int isValid(int [][SIZE], char []);

int main(void) {
	int maze[SIZE][SIZE];
	char path[MAX_PATHLEN+1];

	readMaze(maze, SIZE); 

	printf("Enter path: ");
	scanf("%s", path);

	if (isValid(maze, path))
		printf("Path is valid.\n");
	else
		printf("Path is not valid.\n");

	return 0;
}

// Create the maze
void readMaze(int maze[][SIZE], int size) {
	int	r, c;

	printf("Enter maze:\n");
	for (r=0; r<size; r++)
		for (c=0; c<size; c++)
			scanf("%d", &maze[r][c]);
}

// Determine whether input path is valid in input maze
int isValid(int maze[][SIZE], char path[]) {
	int pathlen;

	pathlen = strlen(path);

	return 0; // this is a stub
}

