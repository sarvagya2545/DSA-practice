#include <stdio.h>

int main() {
  int N, x, pos;
  scanf("%d%d%d", &N, &x, &pos);
  long long fact = 1;
  int a = N - 1, c;
  for ( c = 1; c <= a; c++)
    fact = fact*c;

  long long ans = fact % 1000000007; 

  printf("%lld", ans);
}