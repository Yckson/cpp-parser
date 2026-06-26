#include<stdio.h>
#include<math.h>
int main( )
{
	int n,a[101],i,j,k,c=0,l=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			c+=1;
		}
	}
	for(i=1;i<n-1;i++)
	{
		if((a[i]==0)&&(a[i-1]==1)&&(a[i+1]==1))
		{
			c+=1;
		}
	}
	printf("%d\n",c);
	return 0;
}