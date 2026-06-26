#include <stdio.h>

int main()
{
	int  a , b;
	scanf("%d %d" , &a , &b);

	if(a > b)
	{
		a = a - b;
		int res = a/2;
		printf("%d %d\n",b , res);
	}
	else
	{
		b = b - a;
		int res =  b/2;
		printf("%d %d\n",a , res);
	}
	
}