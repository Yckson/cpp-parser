#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main( )
{
	int n,p,q,a[52]={0},b[52]={0},i;
	scanf("%d",&n);
	for(i=0;i<(n*n);i++)
	{
		scanf("%d %d",&p,&q);
		if((a[p]==0)&&(b[q]==0))
		{
			printf("%d ",i+1);
			a[p]++;
			b[q]++;
		}
	}
//        printf("\n");
	return 0;
}