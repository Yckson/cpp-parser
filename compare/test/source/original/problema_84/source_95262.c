#include<stdio.h>
int main()
{
	int a[200],b[200],n,m,i,j,k=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			 scanf("%d%d",&a[j],&b[j]);
			 if(a[j]==1 || b[j]==1) k++;
		}
	}
	printf("%d",k);
	
	return 0;
}