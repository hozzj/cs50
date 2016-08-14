#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("minutes: ");
    int minutes = GetInt();
    
    int ounces_per_minute = 128 * 1.5;
    int bottle_ounces = 16;
    int bottles_per_minute = ounces_per_minute / bottle_ounces;
    int bottles_wasted = minutes * bottles_per_minute;
    
    printf("bottles: %d\n", bottles_wasted);
    
    return 0;
}