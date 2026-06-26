#include <stdio.h>
int t[111];
int main()
{
	int n,i,c=0,last=-1,f=-1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		if(t[i])
		{
			last=i;
			if(f==-1) f=i;
		}
	}
	if(f==-1)
	{
		puts("0");
		return 0;
	}
	t[0]=0,t[n+1]=0;
	for(i=f;i<=last;i++)
		if(t[i]) c++;
		else if(t[i-1]&&t[i+1]) c++;
	printf("%d\n",c);
}