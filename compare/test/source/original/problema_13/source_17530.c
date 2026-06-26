#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i,arr[n],traveldir=1;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int info=0,count=0,direction=0;
	i=0;
	//printf("%d",i);
	while(count<=n-1)
	{
		if(i>n-1)
				{
					i-=2;
					traveldir=0;
					direction++;
				}
				if(i<0)
				{
					i+=2;
					traveldir=1;
					direction++;
				}
		if(arr[i]<=info && arr[i]!=-1)
			{
				count++;
				info++;
				arr[i]=-1;
			}
			//printf("%d %d %d %d %d\n",i,arr[i],count,traveldir,direction);
			if(traveldir==1)
			i++;
			else if(traveldir==0)
			i--;
			}
	printf("%d", direction);
	return 0;
}