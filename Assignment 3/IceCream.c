#include <stdio.h>

int iceCreamsConsumed[10000] = {0};

int isSatisfiable(int x, int a[], int m, int k) {
  int ans = 0;
  do {
    if((a[m - 1] <= x + k) && (a[m - 1] >= x - k) && iceCreamsConsumed[m-1] == 0) {
      ans = 1;
      iceCreamsConsumed[m - 1] = 1;
      break;
    }
  } while(m--);

  return ans;
}

int main() {
  int n, m, k, ans = 0;

  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);

  int kids[n], cones[m];

  for (int i = 0; i < n; i++)
    scanf("%d", &kids[i]);

  for (int j = 0; j < m; j++)
    scanf("%d", &cones[j]);

  for(int i = 0; i < n; i++) {
    if(isSatisfiable(kids[i], cones, m, k)) {
      ans++;
    }
  }

  printf("%d", ans);
}