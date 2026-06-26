#include<stdio.h>

int main()
{
    int n, n_sq, i, j, k, row[51] = {0}, colom[51] = {51};

    scanf("%d", &n);
    n_sq = n*n;

    for(i = 1; i <= n_sq; i++){
        scanf("%d %d", &j, &k);
        if(!row[j] && !colom[k]){
            printf("%d ", i);

            row[j] = colom[k] = 1;
        }
    }

    putchar('\n');

    return 0;
}