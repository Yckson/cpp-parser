#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    int a[100];
    int i, j;

    memset(a, 0, sizeof(a));
    scanf("%d\n", &n);
    for (i=0; i<n; i++)
        scanf("%d", a+i);

    for (i=0, j=0; i<n; i++) {
        if (a[i] == 1) {
            j++;
        } else {
            if ((i + 1 < n && a[i+1] == 1)
                    && (i-1 >= 0 && a[i-1] == 1))
                j++;
        }
    }
    printf("%d\n", j);

    return 0;
}