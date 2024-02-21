#ifndef SLIST_H
#define SLIST_H

#define ROWS 6
#define COLS 7
#define NUM_ROWS 6
#define NUM_COLS 7

struct Node
{
    char board[ROWS][COLS];
    struct Node* next;
};

void printBoard(struct Node* node);
void freeBoard(struct Node* node);
char CheckWinner(char board[][NUM_COLS]);
void PrintBoard(char board[][NUM_COLS]);
void ReplayBoard(struct Node* node);
void putBoard(struct Node* node, char inData[ROWS][COLS]);
void printBoard(struct Node* node);
void freeBoard(struct Node* node);


#endif /* SLIST_H */
