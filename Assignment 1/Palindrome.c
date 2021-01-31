#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head = NULL;
struct Node* el = NULL;
struct Node* prev = NULL;

int isPalindrome(struct Node * head, struct Node * tail, int n) {
  if(n%2) {
    // if n is odd
    while(head != tail) {
      if(head -> data != tail -> data) {
        return 0;
      }

      head = head -> next;
      tail = tail -> prev;
    }
  } else {
    // if n is even
    int i = 0;
    while(i <= n/2) {
      if(head -> data != tail -> data) {
        return 0;
      }

      head = head -> next;
      tail = tail -> prev;
      i++;
    }
  }

  return 1;
}

int main() {
  int n;
  scanf("%d\n", &n);
  int length = n;
  char c;
  while(n--) {
    scanf("%c", &c);
    el = (struct Node *) malloc(sizeof(struct Node));
    el -> data = c;
    if(head == NULL) {
      head = el;
    } else {
      prev -> next = el;
      el -> prev = prev;  
    }
    
    prev = el;
  }

  // el is the last element here.
  if(isPalindrome(head, el, length)){
    printf("PALINDROME\n");
  } else {
    printf("NOT A PALINDROME\n");
  }

  return 0;  
}