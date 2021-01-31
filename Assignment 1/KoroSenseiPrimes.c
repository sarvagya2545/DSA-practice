#include <stdio.h>
#include <math.h>

int checkIfPrime(int n) {
  int isPrime = 1;

  for(int i = 2; i <= sqrt(n); i++) {
    if(n % i == 0) {
      isPrime = 0;
      break;
    }
  }

  return isPrime;
}

int main() {
  int p,q;
  scanf("%d %d", &p, &q);


  // array with all values 0 counts the frequency of digits
  int arr[10];
  for(int i = 0; i < 10; i++)
    arr[i] = 0;

  // store frequency of every digit in the array
  for(int i = p; i <= q; i++) {
    if(checkIfPrime(i)) {
      // if prime, then count all the digits' frequency
      int num = i;
      while(num > 0) {
        arr[num % 10]++;
        num /= 10;
      }
    }
  }

  // get the max frequency from the array and the index of the array
  int max = 0;
  int index = 0;
  for (int i = 0; i < 10; i++) {
    if (arr[i] > max) {
      index = i;
      max = arr[i];
    }
  }
  printf("%d %d\n", index, max);

  return 0;
}