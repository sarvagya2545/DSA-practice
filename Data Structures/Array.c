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

// selection sort
void selectionSort(struct Array *arr) {
  for(int i = 0; i < arr->length; i++)
    for(int j = i + 1; j < arr->length; j++)
      if(arr->A[i] > arr->A[j])
        swap(&(arr->A)[i], &(arr->A)[j]);
}

void bubbleSort(struct Array *arr) {
     for(int i = 0; i < arr->length; i++) {
        int flg = 0;

        for(int j = 0; j < arr->length - 1; j++) {
            if(arr->A[j] > arr->A[j+1]) {
                flg = 1;
                swap(&arr->A[j], &arr->A[j + 1]);
            }   
        }

        if(!flg)
            break;
    }
}

// left rotate array by 1
void leftRotateBy1(struct Array *arr) {
  int leftmostElement = arr->A[0];

  for(int i = 0; i < arr->length - 1; i++)
    arr->A[i] = arr->A[i + 1];

  arr->A[arr->length - 1] = leftmostElement;
}

// left rotate by d elements
void leftRotate(struct Array *arr, int d) {
  // to not repeat rotation when d exceeds array length
  d = d % (arr->length);

  while(d--)
    leftRotateBy1(arr);
}

void rightRotateBy1(struct Array *arr) {
  int rightMostElement = arr->A[arr->length - 1];

  for(int i = arr->length - 1; i > 0; i--) {
    arr->A[i] = arr->A[i - 1];
  }

  arr->A[0] = rightMostElement;
}

// rotate array right d times
void rightRotate(struct Array *arr, int d) {
  d = d % (arr->length);

  while (d--)
    rightRotateBy1(arr);
}

// insert the item at the provided index
void Insert(struct Array *arr, int x, int index) {

  if(index > arr->length || index < 0) {
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
void reverseAll(struct Array *arr) {

  int len = arr->length;

  for(int i = 0; i < len/2; i++)
    swap(&(arr->A)[i], &(arr->A)[len - i - 1]);
}

// reverse a part of the array
void reverse(struct Array *arr, int l, int r) {

  for(int i = l; i < (l+r)/2 ;i++) {
    printf("\nswapping %d %d\n", i, r - (i - l));
    swap(&(arr->A)[i], &(arr->A)[r - (i - l)]);
  }
}

void merge(struct Array *arr, int l, int mid, int r) {
  int lNo = mid - l + 1;
  int rNo = r - mid;

  int R[rNo];
  int L[lNo];

  int i, j, k;

  for(i = 0; i < lNo; i++) {
    L[i] = arr->A[l + i];
  }

  for(int j = 0; j < rNo; j++) {
    R[j] = arr->A[mid + 1 + j];
  }

  i = l;
  j = 0;
  k = 0;

  while(j < lNo && k < rNo) {
    if(L[j] <= R[k]) {
      arr->A[i] = L[j];
      j++;
    } else {
      arr->A[i] = R[k];
      k++;
    }
    i++;
  }

  while (j < lNo) {
    arr->A[i] = L[j];
    j++;
    i++;
  }

  while(k < rNo) {
    arr->A[i] = R[k];
    k++;
    i++;
  }

}

// merge sort
void mergeSort(struct Array *arr, int l, int r) {
  if(l < r) {
    int mid = (l + r)/2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

// partition for quicksort
int partition(struct Array *arr, int l, int h) {
  int pivot = arr->A[l];

  int i = l, j = h;

  printf("\ni at start %d j at start %d\n", i, j);
  printf("pivot => %d\n", pivot);

  while(i < j) {
    do {
      i++;
    } while(arr->A[i] <= pivot);

    do {
      j--;
    } while(arr->A[j] > pivot);

    printf("\ni %d j %d\n", i, j);

    if(i < j) {
      printf("swapped i & j\n");
      swap(&(arr->A)[i], &(arr->A)[j]);
    } 
  }

  printf("swapped l & j\n");
  swap(&(arr->A)[l], &(arr->A)[j]);

  return j;
}

// quick sort
void quickSort(struct Array *arr, int l, int h) {
  if(l < h) {
    int j = partition(arr, l, h);
    printf("\n");
    printf("j => %d\t", j);
    Display(*arr);
    quickSort(arr, l, j);
    quickSort(arr, j + 1, h);
  }
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

  Append(&arr, 5);
  Append(&arr, 7);
  Append(&arr, 8);
  Append(&arr, 9);
  Append(&arr, 1);
  Append(&arr, 6);
  Append(&arr, 3);
  Append(&arr, 4);
  Append(&arr, 8);
  Append(&arr, 2);

  printf("\n----\n");
  Display(arr);

  // mergeSort(&arr, 0, arr.length - 1);
  quickSort(&arr, 0, arr.length);

  printf("\n----\n");
  Display(arr);
}