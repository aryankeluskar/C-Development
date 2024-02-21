/*
 connect.c

*/
#include "slist.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 6
#define NUM_COLS 7

typedef enum {F = 0,T = 1} Bool;

/*----------------------------------------------------
 int GetColumn(char player)
 prompts the player for a column between 1 and 7
 ----------------------------------------------------*/
int GetColumn(char player)
{
    int column;

    printf("%s to play. Pick a column (1-7):", player=='R' ? "Red":"Yellow");
    int num_values = scanf("%d", &column);
    while(getchar() != '\n'); // clear buffer of newline

    // re-prompt if player enters invalid guess
    while (num_values != 1 || column < 1 || column > NUM_COLS)
    {
        printf("Make sure the column is between 1 and 7: \n");
        num_values = scanf("%d", &column);
        while(getchar() != '\n');
    }
    return column-1;
}

/*----------------------------------------------------
 char CheckWinner(char board[][7])
 checks for four tokens in a row/column and returns
 the character for the winner or ' '
 ----------------------------------------------------*/
char CheckWinner(char board[][NUM_COLS])
{
	// check rows for four sequential tokens
	for (int r = 0; r < NUM_ROWS; r++)
	{
		char prev = board[r][0];
		int num = 1;
		for (int c = 1; c < NUM_COLS; c++)
		{
			if (board[r][c] == prev) num++;
			else {prev = board[r][c]; num = 1;}
			if (num == 4 && prev != ' ') return prev;
		}
	}

	// check columns for four sequential tokens
	for (int c = 0; c < NUM_COLS; c++)
	{
		char prev = board[0][c];
		int num = 1;
		for (int r = 1; r < NUM_ROWS; r++)
		{
			if (board[r][c] == prev) num++;
			else {prev = board[r][c]; num = 1;}
			if (num == 4 && prev != ' ') return prev;
		}
	}
	return ' ';
}


/*----------------------------------------------------
 Bool CheckBoardFull(char board[][NUM_COLS])
 checks if all places on board have been taken
 ----------------------------------------------------*/
Bool CheckBoardFull(char board[][NUM_COLS])
{
	for (int c = 0; c < NUM_COLS; c++)
		if (board[NUM_ROWS-1][c] == ' ')
			return F;
	return T;
}

/*----------------------------------------------------
 int GetEmptyRow(char board[][NUM_COLS], int col)
 returns the next available row for a given column
 ----------------------------------------------------*/
int GetEmptyRow(char board[][NUM_COLS], int col)
{
    int row = 0;
    while (row < NUM_ROWS && board[row][col] != ' ')
    	row++;
	return row;
}

/*----------------------------------------------------
 void PrintBoard(char board[][NUM_COLS])
 prints the current state of the board
 ----------------------------------------------------*/
void PrintBoard(char board[][NUM_COLS])
{
	for (int r = NUM_ROWS-1; r >= 0; r--)
	{
		for (int c = 0; c < NUM_COLS; c++)
			printf("|%c", board[r][c]);
		printf("|\n");
	}
    printf("===============\n");
}

// struct Node
// {
//     char board[ROWS][COLS];
//     struct Node* next;
// };

/*----------------------------------------------------
 void PlayConnectFour()
 allows players to pick a column for their token (R/Y)
 and announces a winner or a tie
 ----------------------------------------------------*/
void PlayConnectFour()
{
    struct Node* head = NULL;
    struct Node* current = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    
    // create an empty board
	char board[NUM_ROWS][NUM_COLS];
	for (int r = 0; r < NUM_ROWS; r++)
		for (int c = 0; c < NUM_COLS; c++)
			board[r][c] = ' ';

    putBoard(head, board);
    PrintBoard(board);
    current = head;

	char player = 'R';
    Bool game_over = F;

    while (!game_over)
    {
        int col = GetColumn(player);
        int row = GetEmptyRow(board, col);
        while (row > 5)
        {
        	printf("that column is full, pick another...\n");
        	col = GetColumn(player);
        	row = GetEmptyRow(board, col);
        }

        board[row][col] = player;
        putBoard(current, board);
        PrintBoard(board);
        current->next = (struct Node*)malloc(sizeof(struct Node));
        current = current->next;        

        char winner = CheckWinner(board);
        if (winner != ' ')
        {
        	printf("You win, %s!\n", winner=='R' ? "Red":"Yellow");
        	game_over = T;
        }
        else if (CheckBoardFull(board))
        {
        	printf("It's a tie!\n");
        	game_over = T;
        }

        player = (player == 'R' ? 'Y' : 'R');
    }
    printf("Good game!\n");
    printf("Press 'q' to quit or 'r' to replay or any other key to continue:\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'r')
    {
        ReplayBoard(head);
    }
    
}

/*----------------------------------------------------
 int main()
 prompts the user to play or quit and then enters a loop
 to allow the user to play as many times as they like
 ----------------------------------------------------*/
int main()
{
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");

    char c;
	Bool done = F;

    while (!done)
    {
        scanf(" %c", &c);

        if (c == 'q')
        {
            done = T;
            printf("Bye Bye!\n");
        }
        else
        {
            PlayConnectFour();
            printf("Press 'q' to quit or any other key to continue:\n");
        }
    }
    return 0;
}




