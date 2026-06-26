#include<stdio.h>
int main()
{
	int n,i,count=0,bent=0;
	scanf("%d",&n);
	int arr[n],j=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	i=0;
	while(1)
	{
		if(i==0)
		{
			if(arr[j]<=bent && arr[j]!=-1)
			{
				bent++;
				if(bent==n)
				{
					break;
				}
				arr[j]=-1;
			}
			j++;
			if(j==n)
			{
				j=n-1;
				i=1;
				count++;
			}
		}
		else if(i==1)
		{
			if(arr[j]<=bent && arr[j]!=-1)
			{
				bent++;
				if(bent==n)
				{
					break;
				}	
				arr[j]=-1;
			}
			j--;
			if(j==-1)
			{
				j=0;
				i=0;
				count++;
			}
		}
	}
	printf("%d",count);
	return 0;
}