#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum = 0, stat, dir = 1, result = 0;
    scanf("%d", &n);
    stat = n;
    int arr[n][2];
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i][0]);
        arr[i][1] = 1;
    }
    i = 0;
    while (stat){
        if (arr[i][1] && (arr[i][0] <= sum)){
            arr[i][1] = 0;
            sum++;
            stat--;
        }
        if ((i == 0) && (dir == -1) && stat) {
            dir = 1;
            result++;
        }else if ((i == n-1) && (dir == 1) && stat){
            dir = -1;
            result++;
        }
        i += dir;
    }
    printf("%d\n", result);
    return 0;
}