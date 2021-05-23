#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q)
{
    Node *el = (Node *)malloc(sizeof(Node));
    q->front = el;
    q->rear = el;
    el->next = NULL;
}

bool isEmpty(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, int x)
{
    Node *el = (Node *)malloc(sizeof(Node));
    el->data = x;
    q->rear->next = el;
    q->rear = q->rear->next;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
        return 0;
    }
    else
    {
        q->front = q->front->next;
        return q->front->data;
    }
}

void printQueue(Queue q)
{
    if (isEmpty(&q))
    {
        printf("Queue is empty");
    }
    else
    {
        while (q.front != q.rear)
        {
            printf("%d ", q.front->next->data);
            q.front = q.front->next;
        }

        printf("\n");
    }
}

int main()
{
    Queue q1;
    initQueue(&q1);

    enqueue(&q1, 1);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);
    enqueue(&q1, 2);

    printQueue(q1);

    printf("%d ", dequeue(&q1));
    printf("%d ", dequeue(&q1));
    printf("%d \n", dequeue(&q1));

    printQueue(q1);

    return 0;
}