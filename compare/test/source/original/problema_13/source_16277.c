#include<stdio.h>
int main()
{
    int n,i,change=0,x=0,t=0,a[1001];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(t!=n)
    {

    for(i=1;i<=n;i++)
    {
        if(x>=a[i])
        {
            x++;
            a[i]=(n+1);
            t++;
        }
    }
  if(t!=n)
    {
        change++;
    }


    for(i=n;i>=1;i--)
    {
        if(x>=a[i])
        {
            x++;
            a[i]=(n+1);
            t++;
        }
    }
  if(t!=n)
    {
        change++;
    }
    }

    printf("%d",change);
    return 0;
}