#include<stdio.h>

int expo(int n)
{
    int ans=1;
    for(int i=0;i<n;i++)
    {
        ans*=2;
    }
    return ans;
}
void main()
{
    int n,pow=1,l=1;
    int sum;
    scanf("%d\n",&n);
    int arr[n];
    for(int i=0;i<n-1;i++)
    {
        scanf("%d ",&arr[i]);
    }
    scanf("%d",&arr[n-1]);
    for(int i=0;i<n;i++)
    {
        sum+=l*arr[i];
        pow--;
        if(pow==0)
        {
            l++;
            pow=expo(l-1);
        }
    }
    printf("%d",sum);
    return;
}