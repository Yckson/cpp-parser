#include<stdio.h>
int main()
{
    int a[300],i,j,k=0,n,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m*2;j=j+2)
        {
         scanf("%d %d",&a[j],&a[j+1]);
            if(a[j]==1 || a[j+1]==1)
            {
                k++;
            }
        }
    }
    printf("%d",k);
}