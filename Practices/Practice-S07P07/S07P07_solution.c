	// Solution


	#include <stdio.h>
	#define MAX_ROW 100
	#define MAX_COL 100

	void findEndPos(int[][MAX_COL], int[][MAX_COL], int, int, int);
	int calculateAns(int[][MAX_COL], int[][MAX_COL], int, int, int);

	int main() {
		int row, col, level, i, j;
		int land[MAX_ROW][MAX_COL];
		int robotsCounter[MAX_ROW][MAX_COL];
		int ans;

		printf("Enter dimensions of the land: ");
		scanf("%d %d", &row, &col);

		printf("Enter elevations: \n");

		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++)
				scanf("%d", &land[i][j]);

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				robotsCounter[i][j] = 1;
			}
		}
		printf("Enter flood level: ");
		scanf("%d", &level);

		findEndPos(land, robotsCounter, level, row, col);
		ans = calculateAns(land, robotsCounter, level, row, col);

		printf("Number of robots to be rescued: %d\n", ans);

		return 0;
	}

	// my answers are always short of 1 or more than 1 away. I"m close!
void findEndPos(int land[][MAX_COL], int robotsCounter[][MAX_COL], int level, int row, int col) {
	int moveDirection; 
	int tempGreatest = 0; 
	int currI, currJ;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			currI = i; 
			currJ = j;

			while (1) {				
				moveDirection = 0;
				tempGreatest = land[i][j];
				

				//checkNorth
				if ((i - 1) != -1) {
					if (land[i - 1][j] > tempGreatest) {
						tempGreatest = land[i - 1][j];
						moveDirection = 1;
					}
				}
				//checkSouth
				if ((i + 1) != row) {
					if (land[i + 1][j] > tempGreatest) {
						tempGreatest = land[i + 1][j];
						moveDirection = 2;

					}
				}
				//checkEast
				if ((j + 1) != col) {
					if (land[i][j + 1] > tempGreatest) {
						tempGreatest = land[i][j + 1];
						moveDirection = 3;
					}
				}
				//checkWest
				if ((j - 1) != -1) {
					if (land[i][j - 1] > tempGreatest) {
						tempGreatest = land[i][j - 1];
						moveDirection = 4;
					}
				}

				if ((moveDirection == 0) || (robotsCounter[i][j] == 0)){
					i = currI; 
					j = currJ;
					break; 
				}

				else if (moveDirection == 1) {
					robotsCounter[i - 1][j] += robotsCounter[i][j];
					robotsCounter[i][j] = 0;
					i = i - 1;
				}
				else if (moveDirection == 2) {
					robotsCounter[i + 1][j] += robotsCounter[i][j];
					robotsCounter[i][j] = 0;
					i = i + 1;
				}
				else if (moveDirection == 3) {
					robotsCounter[i][j + 1] += robotsCounter[i][j];
					robotsCounter[i][j] = 0;
					j = j + 1;
				}
				else if (moveDirection == 4) {
					robotsCounter[i][j - 1] += robotsCounter[i][j];
					robotsCounter[i][j] = 0;
					j = j - 1;
				}
			}
		}

	}
}

int calculateAns(int land[][MAX_COL], int robotsCounter[][MAX_COL], int level, int row, int col) {
	int ans = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (robotsCounter[i][j] != 0) {
				if (land[i][j] < level) {
					ans += robotsCounter[i][j];
				}
			}
		}
	}

	return ans;
}