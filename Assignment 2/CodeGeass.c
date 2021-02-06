#include <stdio.h>
#include <stdlib.h>

// ALL HAIL LELOUCH!!!

int main() {

  long long m,n;

  scanf("%lld", &n);
  scanf("%lld", &m);

  long long *knightmares; 
  long long *powers;

  knightmares = malloc(n * sizeof(*knightmares));
  powers = malloc(m * sizeof(*powers));

  for(long long i = 0; i < n; i++) {
    scanf("%lld", &knightmares[i]);
  }

  for(long long i = 0; i < m; i++) {
    scanf("%lld", &powers[i]);
  }

  for(long long i = 0; i <= n - m; i++) {
    for(long long j = 0; j < m; j++) {
      knightmares[j + i] *= powers[j];
    }
  }

  for(long long i = 0; i < n; i++)
    printf("%lld ", knightmares[i]);
}