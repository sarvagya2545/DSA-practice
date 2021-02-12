#include <stdio.h>
#define  ll long long

int main() {
  ll N, k1, k2;

  scanf("%lld %lld %lld", &N, &k1, &k2);

  ll a[N], b[N];

  for(ll i = 0; i < N; i++)
    scanf("%lld", &a[i]);
  
  for(ll i = 0; i < N; i++)
    scanf("%lld", &b[i]);

  ll cnt = 0;

  for(ll i = 0; i < N; i++) 
    for(ll j = i + 1; j < N; j++) 
      if(a[i] + a[j] + k1 > b[i] + b[j] + k2) 
        cnt++;

  printf("%lld", cnt);

}