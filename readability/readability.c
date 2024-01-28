#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompt user for text input
    string text = get_string("Text: ");

    // count number of letters, words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // apply the Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
    float avg_let = ((float) letters / (float) words) * 100;
    float avg_sen = ((float) sentences / (float) words) * 100;

    float index = 0.0588 * avg_let - 0.296 * avg_sen - 15.8;
    // print the grade recommended for the text
    if (index < 1)
        printf("Before Grade 1\n");
    else if (index >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", (int) round(index));
}

int count_letters(string text)
{
    int letters = 0;
    int text_len = strlen(text);

    for (int i = 0; i < text_len; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
            letters++;
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    int text_len = strlen(text);

    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == 32 || text[i] == 9)
            words++;
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    int text_len = strlen(text);

    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
            sentences++;
    }
    return sentences;
}
