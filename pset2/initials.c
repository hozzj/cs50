#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // first we grab the full name
    string full_name = GetString();
    
    // apply the changes if the name is provided
    if (full_name != NULL)
    {
        // we then go through each character one by one
        for (int i = 0, n = strlen(full_name); i < n; i += 1)
        {
            // of course we capitalize and print the first char
            if (i == 0)
            {
                printf("%c", toupper(full_name[i]));
            }
            
            // and then we check for spaces so that we see the other names
            // and capitalize those either and then print them
            if (full_name[i] == ' ')
            {
                printf("%c", toupper(full_name[i + 1]));
            }
        }
        
        // after the completion we print a new line
        printf("\n");
    }
}