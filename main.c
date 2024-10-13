#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 5
#define MAX_NUMBER 10
#define MIN_NUMBER 1

int main(void)
{
    char name[100];
    char retry = 'n';
    int random_number = 0;
    int attempts = 0;
    int guess = 0;

    printf("\nWelcome to the guessing game!\n");
    printf("\nPlease enter your name: \n");
    scanf("%s", name);

    do
    {
        printf("\nHello, %s. I am thinking of a number between 1 and 10. You have %d attempts to guess it. Can you guess what it is?\n", name, MAX_ATTEMPTS);
        scanf("%d", &guess);
        printf("\nYou guessed %d. Is that correct? Let's find out. \n", guess);

        printf("\nWould you like to play again? (y/n)\n");
        scanf(" %c", &retry);
    } while (retry == 'y' || retry == 'Y');

    printf("\nThanks for playing!\n");
}