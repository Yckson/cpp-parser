//by ahmeterdem™
#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a<b)?a:b
#define max(a,b) (a<b)?b:a
#define FOR (i,a,b) for(i=a;i<b;i++)
#define ROF(i,a,b) for(i=b;i>=0;i--)
int main() {
	int i,arr[1000]={0},n,h[1000]={0},x,y;
		scanf("%d",&n);
		for(i=0;i<n*n;i++){
			scanf("%d %d",&x,&y);
			if(!arr[x] && !h[y]){
			printf("%d ",i+1);
			arr[x]++;
			h[y]++;
		}}
	return 0 ;
}