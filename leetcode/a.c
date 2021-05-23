#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* Head;
    struct ListNode* el;
    struct ListNode* prev;
    
    while(l1 -> next != NULL && l2 -> next != NULL) {
        el = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        if(l2 -> next == NULL) {
            el->val = l1->val;
            l1 = l1->next;
        } else if(l1 -> next == NULL) {
            el->val = l2->val;
            l2 = l2->next;
        } else if(l1->val < l2->val) {
            el->val = l1->val;
            l1 = l1->next;
        } else {
            el->val = l2->val;
            l2 = l2->next;
        }
        
        if(Head == NULL) {
            Head = el;
            prev->next = el;   
        }
        prev = el;
    }
    
    return Head;
}

int main() {
       
}