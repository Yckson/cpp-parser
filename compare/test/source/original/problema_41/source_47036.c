#include <stdio.h>

int main(void) {
	int n,a[100000],b[100000],c=0,min,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d %d",&a[i],&b[i]);}
	c=a[0]*b[0];
	min=b[0];
	for(i=1;i<n;i++)
	{ if(b[i]<min)
	   {min=b[i];}
	   c=c+ a[i]*min;}
	   printf("%d",c);
	return 0;
}