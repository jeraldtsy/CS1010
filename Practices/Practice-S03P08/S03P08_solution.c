// perfectNumber.c  
// Repeatedly reads a non-negative value, and stops when zero is read. 
// For each positive value read, it checks if the value is a perfect number. 
//Solution 

#include <stdio.h> 

int is_perfect(int);

int main(void) {
    int num;

    printf("Enter number: ");   

    while ((scanf("%d", &num)) == 1) {

        if (num == 0) {
            break;
        }
        if (is_perfect(num) == 1) {
            printf("%d is a perfect number\n", num);
        }
        else {
            printf("%d is not a perfect number\n", num);
        }

        printf("Enter number:");
    }

    return 0;
}

int is_perfect(int num) {

    int isPerfect = 0;
    int ans = 0;

    if (num % 2 == 1) {
        return 0;
    }

    else {
        for (int i = 2; i <= (num / 2); i++) {
            if ((num % i) == 0) {
                ans += i;
            }
        }

        ans += 1; 

        if (ans == num) {
            return 1;
        }
    }
}