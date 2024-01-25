#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PlayRockPaperScissorsGame();
char GetPlayerMove();
char GetComputerMove();

int main()
{
   // for printing hello world, printf is the syntax
   printf("Welcome to Rock, Paper, Scissors! ");
   char choice = 'a';
   // printf("%c", choice);
   // return 0;
   printf("press 'q' to quit or any other key to continue:\n");
   scanf(" %c", &choice);
   while (choice != 'q')
   {

      PlayRockPaperScissorsGame();
      printf("press 'q' to quit or any other key to continue:\n");
      scanf(" %c", &choice);
   }
   printf("Bye Bye!\n");
   return 0;
}

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

char GetPlayerMove()
{
   char player[100];
   printf("Enter your move (r for rock, p for paper, s for scissors): ");
   scanf(" %s", player);

   if ((strlen(player) > 1) || (player[0] != 'r' && player[0] != 's' && player[0] != 'p'))
   {
      printf("Invalid Move. ");
      return GetPlayerMove();
   }

   char final = player[0];
   return final;
}

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