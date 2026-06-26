#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int arr[25000];

int main(){
	int a,b,c,d,e;
	scanf("%d%d",&a,&b);
	int i;  int cnt=0;
	for(i=0;i<a;i++){
		for(d=0;d<(2*b);d++){
			scanf("%d",&arr[d]);
		}
		for(d=0;d<(2*b);d+=2){
			int res = arr[d]+arr[d+1];
			if(res>=1){
				cnt++;
			}
		}
		
	}
	printf("%d",cnt);
	
}