#define N 100000

#include <stdio.h>
#include <limits.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int sum  = 0;
	int cost = INT_MAX;
	for (int i = 0; i < n; i++) {
		int req, cur_cost;
		scanf("%d%d", &req, &cur_cost);
		if (cur_cost < cost)
			cost = cur_cost;
		sum += req * cost;
	}
	printf("%d\n", sum);
	return 0;
}