#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,c=0,p,q,length,k=0;
	scanf("%d",&n);
	length=n*n;
	int *a,*b,*res;
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(n*sizeof(int));
	res=(int*)malloc(length*sizeof(int));
	for(i=0;i<n;i++)
	{
		a[i]=0;
		b[i]=0;
	}
	for(i=0;i<length;i++)
	{
		scanf("%d %d",&p,&q);
		if(a[p-1]==0&&b[q-1]==0)
		{
			a[p-1]=1;
			b[q-1]=1;
			res[k]=i+1;
			k++;
			c++;
		}
	}
	for(i=0;i<c;i++)
	  printf("%d ",res[i]);
	  
 return 0;	  
}