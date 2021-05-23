#include<stdio.h>

int numGreater = 0;
int numLesser = 0;

int fact(int n) {
  if(n == 1) 
    return 1;
  else 
    return n * fact(n-1);
}

int noOfArr(int x, int l, int r, int pos, int k) {
  int mid = (l + r) / 2;

  if(mid == pos) {
    return fact(k);
  } else if(pos < mid) {
    numLesser--;

    return (numLesser + 1) * fact(r - mid) * noOfArr(x, l, mid - 1, pos, k/2 - 1);
  } else {
    numGreater--;

    return (numGreater + 1) * fact(mid - l - 1) * noOfArr(x, l, mid - 1, pos, k/2);
  }
}

int main() {
  int N, x, pos;

  scanf("%d", &N);
  scanf("%d", &x);
  scanf("%d", &pos);

  numGreater = N - x;
  numLesser = x - 1;

  int ans = noOfArr(x, 0, N - 1, pos, N - 1);

  printf("%d", ans);
}