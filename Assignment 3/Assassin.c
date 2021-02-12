#include <stdio.h>
#define ll long long

struct Noble {
  ll bodygaurdskill;
  ll goldamount;
};

int main() {
  ll n,m,x,y;
  scanf("%lld", &n);
  scanf("%lld", &m);
  ll assassinSkill[n];
  ll maxgold[n];
  struct Noble nobles[m];

  for(int i = 0; i < n; i++) {
    scanf("%lld", &assassinSkill[i]);
  }

  for(int i = 0; i < m; i++) {
    scanf("%lld", &x);
    scanf("%lld", &y);

    nobles[i].bodygaurdskill = x;
    nobles[i].goldamount = y;
  }

  for(int i = 0; i < n; i++)
    maxgold[i] = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(assassinSkill[i] >= nobles[j].bodygaurdskill) {
        maxgold[i] += nobles[j].goldamount;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    printf("%lld ", maxgold[i]);
  }

}