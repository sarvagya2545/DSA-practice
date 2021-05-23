#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert
   a new node with given key in
 * BST */
Node *insert(Node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(Node *node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    printf("%d ", node->data);
}

int main()
{
    Node *root = NULL;
    int n, x;
    int f = 0;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &x);
        if (!f)
        {
            root = insert(root, x);
            f = 1;
        }
        else
        {
            insert(root, x);
        }
    }

    printPostorder(root);

    return 0;
}