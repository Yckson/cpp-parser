#include<stdio.h>
int main()
{
	int n,i,b[4],a[1010],k=0,count=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	b[0]=0;
	b[1]=1;
	while(k<n)
	{
		if(a[b[1]]<=k && a[b[1]]>=0)
		{	k++;
			a[b[1]]=-2;
		}
		if(b[1]==1 && b[0]==2)
		{
			if(k!=n)
				count++;
			b[0]=1;
			b[1]=2;
		}
		else if(b[1]==n && b[0]==n-1)
		{
			if(k!=n)
				count++;
			b[0]=n;
			b[1]=n-1;
		}
		else if(b[1]>b[0])
		{
			b[0]++;
			b[1]++;
		}
		else
		{
			b[0]--;
			b[1]--;
		}
	}
	printf("%d",count);
	return 0;
}