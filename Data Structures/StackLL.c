#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

void printStack(struct Stack *st)
{
    struct Node *it = st->top;

    while (it != NULL)
    {
        printf("%d ", it->data);
        it = it->next;
    }

    printf("\n");
}

void push(struct Stack *st, int num)
{
    // insert the new node on head of the LL
    struct Node *el = (struct Node *)malloc(sizeof(struct Node));
    el->data = num;
    el->next = st->top;
    st->top = el;
}

bool isEmpty(struct Stack *st)
{
    return st->top == NULL;
}

int pop(struct Stack *st)
{
    if (!isEmpty(st))
    {
        struct Node *el = st->top;
        st->top = st->top->next;
        return el->data;
    }
    else
    {
        printf("Stack empty: nothing to pop");
        return -1;
    }
}

int main()
{
    struct Stack s1;
    s1.top = NULL;
    push(&s1, 1);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 2);
    push(&s1, 5);
    push(&s1, 6);
    printStack(&s1);
    pop(&s1);
    printStack(&s1);

    // if (isEmpty(&s1))
    // {
    //     printf("Stack empty");
    // }
    // else
    // {
    //     printf("Stack not empty");
    // }
}