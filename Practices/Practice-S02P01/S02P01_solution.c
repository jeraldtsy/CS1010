// speedOfSound.c
// Read a temperature and compute the speed of sound in air.
// You must write a function speed_of_sound().
// solution

#include <stdio.h>
#include <math.h>

float speed_of_sound(float);

int main(void) {
    float degree, ans;

    printf("Temperature in degree Fahrenheit: ");
    scanf("%f", &degree);

    ans = speed_of_sound(degree);

    printf("Speed of sound in air of %.2f degree = %.2f ft/sec", degree, ans);
    return 0;
}

float speed_of_sound(float degree) {
    float ans; 

    ans = 1086 * sqrt(((5 * degree) + 297) / 247);

    return ans; 
}
