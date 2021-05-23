#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* createTree(int inorder[], int preorder[], int l, int r, int* pIndex) {

    if(l >= r) return NULL;

    int num = preorder[(*pIndex)++];

    int i;
    for(i = l; i <= r; i++) {
        if(inorder[i] == num) {
            break;
        }
    }

    struct Node* node = createNode(num);

    node->left = createTree(inorder, preorder, l, i - 1, pIndex);
    node->right = createTree(inorder, preorder, i + 1, r, pIndex);
    return node;
}

void postOrder(struct Node* root) {
    if(root->left != NULL) postOrder(root->left);
    if(root->right != NULL) postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d%*c", &n);
    int preorder[n];
    int inorder[n];

    for(int i = 0; i < n; i++) {
        scanf("%d%*c", &inorder[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d%*c", &preorder[i]);
    }

    int pIndex = 0;
    struct Node* root = createTree(inorder, preorder, 0, n - 1, &pIndex);
    // printf("%d", (*root).data);
    postOrder(root);

    return 0;
}