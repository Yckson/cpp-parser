#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;int arr[52][52];int i,j;
	for(i=1;i<=51;i++)
	{
		for(j=1;j<=51;j++)
		{
			arr[i][j]=5;
		}
	}
		
	scanf("%d",&n);
	int a,b;
	
	scanf("%d%d",&a,&b);
	for(j=1;j<=50;j++)arr[a][j]=0;
	for(j=1;j<=50;j++)arr[j][b]=0;
	printf("1 ");

	
	int c=n*n;
	for(i=1;i<c;i++)
	{
		scanf("%d%d",&a,&b);
			
			if(arr[a][b]!=0)
			{
				printf("%d ",i+1);
				for(j=1;j<=50;j++)arr[a][j]=0;
				for(j=1;j<=50;j++)arr[j][b]=0;

			}	
				
						
								
	}	
		
					
		


	
	
return 0;
}