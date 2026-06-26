#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a, b; scanf("%d%d", &a, &b);
	int tmp = a<b?a:b;
	printf("%d %d\n", tmp, (a+b)/2-tmp);
	return 0;
}