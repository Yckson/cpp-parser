#include<stdio.h>
int main()
{
	int a,b,counta=0;
	scanf("%d %d",&a,&b);
	while(1){
		if(a==0||b==0)break;
		a--;
		b--;
		counta++;
		
	}
	printf("%d ",counta);
	counta=0;
	while(1){
		if((a+b)<2)break;
		if(a==0)b-=2;
		else if(b==0)a-=2;
		counta++;
		
	}
	printf("%d",counta);
	return 0;
	
}