#include <stdio.h>
#define ll long long

ll arr[25];
ll maxCount = 0;

int main() {
  ll m,n;
  scanf("%lld", &m);
  scanf("%lld", &n);

  for(int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  // in order to get subsets, we use masking.
  for(ll mask = 0; mask < (1 << n); mask++) {
    // do something with this subset
    ll sum = 0;
    ll count = 0;
    for(int i = 0; i < n; i++) {
      // get individual elements of the subset
      if(mask & (1 << i)) {
        // do something with this number in the subset (i => index)
        sum += arr[i];
        // if pocket money exceeds, return and do not count this subset
        if(sum >= m) 
          break;

        // else count this subset
        count++;
      }

      // if the possibility of items bought exceeds max possibility, update the new max possibility.
      if(count >= maxCount)
        maxCount = count; 
    }
  }
  
  printf("%lld", maxCount);  
  return 0;
}