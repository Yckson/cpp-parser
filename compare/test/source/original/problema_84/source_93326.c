#include <stdio.h>

int main()
{
	int n, m, i, j;
	int cnt = 0;
	int t1, t2;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			scanf("%d %d", &t1, &t2);
			cnt += t1 || t2;
		}

	printf("%d", cnt);

	return 0;
}