#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct graph {
  int numVertices;
  struct node** adjLists;
};

void pushEdgeIntoGraph() {

}

int main() {
  int e, v, s, t;


  scanf("%d", &v);
  scanf("%d", &e);
  scanf("%d", &s);
  scanf("%d", &t);

  struct graph* flights;
  flights = malloc(sizeof(struct graph));

  for(int i = 0; i < e; i++) {
    int t1,t2;
    scanf("%d", &t1);
    scanf("%d", &t2);

    pushEdgeIntoGraph();
  }
}