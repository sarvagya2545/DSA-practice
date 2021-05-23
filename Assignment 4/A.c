#include <stdio.h>

struct Array {
  char *A;
  int length;
  int capacity;
};

void doubleSize(struct Array *arr) {
  char *p;
  int newSize = 2 * arr->capacity;
  p = malloc(newSize * sizeof(char));

  for(int i = 0; i < arr->length; i++) {
    p[i] = arr->A[i];
  }

  arr->A = p;
  free(p);
  arr->capacity = newSize;
}

void inputSorted(struct Array *arr, char c1, char c2) {
  
}

int main() {
  int n;
  scanf("%d", &n);
  struct Array arr;
  
  // initialize array
  arr.capacity = 4;
  arr.length = 0;
  arr.A = malloc(arr.capacity * sizeof(char));

  while(n--) {
    char c1, c2;
    scanf("%c", &c1);
    scanf("%c", &c2);

    inputSorted(&arr, c1,c2);
  }

  return 0;
} 