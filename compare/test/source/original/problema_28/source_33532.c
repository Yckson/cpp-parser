//by ahmeterdem™
#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a<b)?a:b
#define max(a,b) (a<b)?b:a
#define FOR (i,a,b) for(i=a;i<b;i++)
#define ROF(i,a,b) for(i=b;i>=0;i--)
int i,arr[105],n,t,s;
int main() {
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	i=0;
	while(!arr[i] && i<n)i++,s++;
	for(;i<=n;i++)
	{
		if(i==n)
			s+=t;
		else if(arr[i])
		{
			if(t>1)s+=t;
			t=0;
		}
		else
			t++;
	}
	printf("%d\n",n-s);


	return 0 ;
}