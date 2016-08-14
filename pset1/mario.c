#include <stdio.h>
#include <cs50.h>

int main(void) 
{

    // make sure it is an integer
    int height;
    do 
    {
        printf("height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    int spaces = height - 1;
    int hashes = 2;

    int i = 0;
    while (i < height) 
    {    
        int j = 0;
        while (j < spaces)
        {
            printf(" ");
            j += 1;
        }
        
        int k = 0;
        while (hashes > k) 
        {
            printf("#");
            k += 1;
        }
        
        hashes += 1;
        spaces -= 1;
        
        printf("\n");
        i += 1;
    }
    
    return 0;
}