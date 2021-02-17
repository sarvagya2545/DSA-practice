#include <stdio.h>
#include <stdlib.h>

struct Array {
  int *A;
  int capacity;
  int length;
};

// double the size of the array, not to be used by user.
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

// append the item at the end of the array
void Append(struct Array *arr, int x) {
  // if length == capacity, double the capacity of the array
  if(arr->length == arr->capacity)
    doubleSize(arr);
  
  // add the element at the end of the array
  (arr -> A)[arr -> length] = x;
  // increase the length of the element by 1
  arr -> length = arr -> length + 1;
}

// insert the item at the provided index
void Insert(struct Array *arr, int x, int index) {

  if(index > arr->length) {
    printf("\nERROR: You tried to insert %d at the index %d, which exceeds the current size of array, so insert operation aborted.\n", x ,index);

    return;
  }

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

void DeleteAtIndex(struct Array *arr, int index) {
  // if the index >= length - 1, stop executing
  if(index >= arr->length - 1 || index < 0) {
    printf("invalid index");
    return;
  }

  // left shift the items from the index to the end
  for(int i = index; i < arr->length - 1; i++) {
    (arr->A)[i] = (arr->A)[i + 1];
  }

  // decrease the length of the array by 1
  arr->length--;
}

// Find the item and return the index, if not found, return -1;
int Search(struct Array *arr, int x) {
  for(int i = 0; i < arr->length; i++) {
    if((arr->A)[i] == x) {
      return i;
    }
  }

  return -1;
}

// get the item at the current index
int Get(struct Array *arr, int index) {
  return (arr->A)[index];
}

void Set(struct Array *arr, int x, int index) {
  // if the index >= length - 1, stop executing
  if(index >= arr->length - 1 || index < 0) {
    printf("invalid index");
    return;
  }

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

  DeleteAtIndex(&arr, 4);

  printf("\n----\n");
  Display(arr);

  printf("\nSearching item %d, it is at index %d", 5, Search(&arr, 5));
  printf("\nGet item at index %d, it is %d", 3, Get(&arr, 3));

  Set(&arr, 10, 2);

  printf("\n----\n");
  Display(arr);

}