#include<stdio.h>

void main()
{
    int n,w=-1,l=-1,num,u,v;
    scanf("%d",&n);
    num=n*(n-1);
    num/=2;
    num--;
    int arr[n+1][2];
    for(int i=0;i<n+1;i++)
    {
        arr[i][0]=0;
        arr[i][1]=0;
    }
    for(int i=0;i<num;i++)
    {
        scanf("\n%d %d",&u,&v);
        arr[u][0]++;
        arr[v][1]++;
    }
    for(int i=1;i<n+1;i++)
    {
        if(arr[i][0]+arr[i][1]!=n-1)
        {
            if(w==-1)
                w=i;
            else
                l=i;
        }
    }
    /*if(arr[w][0]==arr[l][0]&&arr[w][1]==arr[l][1])
    {
        printf("%d %d",w,l);
        return;
    }*/ //commented out becuase can't determine case is already included
    arr[w][0]++;
    arr[l][1]++;
    for(int i=1;i<n+1;i++)
    {
        if(i!=w&&arr[w][0]==arr[i][0])
        {
            printf("%d %d",l,w);
            return;
        }
    }
    printf("%d %d",w,l);
    return;
}