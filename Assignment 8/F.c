#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int index;
};

void connectEdge(struct Node *tree[], int p, int c, char dir)
{
    if (dir == 'L')
    {
        (tree[p])->left = tree[c];
    }
    else if (dir == 'R')
    {
        (tree[p])->right = tree[c];
    }
}

struct Node *createNewNode(int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->index = index;

    return newNode;
}

struct Node *lca(struct Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);

    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // store the nodes in a list
    struct Node *tree[n];

    // add data to the nodes
    for (int i = 0; i < n; i++)
    {
        tree[i] = createNewNode(arr[i], i);
    }

    int a, b;
    char c;

    // make connections between nodes
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %c", &a, &b, &c);

        connectEdge(tree, a, b, c);
    }

    // answers array
    int *ans = (int *)malloc(q * sizeof(int));

    // handle queries
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &a, &b);
        // get the lowest common ancestor
        struct Node *t = lca(tree[0], arr[a], arr[b]);
        ans[i] = t->index;
    }

    for (int i = 0; i < q; i++)
        printf("%d ", ans[i]);

    return 0;
}