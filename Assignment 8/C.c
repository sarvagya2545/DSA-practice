#include <stdio.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct Tree
{
    struct TreeNode *root;
} Tree;

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

int main()
{
    int n;
    scanf("%d%*c", &n);
    TreeNode *tree;
    tree = (TreeNode *)malloc(n * sizeof(TreeNode));
    int a, b;
    char c;

    // input array
    for (int i = 0; i < n; i++)
    {
        scanf("%d%*c", tree[i].data);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %c%*c", &a, &b, &c);
        if (c == 'L')
            tree[a].left = &tree[b];
        if (c == 'R')
            tree[a].right = &tree[b];
    }

    Stack *st;
    st = (Stack *)malloc(sizeof(Stack));

    return 0;
}
