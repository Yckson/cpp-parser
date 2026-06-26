#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

#define MAX( a, b ) ( ( a > b) ? a : b ) 
#define MIN( a, b ) ( ( a < b) ? a : b )
#define FOR(ii,aa,bb) for(ii=aa;ii<bb;ii++)

int main () {
	int x,n,s,i,j;
	int a[60]={0},b[60]={0};
	scanf("%d",&n);
	FOR(i,0,n*n){
		scanf("%d %d",&x,&s);
		if(!a[x]&&!b[s]){
				printf("%d ",i+1);
				a[x]++;
				b[s]++;}
}


	
	
	
	
	return 0;
}