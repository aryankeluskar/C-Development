// this program in C plays the game of rock, paper, scissors by invoking the necessary functions until the user chooses to quit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PlayRockPaperScissorsGame();
char GetPlayerMove();
char GetComputerMove();

// main function to process choice and call necessary functions to play the game
int main()
{
   printf("Welcome to Rock, Paper, Scissors! ");
   char choice = 'a';
   // printf("%c", choice);
   // return 0;
   printf("press 'q' to quit or any other key to continue:\n");
   scanf(" %c", &choice);
   while (choice != 'q')
   {
      // being in this loop means the user did not enter 'q' to quit, so play the game
      PlayRockPaperScissorsGame();
      printf("press 'q' to quit or any other key to continue:\n");
      scanf(" %c", &choice);
   }
   printf("Bye Bye!\n");
   return 0;
}

// function to play one round of the game
int PlayRockPaperScissorsGame()
{
   char player = GetPlayerMove();
   char comp = GetComputerMove();
   // printf("Player's Move: %c\n",player);
   printf("Computer's Move: %c\n", comp);
   if ((player == 'r' && comp == 'p') || (player == 'p' && comp == 's') || (player == 's' && comp == 'r'))
   {
      printf("Computer Wins!\n");
   }

   if ((player == 'r' && comp == 's') || (player == 'p' && comp == 'r') || (player == 's' && comp == 'p'))
   {
      printf("You Win!\n");
   }
   return 0;
}

// function to get the player's move and validate it before returning
char GetPlayerMove()
{
   // 100 chars in case the user enters a string of characters instead of just one
   char player[100];
   printf("Enter your move (r for rock, p for paper, s for scissors): ");
   scanf(" %s", player);

   // after confirming that string is one character long, check if it is a valid rock, paper, scissor move
   if ((strlen(player) > 1) || (player[0] != 'r' && player[0] != 's' && player[0] != 'p'))
   {
      printf("Invalid Move. ");
      return GetPlayerMove();
   }

   char final = player[0];
   return final;
}

// function to get the computer's move and return it. use rand() function to generate a random number between 1 and 3 and use it to determine the computer's move
char GetComputerMove()
{
   int r = rand() % (3 + 1 - 1) + 1;
   char play = '-';
   if (r == 1)
   {
      play = 'r';
   }
   if (r == 2)
   {
      play = 'p';
   }
   if (r == 3)
   {
      play = 's';
   }
   return play;
}
