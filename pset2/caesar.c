#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// a function for more abstraction
string cipher(int shift, string secret);

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        // zero or more than one arguments? error!!
        printf("error: no shift length is provided !!\n");
        return 1;
    }
    
    // store the shift as an integer
    // request the message from the user
    int shift = atoi(argv[1]);
    string secret = GetString();
    
    printf("%s\n", cipher(shift, secret));
}

string cipher(int shift, string secret)
{
    string ciphered = secret;
    // for every character in ciphered
    for (int i = 0, n = strlen(ciphered); i < n; i += 1)
    {
        // if it is not a letter ignore it
        if (isalpha(ciphered[i]))
        {
            // if uppercase
            if (ciphered[i] <= 'Z')
            {
                if ((ciphered[i] + (shift % 26)) <= 'Z')
                {
                // shift them to right shift times
                    ciphered[i] = (ciphered[i] + (shift % 26));
                }
                else
                {
                    // otherwise shift them to the left
                    ciphered[i] = ((ciphered[i]) - (26 - shift % 26));
                }
            }
            
            // if lowercase
            else
            {
                // repeat..
                if ((ciphered[i] + (shift % 26)) <= 'z')
                {
                    ciphered[i] = ((ciphered[i]) + (shift % 26));
            
                }
                else
                {
                    ciphered[i] = ((ciphered[i]) - (26 - shift % 26));
                }
            }
        }
    }
    return ciphered;
}