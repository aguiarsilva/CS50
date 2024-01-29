#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encode(char *text, char *key);

int main(int argc, string argv[])
{
    // check if there is more than 2 arguments and return error
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // check lenght of the key for errors
    int key_len = strlen(argv[1]);

    // check if lenght of key is not equal 26 and return error
    if (key_len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < key_len; i++)
    {
        // check if key has non alphanumeric chars and return error
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain characters only.\n");
            return 1;
        }
        // check for repeated letters and return error
        for (int j = i + 1; j < key_len; j++)
        {
            // need to convert to lowercase because system doesn't recognize A and a as the same character (ascii number are
            // different)
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must not repeat characters.\n");
                return 1;
            }
        }
    }
    // if key is valid, takes text to encrypt
    string plaintext = get_string("Plaintext: ");
    // create a separate function to make the encryption taking the text inputed by user and the valid key inputed when running the
    // program
    encode(plaintext, argv[1]);
}

void encode(char *text, char *key)
{
    printf("ciphertext: ");

    int text_len = strlen(text);

    // check if text char is alphabetical and print respecting the case
    for (int i = 0; i < text_len; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                // must subtract the Ascii number of letter A and a from upper and lowercase in order to get the exact index number
                // (which starts by 0)
                int pos = text[i] - 65;
                printf("%c", toupper(key[pos]));
            }
            else
            {
                int pos = text[i] - 97;
                printf("%c", tolower(key[pos]));
            }
        }
        // if not alphabetical, just print the character
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
