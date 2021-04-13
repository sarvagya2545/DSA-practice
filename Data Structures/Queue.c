#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// IMPLEMENT A CIRCULAR QUEUE
struct Queue
{
    int *Q;
    int size;
    int front;
    int rear;
};

void initQueue(struct Queue *q, int size)
{
    q->Q = (int *)malloc((size + 1) * sizeof(int));
    q->size = size;
    // we will always keep 1 space empty in the queue
    q->front = 0;
    q->rear = 0;
}

/**
 * 
 *   0 1 2 3 4 5 x 6
 *             r f   
 *   when front and rear pointers are in this position, no more element can be inserted into the queue
 * */
bool isFull(struct Queue *q)
{
    return (q->rear + 1) % (q->size + 1) == q->front;
}

// when both are equal, the queue is empty
bool isEmpty(struct Queue *q)
{
    return q->rear == q->front;
}

// print the data of the queue
void printQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("....EMPTY QUEUE......");
    }
    else
    {
        printf("\n---\n");
        int i = q->front + 1;
        while (i != (q->rear + 1) % (q->size + 1))
        {
            printf("%d ", q->Q[i]);
            i = (i + 1) % (q->size + 1);
        }
        printf("\n---\n");
    }
}

// insert data into a queue
void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
        printf("Queue is full.");
    else
    {
        // increment index
        q->rear = (q->rear + 1) % (q->size + 1);
        // add value to the new index
        q->Q[q->rear] = val;
    }
}

// remove the data from the queue
int dequeue(struct Queue *q)
{
    int x = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        x = q->Q[q->front + 1];
        q->front = (q->front + 1) % (q->size + 1);
    }

    return x;
}

int main()
{
    struct Queue q1;
    initQueue(&q1, 10);
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);
    enqueue(&q1, 6);
    enqueue(&q1, 7);
    enqueue(&q1, 8);
    enqueue(&q1, 9);
    enqueue(&q1, 10);
    printQueue(&q1);
    printf("%d ", dequeue(&q1));
    printf("%d ", dequeue(&q1));
    printf("%d ", dequeue(&q1));
    printQueue(&q1);
    enqueue(&q1, 10);
    printQueue(&q1);
}