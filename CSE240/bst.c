#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// function to create a new node
struct node* createNode(int data, char *question, char *guess)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(strlen(question) > 0){
        newNode->question = (char *)malloc(strlen(question) + 1);
        strcpy(newNode->question, question);
    }
    else{
        newNode->question = (char *)malloc(strlen(guess) + 1);
        strcpy(newNode->question, guess);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a new node with given data
struct node* insert(struct node* root, int data, char *question, char *guess)
{
    if (root == NULL)
    {
        return createNode(data, question, guess);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data, question, guess);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data, question, guess);
    }
    return root;
}
