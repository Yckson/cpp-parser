#include<stdio.h>
int main()
{
    int n,a,b,h[2501],v[2501],count[2501],i;
    scanf("%d",&n);
    for(i=1;i<=n*n;i++)
    {
        h[i]=0;
        v[i]=0;
        count[i]=0;
    }
    for(i=1;i<=n*n;i++)
    {
        scanf("%d %d",&a,&b);
        if(h[a]==0 && v[b]==0)
        {
            count[i]=1;
            h[a]=1;
            v[b]=1;
        }
    }
    for(i=1;i<=n*n;i++)
    {
        if(count[i]==1)
            printf("%d ",i);
    }
    printf("\n");
    return 0;
}