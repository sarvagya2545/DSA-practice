#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct Tree
{
    TreeNode *root;
} Tree;

// implement queue to aid in generating a tree
typedef struct QueueNode
{
    TreeNode *node;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

void initQueue(Queue *q)
{
    QueueNode *el = (QueueNode *)malloc(sizeof(QueueNode));
    q->front = el;
    q->rear = el;
    el->next = NULL;
}

bool isEmpty(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, TreeNode *x)
{
    QueueNode *el = (QueueNode *)malloc(sizeof(QueueNode));
    el->node = x;
    q->rear->next = el;
    q->rear = q->rear->next;
}

TreeNode *dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        q->front = q->front->next;
        return q->front->node;
    }
}

// function to create node
TreeNode *createNode(int data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void postOrder(TreeNode *node)
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

void preOrder(TreeNode *node)
{
    printf("%d ", node->data);
    if (node->left != NULL)
    {
        postOrder(node->left);
    }
    if (node->right != NULL)
    {
        postOrder(node->right);
    }
}

void inOrder(TreeNode *node)
{
    if (node->left != NULL)
    {
        postOrder(node->left);
    }
    printf("%d ", node->data);
    if (node->right != NULL)
    {
        postOrder(node->right);
    }
}

void levelOrder(TreeNode *node)
{
    Queue q1;
    initQueue(&q1);

    enqueue(&q1, node);
    while (!isEmpty(&q1))
    {
        TreeNode *t = dequeue(&q1);
        if (t->left != NULL)
            enqueue(&q1, t->left);
        if (t->right != NULL)
            enqueue(&q1, t->right);
        printf("%d ", t->data);
    }
}

int main()
{
    Tree t1;
    int n;
    int a, b;
    char c;

    scanf("%d%*c", &n);
    TreeNode *arr = NULL;
    arr = (TreeNode *)malloc(sizeof(TreeNode) * n);

    // input array
    for (int i = 0; i < n; i++)
    {
        scanf("%d%*c", &a);
        arr[i].data = a;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i].data);
    // }

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %c%*c", &a, &b, &c);
        if (c == 'L')
            arr[a].left = &arr[b];
        if (c == 'R')
            arr[a].right = &arr[b];
    }

    levelOrder(&(arr[0]));

    return 0;
}