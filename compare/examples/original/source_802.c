#include<stdio.h>

int main()
{
	int a,b,max,min;
	scanf("%d %d",&a,&b);
	
	if(a>b)
		{max=a;
		min=b;}
	else
		{min=a;
		 max=b;}
	
	printf("%d ",min);


	if((max-min)%2==0)
		printf("%d ",(max-min)/2);
	else
		printf("%d ",(max-min-1)/2);
	return 0;
}