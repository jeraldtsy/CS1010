// rotate.c
// Solution
#include <stdio.h>
#define MAX_SIZE 10

int scan(int [][MAX_SIZE]);
void print(int [][MAX_SIZE], int);
void rotate(int [][MAX_SIZE], int, int);

int main(void) {
    int image[MAX_SIZE][MAX_SIZE];
    int degree;
    int size; 
    
    size = scan(image);
    
	printf("Enter degree of rotation: ");
	scanf("%d", &degree);
	
	rotate(image, size, degree);
	printf("The image after rotation: \n");
	print(image, size);

	return 0;
}

void rotate(int image[][MAX_SIZE], int size, int degree) {
    int temp;
    int numRotates; 
    
    numRotates = degree / 90;
    
    for (int a = 0; a < numRotates; a++) {
        for (int i = 0; i < (size / 2); i++) {
            for (int j = i; j < (size - i - 1); j++) {
                temp = image[i][j];
                image[i][j] = image[size - 1 - j][i];
                image[size - 1 - j][i] = image[size - 1 - i][size - 1 - j];
                image[size - 1 - i][size - 1 - j] = image[j][size - 1 - i];
                image[j][size - 1 - i] = temp;
            }
        }
    }
}

// To read in an image
int scan(int image[MAX_SIZE][MAX_SIZE]) {
    int size; 
    
	printf("Enter size: ");
	scanf("%d", &size);
	
	printf("Enter values: \n");
	for (int i = 0; i < size; i++) {
	    for (int j = 0; j < size; j++) {
	        scanf("%d", &image[i][j]);
	    }
	}
	
	return size;
}

// To print an image
void print(int image[][MAX_SIZE], int size) {
	int row, col;

	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) 
			printf("%d ", image[row][col]);
		printf("\n");
	}
}