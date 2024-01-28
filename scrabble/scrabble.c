#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// make an array with the points to be attributed to each letter
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score_sum(string word);

int main(void)
{
    // ask for the words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // compute the score for each word
    int score1 = score_sum(word1);
    int score2 = score_sum(word2);

    // inform the result of the winner by comparing the scores - if condition
    if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else if (score2 < score1)
    {
        printf("Player 1 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score_sum(string word)
{
    // need to use strlen to measure the size of the word and check for each indexed letter
    int score = 0;
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 65];
        }
        else if (islower(word[i]))
        {
            score += points[word[i] - 97];
        }
    }
    return score;
}
