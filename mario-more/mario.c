#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int height;

    do
    {
        height = get_int("Type height (1 - 8): ");
    }
    while (height < 1 || height > 8);
    for (int i = 1; i <= height; i++)
    {
        print_row(height - i, i);
    }
}

void print_row(int spaces, int bricks)
{

    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    for (int k = 0; k < bricks; k++)
    {
        printf("#");
    }
    printf("  ");
    for (int l = 0; l < bricks; l++)
    {
        printf("#");
    }
    printf("\n");
}
