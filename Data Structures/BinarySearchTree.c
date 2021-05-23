#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* node, int x) {
    if(node == NULL) { 
        node = (struct Node*)malloc(sizeof(struct Node));
        node->data = x;
        node->left = node->right = NULL;
        return node;
    }

    if(node->data > x) return insert(node->left, x);
    if(node->data < x) return insert(node->right, x);
    return node;
}

void postOrder(struct Node *node)
{
    if (node->left != NULL)
    {
        postOrder(node->left);
    }
    if (node->right != NULL)
    {
        postOrder(node->right);
    }
    printf("%d ", node->data);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 6);
    insert(root, 7);
    insert(root, 4);
    insert(root, 5);
    insert(root, 8);

    postOrder(root);
    return 0;
}