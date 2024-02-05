#include <cs50.h>
#include <math.h>
#include <stdio.h>

int cclen(long number);
void find_provider(long number);
int luhncheck(long number);

int main(void)
{
    long ccnumber = get_long("Credit Card Number: ");

    if (luhncheck(ccnumber) % 10 == 0)
    {
        find_provider(ccnumber);
    }
    else
        printf("INVALID\n");

    // printf("%i", cclen(ccnumber));
    // printf("%i", find_provider(ccnumber));
    // find_provider(ccnumber);
    // printf("%i\n", luhncheck(ccnumber));
}

int luhncheck(long number)
{
    // create variable to store the sum of the digits
    int sum = 0;
    // need counter for the number of digits to find the odd and even digits
    int count = 0;

    while (number > 0)
    {
        // extract the last digit from the number and store on each digit
        int each_digit = number % 10;
        // remove the last digit from number to run the loop again
        number /= 10;
        count++;
        // for the even counter, multiply by two and if the multiplication is bigger than nine reduce nine to achieve the sum of the
        // digits from the result
        if (count % 2 == 0)
        {
            each_digit *= 2;
            if (each_digit > 9)
            {
                each_digit -= 9;
            }
        }
        // after processign the odd position numbers add them togheter, and also when it is not odd, directly add the numbers.
        sum += each_digit;
    }
    return (sum);
}

int cclen(long number)
{
    int count = 0;

    while (number != 0)
    {
        number = number / 10;
        count++;
    }
    return count;
}

void find_provider(long number)
{
    long first2 = number;
    int card_len = cclen(number);

    while (first2 >= 100)
        first2 /= 10;
    if (card_len == 16)
    {
        if (first2 >= 40 && first2 <= 49)
            printf("VISA\n");
        else if (first2 >= 51 && first2 <= 55)
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
    }
    else if (card_len == 15)
    {
        if (first2 == 34 || first2 == 37)
            printf("AMEX\n");
        else
            printf("INVALID\n");
    }
    else if (card_len == 13)
    {
        if (first2 >= 40 && first2 <= 49)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else if (card_len < 13 || card_len > 16 || card_len == 14)
        printf("INVALID\n");
}
