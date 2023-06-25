// countInputs.c
// To count the number of input values user entered.
// Solution
#include <stdio.h>

int main(void) {
    int num, count = 1;

    printf("Enter integers, terminate with ctrl-d\n");
    scanf("%d", &num);

    while (scanf("%d", &num) == 1) {
        count++;
        scanf("%d", &num);
    }

    printf("Number of values entered = %d\n", count);

    return 0;
}
