#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int PlayGuessingGame();
int GetGuess();

// defined a struct to store player's name and score
struct player
{
    char name[100];
    int score;
};
int main() {
    struct player currPlayer;
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    char c, game_over = 0;
    // starting with assumption that user will play at least once
    while (!game_over)
    {
        scanf(" %c", &c);
        if (c == 'q')
        {
            game_over = 1;
            printf("Bye Bye!\n");
        }
        else
        {
            printf("Please enter your name to start:");
            scanf("%s", currPlayer.name);
            currPlayer.score = PlayGuessingGame();
            printf("You made %d guesses.\n", currPlayer.score);
            FILE *file = fopen("scores.txt", "r");

            // creating an array of players to store all players' scores with their names, but only top 5 players will be stored plus the current player
            struct player allPlayers[6];
            if (file == NULL){
                printf("Error opening file\n");
            }
            else {

                // read all players from file individually and store them in allPlayers array
                char currName[100];
                int currScore;
                int i = 0;
                // fscanf(file, "%s:%d", currName, &currScore);
                // printf("Read %s:%d\n", currName, currScore);
                while (fscanf(file, "%s :%d\n", currName, &currScore) != EOF && i < 5) {
                    // printf("Read %s who scored:%d\n", currName, currScore);
                    allPlayers[i].score = currScore;
                    strcpy(allPlayers[i].name, currName);
                    i++;
                }

                // instead of sorting, which has horrible time complexity, we can just insert the current player in the correct position because the file is already sorted from previous runs
                while (i > 0 && allPlayers[i-1].score > currPlayer.score) {
                    // go from end of array to start, shifting all players with higher scores to the right until the current player's score is better than the player at index i-1
                    allPlayers[i] = allPlayers[i-1];
                    i--;
                }

                // insert the current player at the correct position
                allPlayers[i] = currPlayer;

                // clear contents of file, then write allPlayers to file
                fclose(file);
                file = fopen("scores.txt", "w");

                // write all players to file by rewriting the file entirely
                // the worst player of the 6 will be eliminated at this stage
                for (int j = 0; j < 5; j++) {
                    fprintf(file, "%s :%d\n", allPlayers[j].name, allPlayers[j].score);
                }
                fclose(file);
            }
            
            printf("Press 'q' to quit or any other key to continue:\n");
        }
    }
    return 0;
}

int PlayGuessingGame()
{
    int tries = 0;
    // Generate a random number between 10 and 100 and find its square root
    srand((unsigned int)time(NULL)); // Seed rand() with current time
    int numberToGuess = rand() % 91 + 10;
    double squareRoot = sqrt(numberToGuess);
    printf("%.8f is the square root of what number?", squareRoot);
    char done = 0;
    while (!done)
    {
        int guess = GetGuess();
        if (guess < numberToGuess){
            printf("Too low, guess again: ");
            tries++;
        }
        else if (guess > numberToGuess){
            printf("Too high, guess again: ");
            tries++;
        }
        else
            done = 1;
    }
    printf("You got it, baby!\n");
    return tries+1;
}

int GetGuess()
{
    int guess;
    printf("Guess a value between 10 and 100: ");
    int num_values = scanf("%d", &guess);
    while (getchar() != '\n')
        ; // clear buffer
    // re-prompt if user enters invalid guess
    while (num_values != 1 || guess < 10 || guess > 100)
    {
        printf("Make sure your guess is between 10 and 100: ");
        num_values = scanf("%d", &guess);
        while(getchar() != '\n'); // clear buffer
    }
    return guess;
}
