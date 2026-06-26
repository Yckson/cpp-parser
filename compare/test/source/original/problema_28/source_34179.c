#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i,j,c=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		c++;
		if(a[i-1]==1&&a[i]==0&&a[i+1]==1)
		c++;
	}
	printf("%d",c);
	return 0;
}