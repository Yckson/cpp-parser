/*Duff and Meat*/

#include<stdio.h>

int a[100000], p[100000];

int main()
{
	int i, minp, n, total_cost;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &a[i], &p[i]);
	minp = 10000;
	total_cost = 0;
	for (i = 0; i < n; i++)
	{
		if (minp > p[i])
			minp = p[i];
		total_cost += minp * a[i];
	}
	printf("%d\n", total_cost);
	return 0;
}