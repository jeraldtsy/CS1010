// ilink.c
// Solution
#include <stdio.h>
#define MAXSIZE 10

void printArr(int[][MAXSIZE], int);
void iSolitude(int[][MAXSIZE], int);
void uFriend(int[][MAXSIZE], int);

int main() {
	int friendArr[MAXSIZE][MAXSIZE] = { {0} };
	int size, pairsNum;
	int i, j, k;

	printf("Read in the number of users: ");
	scanf("%d", &size);

	printf("There are %d users, indexed from 0 to %d.\n", size, size - 1);
	printf("Enter the number of pairs of direct friends: ");
	scanf("%d", &pairsNum);

	printf("Enter actual pairs of direct friends:\n");

	for (k = 0; k < pairsNum; k++) {
		scanf("%d %d", &i, &j);
		friendArr[i][j] = 1;
	}

	printArr(friendArr, size);

	for (i = 0; i < size; i++) {
		friendArr[i][i] = 1;
		for (j = i + 1; j < size; j++) {
			if (friendArr[i][j] != friendArr[j][i]) {
				friendArr[i][j] = 1;
				friendArr[j][i] = 1;
			}
		}
	}

	printf("The friendship matrix is:\n");
	printArr(friendArr, size);

	iSolitude(friendArr, size);

	uFriend(friendArr, size);

	return 0;
}

void printArr(int arr[][MAXSIZE], int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
}

void iSolitude(int arr[][MAXSIZE], int size) {
	int min = size;
	int temp;
	int minuser;

	for (int i = 0; i < size; i++) {
		temp = 0;
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 1) {
				temp++;
			}
		}
		if (temp < min) {
			min = temp;
			minuser = i;
		}
	}
	printf("The least number of friends found is %d\n", min);
	for (int i = 0; i < size; i++) {
		temp = 0;

		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 1) {
				temp++;
			}
		}

		if (temp == min) {
			printf("User %d has least number of friends\n", i);
		}
	}
}

void uFriend(int arr[][MAXSIZE], int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 0) {
				for (int k = 0; k < size; k++) {
					if ((k == i) || (k == j)) {
						continue;
					}
					else {
						if ((arr[k][i] == 1) && (arr[k][j] == 1)) {
							if (i < j) {
								printf("(%d, %d) has a friend-of-friend relation.\n", i, j);
								break;
							}
						}
					}
				}
			}
		}
	}
}