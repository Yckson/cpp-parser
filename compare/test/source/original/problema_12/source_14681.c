#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
int i,n,a[2501],b[2501],c[2501],d[2501],l,v;
scanf("%d",&n);
for(i=1;i<=n*n;i++)
{
	c[i]=0;
	d[i]=0;
	scanf("%d %d",&a[i],&b[i]);
}
for(i=1;i<=n*n;i++)
{
if(c[a[i]]==0 && d[b[i]]==0)	
{
//	printf("c[%d]->%d c[%d]->%d",a[i],b[i],c[a[i]],d[b[i]]);
	c[a[i]]=1;
	d[b[i]]=1;
	printf("%d ",i);
}
}
	return 0;
}