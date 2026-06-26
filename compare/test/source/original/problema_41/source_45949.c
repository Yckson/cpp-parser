#include<stdio.h>
int main()
{
	int n,i,min=1000,a,b,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if(b<min)
			min=b;
		ans+=a*min;
		
	}
	printf("%d",ans);
	return 0;
}