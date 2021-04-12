#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

struct Node *createNode(int data)
{
    struct Node *el = (struct Node *)malloc(sizeof(struct Node));
    el->data = data;
    el->next = NULL;
    return el;
}

// struct LinkedList {
//     struct Node* head;
//     struct Node* tail;
// };

struct Node *create(int arr[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return first;
}

void print(struct Node *it)
{
    while (it != NULL)
    {
        printf("%d ", it->data);
        it = it->next;
    }

    printf("\n");
}

// print but recursively
void rPrint(struct Node *it)
{
    if (it == NULL)
    {
        printf("\n");
        return;
    }

    printf("%d ", it->data);
    rPrint(it->next);
}

// print the linked list in a reverse order
void rPrintReverse(struct Node *it)
{
    if (it != NULL)
    {
        rPrintReverse(it->next);
        printf("%d ", it->data);
    }
}

int countItems(struct Node *it)
{
    int cnt = 0;
    while (it != NULL)
    {
        cnt++;
        it = it->next;
    }
    return cnt;
}

int sumOfAllItems(struct Node *it)
{
    int sum = 0;
    while (it != NULL)
    {
        sum += it->data;
        it = it->next;
    }
    return sum;
}

int maxValue(struct Node *it)
{
    int max = INT32_MIN;
    while (it != NULL)
    {
        max = max < it->data ? it->data : max;
        it = it->next;
    }

    return max;
}

// returns the index of the value
int search(struct Node *it, int num)
{
    int index = 0;
    while (it != NULL)
    {
        if (it->data == num)
            return index;
        index++;
        it = it->next;
    }
    return -1;
}

// insert a node at a specified location
void insertAt(struct Node **it, int val, int index)
{
    if (index < 0 || index > countItems(*it))
        return;

    struct Node *head = *it;
    struct Node *el = (struct Node *)malloc(sizeof(struct Node));
    el->data = val;

    // insert at head
    if (index == 0)
    {
        el->next = (*it);
        head = el;
        *it = head;
        return;
    }

    int i = 0;
    while (i != index - 1)
    {
        (*it) = (*it)->next;
        i++;
    }
    struct Node *temp = (*it)->next;
    (*it)->next = el;
    el->next = temp;

    *it = head;
}

// insert while assuming that the list is sorted
void SortedInsert(struct Node **head, int val)
{
    struct Node *el = (struct Node *)malloc(sizeof(struct Node));
    el->data = val;
    el->next = NULL;

    struct Node *p = *head;
    struct Node *q = NULL;

    if ((*head)->data > val)
    {
        el->next = *head;
        *head = el;
        return;
    }

    while (p && p->data < val)
    {
        q = p;
        p = p->next;
    }

    struct Node *t = q->next;
    q->next = el;
    el->next = t;
}

void deleteAtIndex(struct Node **ptrHead, int index)
{
    int cnt = 0;
    struct Node **p = ptrHead;
    struct Node *temp = *ptrHead;

    if (index < 0)
    {
        printf("Invalid index\n");
        return;
    }

    // remove ptrHead
    if (index == 0)
    {
        if ((*ptrHead) == NULL)
            return;
        (*ptrHead) = (*ptrHead)->next;

        return;
    }

    // find the item at the index, p points to the node before the node being deleted
    while (cnt < index - 1)
    {
        if ((*p)->next == NULL)
        {
            printf("INVALID INDEX\n");
            return;
        }

        (*p) = (*p)->next;
        cnt++;
    }

    (*p)->next = (*p)->next->next;
    (*ptrHead) = &(*temp);
}

// CHeck if linked list is sorted
bool isSorted(struct Node *head)
{
    struct Node *it = head;
    while (it->next != NULL)
    {
        if (it->data > it->next->data)
        {
            return 0;
        }

        it = it->next;
    }

    return 1;
}

// Remove duplicates from a sorted linked list
void removeDuplicates(struct Node **head)
{
    struct Node **it = head;
    struct Node *temp = *head;

    while ((*it)->next != NULL)
    {
        if ((*it)->data == (*it)->next->data)
        {
            (*it)->next = (*it)->next->next;
            continue;
        }

        (*it) = (*it)->next;
    }

    *head = temp;
}

// reverse the linked list(Sliding pointers)
void reverse(struct Node **head)
{
    // sliding pointers method. change the next pointer reference of the middle one to the prev and move each of them forward
    struct Node *p = *head;
    struct Node *q = NULL;
    struct Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    *head = q;
}

// reverse linked list using recursion
void rReverse(struct Node *p, struct Node *q, struct Node **head)
{
    // store head pointer value as p everytime to get to the end of the list
    (*head) = p;

    // recursively call the function until p is the final element of the list
    if (p->next != NULL)
    {
        rReverse(p->next, p, head);
    }

    // now since we have two nodes, point from one node to the next in the reverse order.
    p->next = q;
}

// concatenate 2 linked lists
// append ll2 at the end of ll1 and return
void concat(struct Node *ll1, struct Node *ll2)
{
    struct Node *head = ll1;

    while (ll1->next != NULL)
    {
        ll1 = ll1->next;
    }

    ll1->next = ll2;
}

// NOTE: merges the linked lists but destroys the previous linked lists
// merge two sorted linked lists => return a new ll which is sorted
struct Node *merge(struct Node *ll1, struct Node *ll2)
{
    struct Node *ll3, *tail;

    if (ll1->data > ll2->data)
    {
        ll3 = tail = ll2;
        ll2 = ll2->next;
        tail->next = NULL;
    }
    else
    {
        ll3 = tail = ll1;
        ll1 = ll1->next;
        tail->next = NULL;
    }

    while (ll1 && ll2)
    {
        if (ll1->data < ll2->data)
        {
            tail->next = ll1;
            tail = tail->next;
            ll1 = ll1->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = ll2;
            tail = tail->next;
            ll2 = ll2->next;
            tail->next = NULL;
        }
    }

    if (ll1)
        tail->next = ll1;
    if (ll2)
        tail->next = ll2;

    return ll3;
}

// try to not destroy the previous linked lists
struct Node *merge2(struct Node *ll1, struct Node *ll2)
{

    if (!ll1)
        return ll2;
    if (!ll2)
        return ll1;
    struct Node *ll3, *tail, *el;
    ll3 = (struct Node *)malloc(sizeof(struct Node));
    tail = ll3;

    if (ll1->data < ll2->data)
    {
        ll3->data = ll1->data;
        ll1 = ll1->next;
    }
    else
    {
        ll3->data = ll2->data;
        ll2 = ll2->next;
    }

    while (ll1 && ll2)
    {
        el = (struct Node *)malloc(sizeof(struct Node));

        if (ll1->data < ll2->data)
        {
            el->data = ll1->data;
            ll1 = ll1->next;
        }
        else
        {
            el->data = ll2->data;
            ll2 = ll2->next;
        }

        tail->next = el;
        tail = el;
    }

    if (ll1)
        tail->next = ll1;
    if (ll2)
        tail->next = ll2;

    return ll3;
}

// check to see if the linked list is looping or not.
bool isLoop(struct Node *head)
{
    bool isLoop = false;
    struct Node *p1, *p2;
    p1 = p2 = head;

    while (p1 && p2)
    {
        p1 = p1->next;
        p2 = p2->next->next;

        if (p1 == p2)
        {
            isLoop = true;
            break;
        }
    }

    return isLoop;
}

int main()
{
    int A[] = {0, 2, 4, 5, 7, 9, 13};
    int B[] = {1, 3, 6, 8, 10, 11, 12, 14, 15, 16};
    int n = sizeof(A) / sizeof(int);
    int m = sizeof(B) / sizeof(int);
    struct Node *ll1 = create(A, n);
    struct Node *ll2 = create(B, m);

    // print(ll1);
    // rPrint(ll1);
    // rPrintReverse(ll1);
    // printf("%d",countItems(ll1));
    // printf("%d",search(ll1, 2));

    print(ll1);
    print(ll2);

    // SortedInsert(&ll1, -1);
    // deleteAtIndex(ll1, 2);
    // deleteAtIndex(ll1, 4);
    // deleteAtIndex(&ll1, 4);

    // removeDuplicates(&ll1);
    // rReverse(ll1, NULL, &ll1);

    // concat(ll1, ll2);

    struct Node *ll3 = merge2(ll1, ll2);

    print(ll1);
    print(ll2);

    print(ll3);

    return 0;
}