#include <stdio.h>

int main()
{
	int n, i, sum, a, minp;

	scanf ("%d", &n);
	scanf ("%d %d", &a, &minp);
	sum = a * minp;

	for (i = 1; i < n; i++) {
		int p;
		scanf ("%d %d", &a, &p);
		if (p < minp)
			minp = p;
		sum += a * minp;
	}

	printf ("%d", sum);

	return 0;
}