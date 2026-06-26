#include<stdio.h>
int main()
{
int n,i,h,v;
scanf("%d",&n);
int a[n],b[n];
for(i=0;i<n;i++)
{
    a[i]=i+1;
    b[i]=i+1;
}
for(i=1;i<=(n*n);i++)
{
    scanf("%d%d",&h,&v);
    if(a[h-1]!=0&&b[v-1]!=0)
    {
        printf("%d ",i);
        a[h-1]=0;
        b[v-1]=0;
    }
}
}