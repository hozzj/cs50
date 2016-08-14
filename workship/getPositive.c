#include <stdio.h>
#include <cs50.h>

int GetPositiveInt();

int main(void)
{
    int n = GetPositiveInt();
    printf("%d", n);
    return 0;
}

int GetPositiveInt(void)
{
    int n;
    do 
    {
        printf("Please give me a positive integer");
        n = GetInt();
    }
    while (n < 1);
    return n;
}