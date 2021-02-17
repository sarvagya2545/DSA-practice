#include <stdio.h>
#include <stdlib.h>

struct Array {
  int *A;
  int capacity;
  int length;
};

void doubleSize(struct Array *arr) {
  int newSize = arr->capacity * 2;
  int *p;
  p = (int *)malloc(newSize * sizeof(int));

  for(int i = 0; i < arr->length; i++) {
    p[i] = (arr->A)[i];
  }

  arr->A = p;
  free(p);
  arr->capacity = newSize;
}

void Display(struct Array arr) {
  for(int i = 0; i < arr.length; i++)
    printf("%d ", arr.A[i]);
}

void Append(struct Array *arr, int x) {
  // if length == capacity, double the capacity of the array
  if(arr->length == arr->capacity)
    doubleSize(arr);
  
  // add the element at the end of the array
  (arr -> A)[arr -> length] = x;
  // increase the length of the element by 1
  arr -> length = arr -> length + 1;
}

void Insert(struct Array *arr, int x, int index) {
  // if length == capacity, double the capacity of the array
  if(arr->length == arr->capacity)
    doubleSize(arr);

  // copy the elements from the end to shift 1 space right till the index
  for(int i = arr->length; i > index; i--) {
    (arr->A)[i] = (arr->A)[i - 1];
  }

  // increase the length of the array by 1
  arr->length = arr->length + 1;

  // now, at the index, insert the specified number
  (arr->A)[index] = x;
}

int main() {
  struct Array arr;
  scanf("%d", &arr.capacity);

  arr.A = malloc(arr.capacity * sizeof(int));

  scanf("%d", &arr.length);

  for(int i = 0; i < arr.length; i++)
    scanf("%d", &arr.A[i]);

  printf("----\n");
  Display(arr);

  Insert(&arr, 4, 1);
  Insert(&arr, 5, 1);
  Insert(&arr, 7, 0);

  printf("\n----\n");
  Display(arr);

}