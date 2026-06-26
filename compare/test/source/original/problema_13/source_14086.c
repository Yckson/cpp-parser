#include<stdio.h>
#include<math.h>
int main( )
{
	int n,a[1001],i,j,k,c=0,s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<n;j++)
	{
//		printf("j is %d\n",j);
		if(j%2==0)
		{
//			printf("Hai\n");
			s+=1;
			for(i=0;i<n;i++)
			{
				if(a[i]<=c)
				{
					c+=1;
                                        a[i]=1001;
//					printf("c is %d\n",c);
				}
				if(c==n)
				{
					break;
				}
			}
		}
		else
		{
//			printf("Hello\n");
			s+=1;
			for(k=n-1;k>=0;k--)
			{
				if(a[k]<=c)
				{
                                        a[k]=1001;
					c+=1;
//					printf("c is the %d\n",c);
				}
				if(c==n)
				{
					break;
				}
			}
		}
		if(c==n)
		{
			break;
		}
	}
	printf("%d\n",s-1);
	return 0;
}