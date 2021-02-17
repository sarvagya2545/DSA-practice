#include<stdio.h>

int solve(int n)
{
    int pow=1;
    while(pow<n)
    {
        pow*=2;
    }
    pow/=2;
    return solve(n-pow);
}

void main()
{
    int n,ans;
    scanf("%d",&n);
    ans=solve(n);
    printf("%d",scanf);
    return;
}