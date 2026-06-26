#include<stdio.h>

int c[60],d[60];

int main()

{
    int n,i,j,k,a[3000],b[3000],x,y;
    scanf("%d",&n);
    for(i=0;i<(n*n);i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i=0;i<(n*n);i++)
    {
        x=a[i],y=b[i];
        if(a[i]!=c[x]&&b[i]!=d[y])
        {
            printf("%d ",i+1);
            c[x]=a[i];
            d[y]=b[i];
        }
    }
}