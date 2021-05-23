#include <stdio.h>
#include <string.h>
int rep(char *m, int l, char *s)
{
    int ans = 0;
    int lr = 0;
    for (int i = 0; i < l; i++)
    {
        if (m[i] == s[lr])
        {
            lr++;
        }
        else
        {
            lr = 0;
        }
        if (lr == strlen(s))
        {
            ans = 1;
            break;
        }
    }
    return ans;
}
void solve()
{
    int n;
    scanf("%d", &n);
    int winner = 0;
    int dec = 0;
    char prev;
    char m[1000000] = "";
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        char s[10];
        scanf("%s", s);
        if (i != 0 && dec == 0 && prev != s[0])
        {
            dec = 1;
            winner = i % 2;
        }
        if (dec == 0 && rep(m, l, s) == 1)
        {
            dec = 1;
            winner = i % 2;
        }
        prev = s[strlen(s) - 1];
        strcat(m, s);
        l += strlen(s);
    }
    if (dec == 0)
    {
        winner = n % 2;
    }
    if (winner)
    {
        printf("Alice");
    }
    else
    {
        printf("Bob");
    }
}
int main()
{
    solve();
}
