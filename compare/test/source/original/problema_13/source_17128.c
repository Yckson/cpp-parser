#include "stdio.h"

int main()
{
	int i,n,rounds=0,total=0;
	scanf("%d",&n);
	int a[n],info=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		total+=a[i];
	}
	while(total!=0)
	{
		if(rounds%2==0)
		{
			for(i=0;i<n;++i)
			{
				if(a[i]<=info&&a[i]>=0)
				{
					info++;
					total-=a[i];
					a[i]=-1;
				}
			}
		}
		else
		{
			for(i=n-1;i>=0;--i)
			{
				if(a[i]<=info&&a[i]>=0)
				{
					info++;
					total-=a[i];
					a[i]=-1;
				}
			}
		}
		//printf("%d\n",i);
		rounds++;
	}
	if(rounds>0)
		printf("%d",rounds-1);
	else
		printf("0");
	return 0;
}