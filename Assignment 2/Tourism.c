#include <stdio.h>
#include <stdlib.h>

// dfs traversal
int traverse(int** graph, int v, int sv, int* visited) {
  int visitedislands = 1;
  visited[sv] = 1;
  // PRINTING VISITED ARRAY FOR DEBUG
  // printf("visited array => ");

  // for(int i = 0; i < v; i++) {
  //   printf("%d", visited[i]);
  // }

  // printf("\n");

  for(int i = 0; i < v; i++) {
    if(i == sv)
      continue;
    
    if(graph[sv][i] == 1) {
      if(visited[i])
        continue;
      
      visitedislands += traverse(graph, v, i, visited);
      // printf("HERE => %d\n", visitedislands);
    }
  }
  return visitedislands;
}

void printGraph(int** graph, int v) {
  for(int i = 0; i < v; i++){
    for(int j = 0; j < v; j++){
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}

int maxVisitedIslands(int** graph, int v) {
  int maxVisitedIslands = 0;
  
  for(int i = 0; i < v; i++) {
    int* visited;

    // allocate memory
    visited = malloc(v * sizeof(visited));

    for(int i = 0; i < v; i++)
      visited[i] = 0;

    for(int i = 0; i < v; i++) {
      int visitedIslands = traverse(graph, v, i, visited);
      // printf("visitedIslands => %d\n", visitedIslands);
      maxVisitedIslands = maxVisitedIslands < visitedIslands ? visitedIslands : maxVisitedIslands;
    }

    free(visited);

    return maxVisitedIslands;
  }

  printf("\nans => %d\n", maxVisitedIslands);

  return maxVisitedIslands;
}

int main() {
  int e,v;
  scanf("%d", &v);
  scanf("%d", &e);

  int **graph;

  // allocating memory to 2d array (graph)
  graph = malloc(v * sizeof(*graph));
  for (int i = 0; i < v; i++)
    graph[i] = malloc(v * sizeof *graph[i]);

  for(int i = 0; i < v; i++)
    for(int j = 0; j < v; j++)
      graph[i][j] = 0;

  for(int i = 0; i < e; i++) {
    int v1,v2;
    scanf("%d", &v1);
    scanf("%d", &v2);
    graph[v1 - 1][v2 - 1] = 1;
  }

  // printing the graph for debugging
  // printf("---------\n");
  // printGraph(graph, v);
  // printf("---------\n");

  int ans = maxVisitedIslands(graph, v);

  printf("%d", ans);

  // free memory
  for(int i = 0; i < v; i++)
    free(graph[i]);

  free(graph);

  return 0;
}