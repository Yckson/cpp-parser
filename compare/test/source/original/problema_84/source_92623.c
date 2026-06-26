#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, a, b, i, sum = 0;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n * m; i++)
    {
        scanf("%d %d", &a, &b);
        if (a || b)
            sum++;
    }
    printf("%d\n", sum);

    return 0;
}