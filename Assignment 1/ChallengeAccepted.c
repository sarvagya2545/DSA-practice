#include <stdio.h>

// baababbaab
int main()
{
  /**
   * n -> number of items in the string,
   * found -> flag
   * index -> index of traversal in string
   * pos -> number of characters of 'baab' already matched
  */
  int n, found = 0, index = 0, pos = 0;
  char c;
  scanf("%d", &n);

  while (index <= n + 1)
  {

    scanf("%c", &c);
    index++;

    if ((c == 'b' && pos == 0) || (c == 'a' && pos == 1) || (c == 'a' && pos == 2))
    {
      pos++;
    }
    else if (c == 'b' && pos == 3)
    {
      if (!found)
      {
        printf("YES");
        found = 1;
      }
      printf(" %d", index - 4);
      pos = 1;
    }
    else
    {
      if (c == 'b')
        pos = 1;
      else
        pos = 0;
    }
  }

  if (!found)
    printf("NO");
}