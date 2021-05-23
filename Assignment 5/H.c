#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

int main() {
	int n, i, num, len = 0;
	struct Node* el;
	struct Node* ptr;
	struct Node* ptr1;
	scanf("%d",&n);
	int arr[n];
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	for(i = 1; i <= n; i++) {
		scanf("%d",&num);
		if(i == 1){
            head->data = num;
            head->next = NULL;
            head->prev = NULL;
		} else {
            el = (struct Node*)malloc(sizeof(struct Node));
            el->data = num;
            ptr = head;
            while(ptr != NULL) {
                if((ptr->prev == NULL) && (ptr->data > el->data)){
                    el->prev = NULL;
                    ptr->prev = el;
                    el->next = ptr;
                    head = el;
                    break;
                }
                if((ptr->next == NULL) && (ptr->data < el->data)){
                    el->next = NULL;
                    el->prev = ptr;
                    ptr->next = el;
                    break;
                }
                ptr1 = ptr->next;
                if((ptr->data <= el->data) && (ptr1->data >= el->data)){
                    ptr->next = el;
                    ptr1->prev = el;
                    el->prev = ptr;
                    el->next = ptr1;
                    break;
                }
                ptr = ptr->next;
		    }
	    }
	    ptr = head;
	    if(len % 2 == 0){
	    	for(int j = 0; j < len/2; j++)
	    	    ptr = ptr->next;
	    	arr[len] = ptr->data;
	    	len++;
		} else {
			for(int j = 0; j < len/2; j++)
			    ptr = ptr->next;
			ptr1 = ptr->next;
			arr[len] = (ptr->data + ptr1->data) / 2;
			len++;
		}
	}
	for(i = 0; i < n - 1; i++)
	    printf("%d ", arr[i]);
	printf("%d", arr[i]);
}