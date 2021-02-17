#include <stdio.h>
#include <stdlib.h>

struct Array {
  int *A;
  int capacity;
  int length;
};

void Display(struct Array arr) {
  for(int i = 0; i < arr.length; i++)
    printf("%d ", arr.A[i]);
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

}