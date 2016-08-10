#include <stdio.h>
#include <cs50.h>

int main(void) {
    printf("minutes: ");
    int minutes = GetInt();
    
    int ouncesPerMinute = 128 * 1.5;
    int bottleOunces = 16;
    int bottlesPerMinute = ouncesPerMinute / bottleOunces;
    int bottlesWasted = minutes * bottlesPerMinute;
    
    printf("bottles: %d\n", bottlesWasted);
    
    return 0;
}