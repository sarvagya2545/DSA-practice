#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char* letters, char* prefix, int n, int k) {
  if(k == 0) {
    printf("%s\n", prefix);
    return;
  }

  for(int i = 0; i < n; i++) {
    char *newPrefix;
    newPrefix = malloc((n - k + 1) * sizeof(*newPrefix));
    const char *s1 = &letters[i];
    strcat(prefix, s1);
    strcpy(newPrefix, prefix);
    print(letters, newPrefix, n, k - 1);
  }
}

int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);

  // init character array to store n distinct characters
  char* letters;
  letters = malloc(n * sizeof(*letters));
  scanf("%s", letters);

  // printf("%s", letters);

  print(letters, "", n, k);
}