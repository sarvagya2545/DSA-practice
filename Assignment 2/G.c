#include<stdio.h>
void main()
{
    int n,b;
    int ans=0;
    scanf("%d\n",&n);
    int arr[n];
    for(int i=0;i<n-1;i++)
        scanf("%d ",&arr[i]);
    scanf("%d\n",&arr[n-1]);
    scanf("%d",&b);
    for(int j=0;j<n;j++)
    {
        if(arr[j]==b)
        {
            arr[j]==0;
            ans++;
        }    
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
            continue;
        int j=i+1;
        int temp=b;
        while(arr[i]+arr[j]!=temp)
        {
            if(j==n-1)
            {
                temp--;
                j=i;
            }
            j++;
        }
        ans++;
        arr[i]=0;
        arr[j]=0;
    }
    printf("%d",ans);
    return;
}