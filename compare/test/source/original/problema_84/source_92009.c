#include <stdio.h>

int main(){
	int n, m;
	int inp1, inp2;
	int ans=0;
	int i, j;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d", &inp1);
			scanf("%d", &inp2);
			if(inp1 == 1 || inp2 == 1) ans++;
		}
	}
	
	printf("%d", ans);
}