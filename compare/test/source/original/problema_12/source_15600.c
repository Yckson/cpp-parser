#include <stdio.h>

int main() {
	int i, n;
	static int h[2500], v[2500]; 
	static char hused[50], vused[50];

	scanf("%d", &n);
	for (i = 0; i < n * n; i++) {
		scanf("%d%d", &h[i], &v[i]);
		h[i]--, v[i]--;
	}
	for (i = 0; i < n * n; i++)
		if (!hused[h[i]] && !vused[v[i]]) {
			printf("%d ", i + 1);
			hused[h[i]] = vused[v[i]] = 1;
		}
	printf("\n");
	return 0;
}