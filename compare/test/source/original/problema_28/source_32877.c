#include<stdio.h>
int main(){
	int a[102]={0};
	int i,n,sum;
	sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		if(a[i-1]==1 && a[i+1]==1)
			a[i]=1;
		if(a[i]==1) sum++;
	}
	printf("%d",sum);
    return 0;
}