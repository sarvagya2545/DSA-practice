#include <stdio.h>

long long cnt[560];

long long comb(long long x) {
    return x * (x - 1) / 2;
}

int main() {    
  long long n, C;
  scanf("%lld",&n);
  scanf("%lld",&C);
  char s[45];
  for (int i = 0; i < 500; ++i) {
    cnt[i] = 0;
  }
  for(long long i = 0; i < n ; ++i) {
    scanf("%s",s);
    cnt[s[0] - '0']++;
  }
  long long ans = 0;
  for(long long i = 0; i <= 556; ++i) {
    long long rem = cnt[i] % C;
    ans += ((comb(cnt[i] / C)) * (C - rem) + comb(cnt[i]/C + 1) * rem);
  }
  printf("%lld", ans);
  return 0;
}