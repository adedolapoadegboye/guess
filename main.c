#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 5
#define MAX_NUMBER 10
#define MIN_NUMBER 1

// Clear input buffer
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(void)
{
    char name[100];        // Player's name
    char retry = 'n';      // Variable for retrying the game
    int random_number = 0; // Random number
    int attempts = 0;      // Number of attempts
    int guess = 0;         // Player's guess
    time_t t;

    // Welcome and personalization of the game
    printf("\nWelcome to the guessing game!\n");
    printf("\nPlease enter your name: ");
    scanf("%s", name);

    do // Game loop
    {
        // Generating a random number between MIN_NUMBER and MAX_NUMBER
        srand((unsigned)time(&t));                                             // Initialize random number generator
        random_number = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER; // Generate a random number between MIN_NUMBER and MAX_NUMBER
        printf("Hint: The number is %d.\n", random_number);

        printf("\nHello, %s. I am thinking of a number between 1 and 10. You have %d attempts to guess it.\n", name, MAX_ATTEMPTS);

        // Handling the guess attempts
        for (attempts = 1; attempts < MAX_ATTEMPTS; attempts++)
        {
            printf("\n>> Enter your guess: ");
            scanf("%d", &guess);

            if (guess > MAX_NUMBER || guess < MIN_NUMBER)
            {
                printf("\nAttempt %d: Error! Please enter a number between %d and %d.\n", attempts, MIN_NUMBER, MAX_NUMBER);
            }
            else if (guess < random_number)
            {
                printf("\nAttempt %d: Too low. Try again.\n", attempts);
            }
            else if (guess > random_number)
            {
                printf("\nAttempt %d: Too high. Try again.\n", attempts);
            }
            else
            {
                printf("\nCongratulations, %s. You guessed it in %d attempts.\n", name, attempts);
                break;
            }
        }

        if (attempts == MAX_ATTEMPTS)
        {
            printf("\nGame over! You have no attempts left. The number was %d.\n", random_number);
        } // Game over message if no attempts left. The number was random_number.

        // Clear buffer and ask if the user wants to play again
        clearBuffer();
        printf("\n>> Would you like to play again? (y/n)\n");
        scanf(" %c", &retry);

    } while (retry == 'y' || retry == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}
