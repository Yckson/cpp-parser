#include <stdio.h>
int main() {
  int n, meat, cost, min_cost = 100, ret = 0;
  scanf("%d", &n);
  while (n--) {
      scanf("%d%d", &meat, &cost);
      if (min_cost > cost) min_cost = cost;
      ret += meat * min_cost;
  }
  printf("%d\n", ret);
  return 0;
}