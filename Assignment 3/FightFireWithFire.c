#include <stdio.h>

void dfs(int** graph, int v, int sv, int* visited) {

}

int antivirusDoses() {
  int antivirusDoses = 0;

  
}

int main() {
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);

  // initialize graph
  int graph[N][N];

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      graph[i][j] = 0;

  // input graph
  for(int i = 0; i < M; i++) {
    int n1,n2;
    scanf("%d", &n1);
    scanf("%d", &n2);

    graph[n1][n2] = 1;
    graph[n2][n1] = 1;
  }

  // number of people to infect with antivirus virus
  const int target = ((80 * N) / 100) + 1;

  
  
}