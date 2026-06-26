#include <stdio.h>

int main(){
	int res = 0;
	int i = 0;
	int j = 0;
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	i = 0;
	if (n == 1){
		res = a[0];
	}
	else{
		while (i<n){
			j = i+1;
			if (a[i] == 1){
				res += 1;
			}
			else if (j<n && i>0){
				if (a[i] == 0 && a[j] == 1 && a[i-1] == 1){
					res += 1;
				}
			}
			i += 1;
		}
	}
	printf("%d\n", res);
	return(0);
}