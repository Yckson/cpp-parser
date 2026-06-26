#include<stdio.h>
#include<math.h>

main()
{
	int n,i,a,b,t=0;
	
	scanf("%d",&n);
	
	int m[n],mb[n],m2[n];
	
	for(i=0;i<n;i++)
	{
		m[i]=0;
		mb[i]=0;
	}
		
	
	
	for(i=0;i<n*n;i++)
	{
		scanf("%d %d",&a,&b);
		if(m[a-1]==0 && mb[b-1]==0)
		{
			m2[t]=i+1;
			m[a-1]=1;
			mb[b-1]=1;
			t++;
		}
	}	
	
	for(i=0;i<t;i++) printf("%d ",m2[i]);	
}