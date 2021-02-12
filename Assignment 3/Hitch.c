#include <stdio.h>

int main() {
  int N,M;
  scanf("%d", &M);
  scanf("%d", &N);

  int places[M], budget[N], choices[N];

  for(int i = 0; i < M; i++)
    scanf("%d", &places[i]);

  for(int i = 0; i < N; i++)
    scanf("%d", &budget[i]);

  for(int i = 0; i < N; i++) 
    choices[i] = 0;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(places[j] <= budget[i])
        choices[i]++;
    }
  }

  for(int i = 0; i < N; i++)
    printf("%d ", choices[i]);
}