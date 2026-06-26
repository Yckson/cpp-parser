#include <stdio.h>


int main(){
    int n;
    int a[1000];
    int i, res = 0, count = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (count < n){
        if (res % 2 == 0)
            for (i = 0; i < n; i++)
        if (a[i] <= count){
            a[i] = 1001;
            count++;
        }
        if (res % 2 != 0)
            for (i = n-1; i >= 0; i--)
        if (a[i] <= count){
            a[i] = 1001;
            count++;
        }
        res++;
    }
    printf("%d", res-1);
    return 0;
}