// magicNumber.c
// You must write a function get_magic().
// solution

#include <stdio.h>

int get_magic(int);

int main(void) {
    int num1, num2, ans1, ans2; 

    printf("Enter 1st value: ");
    scanf("%d", &num1);
    ans1 = get_magic(num1);
    printf("Magic number = %d\n", ans1);
    
    printf("Enter 2nd value: ");
    scanf("%d", &num2);
    ans2 = get_magic(num2);
    printf("Magic number = %d", ans2);

    return 0;
}

int get_magic(int num) {
    int ans = 0; 
    
    for (int i = 0; i < 5; i++) {
        if ((i % 2) == 0) {
            ans += num % 10;
        }
        num /= 10;
    }
    return (ans % 10); 
}// magicNumber.c
// You must write a function get_magic().
// solution

#include <stdio.h>

int get_magic(int);

int main(void) {
    int num1, num2, ans1, ans2; 

    printf("Enter 1st value: ");
    scanf("%d", &num1);
    ans1 = get_magic(num1);
    printf("Magic number = %d\n", ans1);
    
    printf("Enter 2nd value: ");
    scanf("%d", &num2);
    ans2 = get_magic(num2);
    printf("Magic number = %d", ans2);

    return 0;
}

int get_magic(int num) {
    int ans = 0; 
    
    for (int i = 0; i < 5; i++) {
        if ((i % 2) == 0) {
            ans += num % 10;
        }
        num /= 10;
    }
    return (ans % 10); 
}