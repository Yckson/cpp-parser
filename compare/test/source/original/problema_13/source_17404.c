#include <stdio.h>
#define SIZE 1000

struct {
	int inf, crack;
} a[SIZE];

int main()
{
	int n, inf = 0, i, cnt = 0;

	scanf ("%d", &n);

	for (i = 0; i < n; i++) {
		scanf ("%d", &a[i].inf);
		a[i].crack = 0;
	}

	while (inf < n) {
		
		cnt++;

		for (i = 0; i < n; i++)
			if (!a[i].crack && a[i].inf <= inf) {
				inf++;
				a[i].crack = 1;
			}

		if (inf == n)
			break;
		
		cnt++;
		
		for (i = n - 1; i >= 0; i--)
			if (!a[i].crack && a[i].inf <= inf) {
				inf++;
				a[i].crack = 1;
			}

	}

	printf ("%d", cnt - 1);

	return 0;
}