#include<stdio.h>
int main()
{
    int a,b,n;
    scanf("%d %d",&a,&b);
    if(a<b)
    {
       n=a;
       a=0;
       a=b;
       b=0;
       b=n;
    }
    printf("%d %d\n",b,(a-b)/2);
    return 0;
}