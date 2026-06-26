#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],p[n];
	int i,sum=0,min;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&p[i]);
		if(i==0)
			min=p[i];
		else if(min>p[i])
			min=p[i];
		sum+=min*a[i];
	}
	printf("%d\n",sum);
	return 0;
}