#include <stdio.h>
#include <string.h>
char arr[5] = {"\0"};
int count = 0;
int fd(int ans, int no)
{
  count++;
  return ans + no;
}
int loop(int ans, int no)
{
  count++;
  int anstemp = 0;
  while (1)
  {
    scanf("%s", arr);
    if (strcmp(arr, "FD") == 0)
    {
      int k;
      scanf("%d", &k);
      anstemp = fd(anstemp, k);
    }
    else if (strcmp(arr, "LOOP") == 0)
    {
      int k;
      scanf("%d", &k);
      anstemp = loop(anstemp, k);
    }
    else
    {
      count++;
      break;
    }
  }

  return ans + anstemp * no;
}
int main()
{
  int n, ans = 0;
  scanf("%d", &n);
  while (count != n)
  {
    scanf("%s", arr);
    if (strcmp(arr, "FD") == 0)
    {
      int k;
      scanf("%d", &k);
      ans = fd(ans, k);
    }
    else if (strcmp(arr, "LOOP") == 0)
    {
      int k;
      scanf("%d", &k);
      ans = loop(ans, k);
    }
    if (count == n)
    {
      break;
    }
  }
  printf("%d", ans);
}