#include <stdio.h>


int main(){
    int n, sta = 0, res = 0;
    int a[102];
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[n+1] = 0;
    for (i = 1; i <= n; i++)
    {
        if (sta == 0)
            if (a[i] == 1) sta = 1;
        if (sta == 1)
            if (a[i] == 0 && a[i+1] == 0) sta = 0;
        if (sta == 1) res++;

    }
    printf("%d", res);
    return 0;
}