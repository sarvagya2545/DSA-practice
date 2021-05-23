#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *head;
struct Node *tail;
struct Node *el;

void createNode(char c)
{
    // create unlinked node
    el = (struct Node *)malloc(sizeof(struct Node));
    el->data = c;
    el->left = el->right = NULL;

    // link the node
    if (head == NULL || tail == NULL)
    {
        head = el;
        tail = el;
        return;
    }

    tail->right = el;
    el->left = tail;
    tail = el;
}

int main()
{
    int n;
    char c;
    scanf("%d\n", &n);

    // // take input
    while (n--)
    {
        scanf("%c ", &c);
        createNode(c);
    }

    // printLL();

    // if n is odd
    if (n % 2)
    {
        while (head != tail)
        {
            printf("%c %c", head->data, tail->data);
            if (head->data != tail->data)
            {
                printf("NOT A PALINDROME");
                return 0;
            }

            head = head->right;
            tail = tail->left;
        }
    }
    else
    {
        for (int i = 0; i <= n / 2; i++)
        {
            if (head->data != tail->data)
            {
                printf("NOT A PALINDROME");
                return 0;
            }

            head = head->right;
            tail = tail->left;
        }
    }

    printf("PALINDROME");

    return 0;
}