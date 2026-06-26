#include<stdio.h>

int main()

{
    long long i, n, a[100001], p[100001], min, c;

    min = 1000;

    c = 0;

    scanf("%lld", &n);

    for (i = 0; i < n; i++) {

        scanf("%lld %lld", &a[i], &p[i]);

        min = (min >= p[i]) ? p[i] : min;

        c += a[i] * min;
    }

    printf("%lld\n", c);

    return 0;
}