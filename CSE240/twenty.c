#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct node *create_game_tree()
{
    struct node *root = NULL;
    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");
    return root;
}
int main()
{
    struct node *root = create_game_tree();
    struct node *game_tree = root;
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    char c = 'a', d = 'b';
    scanf(" %c", &c);
    while(c!='q'){
        printf("You think of a fruit or a vegetable and I will try to guess it!\n");
        while(game_tree->left != NULL && game_tree->right != NULL){
            printf("%s\n", game_tree->question);
            printf("y/n: ");
            scanf(" %c", &d);
            if(d == 'y'){
                game_tree = game_tree->left;
            }
            else{
                game_tree = game_tree->right;
            }
        }
        printf("%s\n", game_tree->question);
        printf("y/n: ");
        scanf(" %c", &d);
        if(d=='y'){
            printf("I win!");
        }
        else{
            printf("You win!");
        }
        printf("\n");
        game_tree = root;
        printf("Press 'q' to quit or any other key to continue:\n");
        scanf(" %c", &c);
    }
    printf("Bye Bye!\n");
}