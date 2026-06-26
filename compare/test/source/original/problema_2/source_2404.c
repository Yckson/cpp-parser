#include<stdio.h>
int main()
{
	int a,b,d;
	scanf("%d %d",&a,&b);
	if(b>a)
	{
		printf("%d ",a);
		b=b-a;
		if(b>1)
		{
			d=b/2;
			printf("%d",d);
		}
		else if(b<=1)
		{
			printf("0");
		}
	}
	else
	{
	
	
		printf("%d ",b);
		a=a-b;
		if(a>1)
		{
			d=a/2;
			printf("%d",d);
		}
		else if(a<=1)
		{
			printf("0");
		}

	}
	
	 
}