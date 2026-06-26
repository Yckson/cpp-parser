#include <stdio.h>

int main(){
	int i, j, k, n, m, result, in, temp;
	scanf("%d %d", &n, &m);
	
	for(result = 0, i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			for(k = 0, temp = 0; k < 2; k++){
				scanf("%d", &in);
				temp = temp | in;
			}
			result += temp;
		}
	}

	printf("%d", result);
}
// 1452661749747