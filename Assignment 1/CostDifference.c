#include <stdio.h>

#define MAX_COST 250250000000;
#define MIN_COST -250000000000;

// First define extremes.
long long maxCost = MIN_COST;
long long minCost = MAX_COST;

long long getCost(int arr[], int n) {
  long long cost = 0;

  for (int i = 0; i < n; i++) {
    if(i%2 == 0) {
      cost += arr[i] * arr[i];
    } else {
      cost -= arr[i] * arr[i] * arr[i];
    }
  }

  return cost;
}

void rotateLeft(int arr[], int n) {
  int temp = arr[0];

  for(int i = 0; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }

  arr[n - 1] = temp;
}

int main() {
  int n;
  scanf("%d\n", &n);
  int arr[n];

  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int i = n;

  while(i--) {
    rotateLeft(arr, n);
    long long arrayCost = getCost(arr, n);
    if(arrayCost < minCost)
      minCost = arrayCost;
    if(arrayCost > maxCost) 
      maxCost = arrayCost;
  }

  printf("%lld\n", maxCost - minCost);
  return 0;
}