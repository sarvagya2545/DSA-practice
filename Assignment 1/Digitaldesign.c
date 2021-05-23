#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Register operations using an doubly linked list: 
 * 
 * Left shift
 * Right shift
 * Left rotate
 * Right rotate
 * Increment by 1 
 * Decrement by 1
 * 
 * */

struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head = NULL;
struct Node* el = NULL;
struct Node* prev = NULL;

void printList(struct Node* elem) {
  while(1) {
    if(elem == NULL)
      break;
    else {
      printf("%c", elem -> data);
      elem = elem -> next;
    }
  }
}

void leftRotateByOne(struct Node* elem) {
  struct Node* tempHead = NULL;

  // get the data at the head of the linked list and store it.
  tempHead = (struct Node *) malloc(sizeof(struct Node));
  tempHead -> data = elem -> data;

  while (1) {
    if(elem -> next == NULL){
      // in rotation, the first element will come back to the end of the linked list
      elem -> data = tempHead -> data;
      break;
    }

    elem -> data = elem -> next -> data;
    elem = elem -> next;
  }
  
}

void rightRotateByOne(struct Node* elem) {
  struct Node* tail = NULL;
  tail = (struct Node *) malloc(sizeof(struct Node));

  // head element is assigned to tail
  tail = elem;

  // convert the head element to tail.
  while(tail -> next != NULL)
    tail = tail -> next;

  struct Node* tempTail = NULL;
  tempTail = (struct Node *) malloc(sizeof(struct Node));

  // in right rotation, we store the tail's data in a temp var 
  tempTail -> data = tail -> data;

  while(1) {
    if(tail -> prev == NULL) {
      // we set the temp value to the start
      tail -> data = tempTail -> data;
      break;
    }

    tail -> data = tail -> prev -> data;
    tail = tail -> prev;
  }

}

void leftShiftByOne(struct Node* elem) {
  while (1) {
    if(elem -> next == NULL){
      // in shift, the last element always gets a value of 0
      elem -> data = 0;
      break;
    }

    elem -> data = elem -> next -> data;
    elem = elem -> next;
  }
}

void rightShiftByOne(struct Node* elem) {
  struct Node* tail = NULL;
  tail = (struct Node *) malloc(sizeof(struct Node));

  // head element is assigned to tail
  tail = elem;

  // convert the head element to tail.
  while(tail -> next != NULL)
    tail = tail -> next;

  while(1) {
    if(tail -> prev == NULL) {
      // we set the temp value to the start
      tail -> data = 0;
      break;
    }

    tail -> data = tail -> prev -> data;
    tail = tail -> prev;
  }
}

void increaseByOne(struct Node* elem) {
  
  struct Node* head = elem;
  struct Node* temp;
  struct Node* prev = NULL;
  int carry = 1, sum;

  while(elem != NULL) {
    sum = elem -> data + carry;
    carry = sum >= 2 ? 1 : 0;
    sum %= 2;
    elem -> data = sum;

    temp = elem;
    elem = elem -> next;
  }


  
}

void decreaseByOne(struct Node* elem) {

}

int	main() {
  char bit;
  while(1) {
    scanf("%c", &bit);

    if(bit == '\n') {
      break;
    }

    el = (struct Node *) malloc(sizeof(struct Node));
    el -> data = bit;
    if(head == NULL) {
      head = el;
    } else {
      prev -> next = el;
      el -> prev = prev;  
    }
    
    prev = el;
  }

  printList(head);

  int n;
  int st = 0;
  scanf("%d", &n);

  while(n--){
    char s[3];
    scanf("%s", s);

    if(!strncmp(s, "LS", 2)) {
      leftShiftByOne(head);
    } else if(!strncmp(s, "LR", 2)) {
      leftRotateByOne(head);
    } else if(!strncmp(s, "RS", 2)) {
      rightShiftByOne(head);
    } else if(!strncmp(s, "RR", 2)) {
      rightRotateByOne(head);
    } else if(!strncmp(s, "INC", 3)) {
      increaseByOne(head);
    } else if(!strncmp(s, "DEC", 3)) {
      decreaseByOne(head);
    }
  }


  printList(head);

  return 0;
}
