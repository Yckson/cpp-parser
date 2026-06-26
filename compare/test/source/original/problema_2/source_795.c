#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	
	int r,b,fashion_,same_,left;
	scanf("%d %d",&r,&b);
	if(r<b)
	{
		fashion_=r;
		left=b-r;
		if(left/2)
		  same_=left/2;
		else 
		  same_=0;  
	}
	else
	{
		fashion_=b;
		left=r-b;
		if(left/2)
		  same_=left/2;
		else 
		  same_=0; 
		
	}
	
	printf("%d %d\n ",fashion_,same_);                                                                                       
	
	return 0;

}