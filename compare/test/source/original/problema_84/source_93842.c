#include<stdio.h>
int main()
{
	long int n,m,count=0 ;
	int a[200];
	scanf("%ld %ld",&n,&m);
	long int test=0;
	while (test<n)
	{
		long  int i;
		for (i=0;i<(2*m);i++)
		scanf("%d", &a[i]);
		
		for (i=0;i<2*m;i=i+2)
		if (a[i]==1 || a[i+1]==1)
		count++;
		test++;
	}
	printf("%ld",count);
	return 0;
}