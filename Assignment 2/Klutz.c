#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

int max(int a,int b){
  return a > b? a : b;
}

int cnt = 0;

struct AdjListNode { 
  int dest;
  struct AdjListNode* next;
};

struct AdjList { 
  struct AdjListNode *head;  
}; 
  

struct Graph {
  int V; 
  struct AdjList* array; 
}; 

struct AdjListNode* newAdjListNode(int dest) { 
  struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
  newNode->dest = dest;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int V) { 
  struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
  graph->V = V;
  graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
  
  int i; 
  for (i = 0; i < V; ++i) 
    graph->array[i].head = NULL; 
  
  return graph; 
} 
  

void addEdge(struct Graph* graph, int src, int dest) { 
  struct AdjListNode* newNode = newAdjListNode(dest); 
  newNode->next = graph->array[src].head; 
  graph->array[src].head = newNode; 
  //newNode = newAdjListNode(src); 
  //newNode->next = graph->array[dest].head; 
  //graph->array[dest].head = newNode; 
}

void printGraph(struct Graph* graph) { 
  int v; 
  for (v = 0; v < graph -> V; ++v) { 
    struct AdjListNode* pCrawl = graph->array[v].head; 
    printf("\n Adjacency list of vertex %d\n head ", v); 
    while (pCrawl) { 
        printf("-> %d", pCrawl->dest); 
        pCrawl = pCrawl->next; 
    } 
    printf("\n");
  } 
} 

    
void dfs(bool vis[],int n,struct Graph* graph) { 
  vis[n]=1;
  struct AdjListNode* pCrawl = graph -> array[n].head;

  while (pCrawl) {
    int k = (pCrawl) -> dest;

    if(vis[k]==0)
      dfs(vis,k,graph);

    pCrawl = pCrawl->next; 
  }
}

int main() {
  int n,m;
  scanf("%d",&n);
  m = (n * (n - 1) / 2) - 1;
  //Remember n++ here coz in this que graph indexing is not 0 indexing..so make sure u dont consider first (0) node as part of the graph .. the first node is 1
  n++;
  int see[n];
  bool vis[n];

  for(int i = 0; i < n; i++) {
    see[i] = 0;
    vis[i] = false;
  }
  
  struct Graph* graph = createGraph(n); 

  while(m--) {
    int a,b;
    scanf("%d %d", &a, &b);
    see[a]++;
    see[b]++;
    addEdge(graph, a, b);
  }

  int n1 = -1,n2 = -1;

  for(int i = 1; i < n; i++) {
    if(see[i] == n - 3) {
      if(n1 == -1) {
        n1 = i;
        continue;
      }

      if(n2 == -1) {
        n2 = i;
        break;
      }
    }
  }

  //printGraph(graph);
  //printf("%d %d",n1,n2);

  dfs(vis,n1,graph);

  if(vis[n2] == 1){
    printf("%d %d", n1, n2);
  } else {
    printf("%d %d", n2, n1);
  }

  return 0; 
}