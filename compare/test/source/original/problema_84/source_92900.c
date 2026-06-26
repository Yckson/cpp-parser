#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i,sum,j,a,b,c;
	sum = 0;
	j = (2*m)*n;
	for (i=0;i<(j/2);i++)
	{
		scanf("%d %d",&a,&b);
		c = a+b;
		if ( c>=1)
			sum = sum + 1;
	}
	printf("%d\n",sum);

return 0;
}