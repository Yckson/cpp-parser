#include<stdio.h>
int main()
{
	int cnt=0,flag=0,n,a[10001],i,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	i=0;
	while(1)
	{
		if(flag==0)//means moving ahead;
		{
			if(count>=a[i])
			{
				count++;
				a[i]=1001;
			}
			i++;
		}
		else
		{
			if(count>=a[i])
			{
				count++;
				a[i]=1001;
			}
			i--;
		}
		if(count==n)
			break;
		if(i==-1)
		{flag=0;cnt++;i++;}
		else if(i==n)
		{flag=1;cnt++;i--;}
	}
	printf("%d",cnt);
	return 0;
}