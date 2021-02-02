#include <stdio.h>
#include <math.h>

int isprime(int n)
{
int flg = 1;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      flg = 0;
      break;
    }
  }
  return flg;
}

int main()
{
  int a, b;
  int arr[10] = {0};
  scanf("%d %d", &a, &b);
  for (int i = a; i <= b; i++)
  {
    if (isprime(i))
    {
      int k = i;
      while (k > 0)
      {
        arr[k % 10]++;
        k /= 10;
      }
    }
  }
  int mx = 0;
  int ans = 0;
  for (int i = 0; i < 10; i++)
  {
    if (arr[i] > mx)
    {
      mx = arr[i];
      ans = i;
    }
  }
  printf("%d %d", ans, mx);
}