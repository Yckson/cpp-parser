#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define re return (0);
#define pi(a) printf("%d",a);
#define s(t) scanf("%d",&t)
#define s2(t,u) scanf("%d%d",&t,&u)
#define rep( i, N) for(int i=0;i<N;i++)
main()
{
	int t;
	s(t);
	int a[t]; int b[t];	
	rep(i,t)
		s2(a[i],b[i]);
		int cost=a[0]*b[0];
		int min=b[0];
	for(int i=1;i<t;i++)
	{
	if(b[i]<min)
	min=b[i];
	cost+=min*(a[i]);
}
		
	printf("%d",cost);
}