#include<stdio.h>
main()
{
	int n; scanf("%d",&n);
	int a[n][2];
	int p;
	scanf("%d%d",&a[0][0],&a[0][1]);
	p=a[0][1]; long long int s=p*a[0][0];
	int i=1;
	while(i<n)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
		if(p>a[i][1])
		p=a[i][1];
		s+=(p*a[i][0]);
		i++;
	}
	printf("%I64d",s);
}