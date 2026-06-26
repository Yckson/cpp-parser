#include<stdio.h>
int a[52][52];
int main()
{
	int n,i,count=0,h,v,j;
	scanf("%d",&n);
	for(i=0;i<n*n;i++)
	{
		scanf("%d%d",&h,&v);
		if(a[h-1][v-1]==0)
		{
			for(j=0;j<n;j++)
			{
				a[h-1][j]=1;
				a[j][v-1]=1;
			}
			printf("%d ",i+1);
		}	
	}
	printf("\n");
	return 0;
}