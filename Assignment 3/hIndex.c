#include <stdio.h>

int main() {
  int A, P, C;

  scanf("%d %d %d", &A, &P, &C);

  // list of authors
  int authors[A];
  // h-index of author (minimum no. of citations by an author)
  int hIndex[A];

  for (int i = 0; i < A; i++) {
    authors[i] = 0;
    
  }

  for(int i = 0; i < P; i++) {
    int p;
    scanf("%d", &p);
    authors[p]++;
  }

  int citationGraph[P][P];

  for(int i = 0; i < P; i++)
    for(int i = 0; i < P; i++)
      citationGraph[i][i] = 0;
  

}