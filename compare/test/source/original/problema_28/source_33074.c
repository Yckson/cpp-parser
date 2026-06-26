#include<stdio.h>
int main(){
	int a[100], h[100];
	int g,i,j,d,n,s,p,b;
	scanf("%d", &n);
	for (i=0,s=0,b=0,p=0;i<n;i++){
		scanf("%d", &a[i]);
		if(a[i]==1){
			h[b]=i;
			p=p+1;
			b=b+1;
			s=s+1;
		}
	}
	for(b=1;b<p;b++){
		j=h[b]-h[b-1];
		if(j==2)
			s=s+1;
	}
	printf("%d\n",s);
	return 0;
}