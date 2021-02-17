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

  // return;
  // add the element at the end of the array
  (arr -> A)[arr -> length] = x;
  arr -> length = arr -> length + 1;
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

  Append(&arr, 3);

  printf("\n----\n");
  Display(arr);

}