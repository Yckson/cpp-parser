#include<stdio.h>
main()
{
	int n,i,j,c=0,min=101;
	scanf("%d\n",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
	{
      scanf("%d%d",&a[i],&b[i]);
      if(min>b[i])
      min=b[i];
      c+=min*a[i];
	}
	printf("%d",c);
}