#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x, a = -1, b = -1, sum = 0;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &x);
        if (x) {
            sum++;
            if ((a == 1) && (b == 0)) sum++;
        }
        a = b;
        b = x;
    }
    printf("%d\n", sum);
    return 0;
}