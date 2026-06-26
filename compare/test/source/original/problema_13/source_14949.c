#include <stdio.h>

int main()
{
	int n,i,j,k=0,l=0,cnt=0;
	scanf("%d",&n);
	int ara[10000];
	int b[10000];
	for (i=0;i<n;i++){
		scanf("%d",&ara[i]);
	}
	
	while(1){
	for (i=0;i<n;i++){
		if (ara[i]!=-1 && ara[i]<=l){
			ara[i]=-1;
			k++;
			if (k==n){
				printf("%d",cnt);
				return 0;
			}
			l++;
		}
	}
	cnt++;
	for (i=n-1;i>=0;i--){
		if (ara[i]!=-1 && ara[i]<=l){
			ara[i]=-1;
			k++;
			if (k==n){
				printf("%d",cnt);
				return 0;
			}
			l++;
		}
	}
	cnt++;
	}
	return 0;
}