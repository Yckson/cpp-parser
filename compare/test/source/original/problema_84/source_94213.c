#include<stdio.h>
int main()
{
	int a[2000],b,n,m,i,j,k,l,count1,count2,flag,plag;
	scanf("%d %d",&n,&m);
	count2=0;
	while(n--)
	{
		k=2*m;
		count1=0;
		flag=0;
		plag=0;
		for(i=0;i<k;i++)
			scanf("%d",&a[i]);
		for(i=0;i<k;i++)
		{
			if(a[i]== 1)
				flag=1;
		   if(i%2!=0)
		   {
		   	if(flag==1)
				count2++;

			 flag=0;

		   }
		}
	}
	printf("%d\n",count2);
	return 0;
}