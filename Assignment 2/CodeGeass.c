#include <stdio.h>
#include <stdlib.h>

// ALL HAIL LELOUCH!!!

int main() {

  int m,n;

  scanf("%d", &n);
  scanf("%d", &m);

  int *knightmares; 
  int *powers;

  knightmares = malloc(n * sizeof(*knightmares));
  powers = malloc(m * sizeof(*powers));

  for(int i = 0; i < n; i++) {
    scanf("%d", &knightmares[i]);
  }

  for(int i = 0; i < m; i++) {
    scanf("%d", &powers[i]);
  }

  for(int i = 0; i <= n - m; i++) {
    for(int j = 0; j < m; j++) {
      knightmares[j + i] *= powers[j];
    }
  }

  for(int i = 0; i < n; i++)
    printf("%d ", knightmares[i]);
}