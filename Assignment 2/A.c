#include<stdio.h>

int div1(int n)
{
    for(int i=n-1;i>1;i--)
    {
        if(n%i==0)
            return i;
    }
    return -1;
}
int div2(int n, int div1)
{
    for(int i=n-1;i>1;i--)
    {
        if(n%i==0&&i!=div1)
            return i;
    }
    return -1;
}

int f(int n)
{
    int divisor1,divisor2;
    divisor1=div1(n);
    divisor2=div2(n,divisor1);
    if(divisor1==-1||divisor2==-1)
    {
        return n;
    }
    return f(divisor1)+f(divisor2);
}
void main()
{
    int n;
    //int div[100000];
    scanf("%d",&n);
    printf("%d",f(n));
    return;
}