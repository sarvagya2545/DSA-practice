#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 
 * 1. size: stack's maximum size or capacity
 * 2. *s: pointer pointing to an array 
 * 3. top: the variable pointing to the last element on the stack
 * 
 * */
struct Stack
{
    int size;
    int *s;
    int top;
};

// initialize stack
struct Stack initStack(int size)
{
    // snippet for stack not using pointers
    struct Stack st;
    st.size = size;
    st.s = (int *)malloc(st.size * sizeof(int));
    st.top = -1;

    // snippet for stack using pointers
    struct Stack *st1;
    // (*st1).size = size;
    // (*st1).s = (int *)malloc((*st1).size * sizeof(int));
    // (*st1).top = -1; // because there are no elements in stack currently

    return st;
}

// check if the stack is full
bool isEmpty(struct Stack *st)
{
    return (*st).top == -1;
}

// check if the stack is empty
bool isFull(struct Stack *st)
{
    return (*st).top == (*st).size - 1;
}

// print the entire stack contents to the screen
void printStack(struct Stack *st)
{
    for (int i = 0; i <= (*st).top; i++)
    {
        printf("%d ", (*st).s[i]);
    }
}

// push data into the stack
void push(struct Stack *st, int data)
{
    if (!isFull(st))
    {
        // (*st) is derefencing the passed stack pointer
        // (*st).s is the array
        // (*st).s[index] => index is ++(*st).top
        // ++(*st).top means we get the top value from the stack and increment it.
        // the incremented top value is now used as an index to push data in the stack
        (*st).s[++(*st).top] = data;

        /**
         * simplified version: 
         * 
         * int index = ++(*st).top;
         * (*st).s[index] = data;
         * 
         * */
    }
    else
    {
        printf("Stack overflow");
    }
}

// remove the top data and return it
int pop(struct Stack *st)
{
    if (!isEmpty(st))
    {
        int val = (*st).s[(*st).top];
        (*st).top--;
        return val;
    }
    else
    {
        printf("Stack is empty");
        return -1;
    }
}

// check out what data is present at a level from the top of the stack
// index => level from the top of the stack
int peek(struct Stack *st, int index)
{
    // stack array position
    int stackArrPos = (*st).top - index;

    if (index < 0)
    {
        printf("Invalid index value");
        return -1;
    }
    else
    {
        if (stackArrPos >= 0)
            return (*st).s[stackArrPos];
        else
        {
            printf("stack position not defined");
            return -1;
        }
    }
}

// DRIVER CODE
int main()
{
    int size = 6;
    struct Stack st = initStack(size);
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    printStack(&st);
    printf("\n----------\n");
    printStack(&st);
}