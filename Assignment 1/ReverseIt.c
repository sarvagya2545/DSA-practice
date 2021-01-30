/**
 * Program to reverse a linked list
 * */

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// The head pointer of the linked list.
struct Node* head = NULL;
// The element pointer of the linked list.
struct Node* el = NULL;
struct Node* prev = NULL;

void printList(struct Node* elem) {
  while(1) {
    if(elem == NULL)
      break;
    else {
      printf("%d ", elem -> data);
      elem = elem -> next;
    }
  }
}

void reverseList(struct Node* h) {
  /**
   * current -> current node
   * before -> a node before the current node (Generally a node which current points to)
   * after -> a node after (Generally a node which points to current)
   */
  struct Node* current = h;
  struct Node* before = h -> next;
  // Note that the last node in a linked list points to NULL.
  struct Node* after = NULL;

  while (1) {
    // reverse the pointer of list
    current -> next = after;

    if(before == NULL) {
      // set the head pointer to current and terminate the loop.
      head = current;
      break;
    }

    // move the all the elements a step ahead.
    after = current;
    current = before;
    before = before -> next;
  }
}

int main() {
  int num;

  head = NULL;

  while (1) {
    // enter a value 
    scanf("%d", &num);

    if(num == -1) {
      el -> next = NULL;
      break;
    }

    // get a new memory space for the element.
    el = (struct Node*) malloc(sizeof(struct Node));
    el -> data = num;
    // If head is not present, set the current element as the head.
    // Else set the next property of the prev element as the current element.
    if(head == NULL) 
      head = el;
    else
      prev -> next = el;

    // Finally, to move forward, we need to set the prev property to the current element.
    prev = el;
  };

  reverseList(head);

  printList(head);
  printf("\n");

  return 0;
}