#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string cipher(string key, string secret);

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("ERROR: PLEASE PROVIDE 1 KEY!!\n");
        return 1;
    }
    
    for (int i = 0, n = strlen(argv[1]); i < n; i += 1)
    {
        if (!(isalpha(argv[1][i])))
        {
            printf("ERROR: PLEASE DON'T USE NON-ALPHABETICAL CHARACTERS!!\n");
            return 1;
        }
    }
    string key = argv[1];
    string secret = GetString();
    printf("%s\n", cipher(key, secret));
    
}

string cipher(string key, string secret)
{
    /*
    the whole thing is that we should
    1. check for every char in the message and it's corresponding
    char value in the key
    2. then we convert the ascii presentation of these key chars
    into a 0-indexed list of chars
    3. at the end we should increment the chars by the number
    that represents the chars
    */
    
    // contain the addition ratio into an array
    int len = strlen(key);
    
    int keys[len];
    
    // push the ratios into the array
    for(int j = 0; j < len; j += 1)
    {
        keys[j] = (int) (toupper(key[j]) - 65);
    }
    
    
    for (int i = 0, j = 0, n = strlen(secret); i < n; i += 1)
    {
        if (isalpha(secret[i]))
        {
            // if uppercase
            if (isupper(secret[i]))
            {
                if ((secret[i] + keys[j % len]) <= 'Z')
                {
                // shift them to right k to the jth times
                    secret[i] = (secret[i] + keys[j % len]);
                    j += 1;
                }
                else
                {
                    // otherwise shift them to the left
                    secret[i] = ((secret[i]) - (26 - keys[j % len]));
                    j += 1;
                }
            }
            
            // if lowercase
            if (islower(secret[i]))
            {
                if ((secret[i] + keys[j % len]) <= 'z')
                {
                    secret[i] = ((secret[i]) + keys[j % len]);
                    j += 1;
                }
                else
                {
                    secret[i] = ((secret[i]) - (26 - keys[j % len]));
                    j += 1;
                }
            }
        }
    }
    return secret;
}