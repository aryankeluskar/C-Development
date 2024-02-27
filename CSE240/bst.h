struct node
{
    int data;
    char *question;
    char *guess;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data, char *question, char *guess);
struct node *insert(struct node *root, int data, char *question, char *guess);
