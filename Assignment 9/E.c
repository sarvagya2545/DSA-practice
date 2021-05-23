#include <stdio.h>
#include <stdlib.h>
#define N 123000

typedef struct Nodetype
{
    int data;
    struct Nodetype *next;
} Node;

Node *adj_list[N];
int dist[N];

void add(int idx, int pos)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->data = idx;
    if (adj_list[pos])
        node->next = adj_list[pos];
    adj_list[pos] = node;
}

int dp[N];
void dfs(int x)
{
    dp[x] = 1;
    Node *head = adj_list[x];
    while (head)
    {
        int it = head->data;
        if (dp[it] == 0)
        {
            dfs(it);
            dp[x] += dp[it];
        }
        head = head->next;
    }
}

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    x--, y--;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        u--, v--;
        add(u, v);
        add(v, u);
    }
    dfs(x);
    long long ans = 1LL * n * (n - 1) - 1LL * (n - dp[y]) * dp[y];
    printf("%lld", ans);
    return 0;
}