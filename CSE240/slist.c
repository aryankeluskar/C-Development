#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "slist.h"

#define ROWS 6
#define COLS 7

// struct Node
// {
//     char board[ROWS][COLS];
//     struct Node* next;
// };

void putBoard(struct Node* node, char inData[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            node->board[i][j] = inData[i][j];
}

void printBoard(struct Node* node){
    for (int r = ROWS-1; r >= 0; r--)
    {
        for (int c = 0; c < NUM_COLS; c++){
            if(node->board[r][c] != 'R' && node->board[r][c] != 'Y' && node->board[r][c] != ' ')
                return;
            printf("|%c", node->board[r][c]);
        }
		printf("|\n");
    }
    printf("===============\n");
    // printf("\n");
}

void freeBoard(struct Node* node){
    while (node != NULL)
    {
        struct Node* temp = node;
        node = node->next;
        free(temp);
    }
}

void ReplayBoard(struct Node* node){
    struct Node* current = node;
    while (current->next != NULL)
    {
        printBoard(current);
        current = current->next;
    }
}

// int main()
// {
//     struct Node* head = NULL;
//     struct Node* current = NULL;

//     // Generate random matrix for the head node
//     head = (struct Node*)malloc(sizeof(struct Node));
//     // char simBoard[ROWS][COLS] = { {'R', 'Y', 'R', 'Y', 'R', 'Y', 'R'},
//     //                               {'Y', 'R', 'Y', 'R', 'Y', 'R', 'Y'},
//     //                               {'R', 'Y', 'R', 'Y', 'R', 'Y', 'R'},
//     //                               {'Y', 'R', 'Y', 'R', 'Y', 'R', 'Y'},
//     //                               {'R', 'Y', 'R', 'Y', 'R', 'Y', 'R'},
//     //                               {'Y', 'R', 'Y', 'R', 'Y', 'R', 'Y'} };
//     // putBoard(head->board, simBoard);
//     // head->row = 0;
//     // head->col = 0;
//     head->next = NULL;

//     // Print the linked list
//     current = head;
//     while (current != NULL)
//     {
//         printBoard(current);

//         current = current->next;
//     }

//     // Free the memory
//     current = head;
//     while (current != NULL)
//     {
//         struct Node* temp = current;
//         current = current->next;
//         free(temp);
//     }

//     return 0;
// }
