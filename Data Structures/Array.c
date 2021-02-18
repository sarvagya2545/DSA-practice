#include <stdio.h>
#include <stdlib.h>

struct Array {
  int *A;
  int capacity;
  int length;
};

void swap(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

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

void bubbleSort(struct Array *arr) {
  for(int i = 0; i < arr->length; i++)
    for(int j = i + 1; j < arr->length; j++)
      if(arr->A[i] > arr->A[j])
        swap(&(arr->A)[i], &(arr->A)[j]);
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

int linearSearch(struct Array *arr, int x) {
  for(int i = 0; i < arr->length; i++) {
    if((arr->A)[i] == x) {
      return i;
    }
  }

  return -1;
}

// binary searcj using loops
int binarySearch(struct Array *arr, int x) {
  int l = 0;
  int r = arr->length - 1;
  while(1) {
    int mid = (l + r) / 2;

    if(l > r) {
      return -1;
    }
    
    int midElement = (arr->A)[mid];

    if(x == midElement) {
      return mid;
    } else if(x > midElement) {
      l = mid + 1;
    } else if(x < midElement) {
      r = mid - 1;
    }
  }
}

// recursive binary search
int rBinarySearch(struct Array *arr, int x, int l, int r) {
  int mid = (l + r) / 2;

  int midElement = (arr->A)[mid];

  if(x == midElement) {
    return mid;
  } else if(x > midElement) {
    return rBinarySearch(arr, x, mid + 1, r);
  } else {
    return rBinarySearch(arr, x, l, mid - 1);
  }
}

// Find the item and return the index, if not found, return -1;
int getIndex(struct Array *arr, int x) {
  return linearSearch(arr, x);
}

// reverse the array
void reverse(struct Array *arr) {

  int len = arr->length;

  for(int i = 0; i < len/2; i++)
    swap(&(arr->A)[i], &(arr->A)[len - i - 1]);
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

  printf("\nSearching item %d, it is at index %d", 5, getIndex(&arr, 5));
  printf("\nGet item at index %d, it is %d", 3, Get(&arr, 3));

  Set(&arr, 10, 2);

  printf("\n----\n");
  Display(arr);

  printf("sorting array");
  bubbleSort(&arr);

  printf("\n----\n");
  Display(arr);
}