#include <stdio.h>
#include <limits.h>

int minimum(int a,int b)
{
	if(a<b)
		return a;
	return b;
}//end of function to find min

int main(void)
{
	int i, n;
	scanf("%d",&n);
	int amt,cost;
	/*
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&amt[i],&cost[i]);
	}
	*/
	int ans=0;
	int price=INT_MAX;
	for(i=1;i<=n;i++)
	{
		int amt,cost;
		scanf("%d %d",&amt,&cost);
		price=minimum(price,cost);
		ans+=(price*amt);
	}
	printf("%d\n",ans);
	return 0;
}//end of main