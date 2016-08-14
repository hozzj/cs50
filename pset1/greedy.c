// greedy algorithm
// ask how much change is owed
// create coins
// return the minimum number of coins

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    float cash;
    int count = 0;
    do 
    {
        printf("How much change is owed?\n");
        cash = (GetFloat() * 100);
        cash = round(cash);
    } 
    while (cash < 0);

    while (cash >= 25)
    {
        cash -= 25;
        count += 1;
    }

    while(cash >= 10 )
    {
        cash -= 10;
        count += 1;
    }

    while(cash >= 5)
    {
        cash -= 5;
        count += 1;
    }
    
    while (cash >= 1)
    {
        cash -= 1;
        count += 1;
    }
    
    printf("%d\n", count);
    return 0;
}