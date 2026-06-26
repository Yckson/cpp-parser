#include <limits.h>
#include <stdio.h>

int main() {
	int i, n, cnt, dcnt; 
	static int a[1000];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	cnt = dcnt = 0;
	while (cnt < n) {
		for (i = 0; i < n; i++)
			if (cnt >= a[i]) {
				a[i] = INT_MAX;
				cnt++;
			}
		if (cnt < n)
			dcnt++;
		for (i = n - 1; i >= 0; i--) {
			if (cnt >= a[i]) {
				a[i] = INT_MAX;
				cnt++;
			}
		}
		if (cnt < n)
			dcnt++;
	}
	printf("%d\n", dcnt);
	return 0;
}