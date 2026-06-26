#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

int n, m, ar[MAX];
bool H[MAX], V[MAX];

int main(){
    int i, j, k, l, x, y;

    while (scanf("%d", &n) != EOF){
        m = 0;
        n *= n;
        clr(H), clr(V);

        for (i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            if (!H[x] && !V[y]){
                ar[m++] = i + 1;
                H[x] = true, V[y] = true;
            }
        }

        if (m){
            printf("%d", ar[0]);
            for (i = 1; i < m; i++) printf(" %d", ar[i]);
        }
        puts("");
    }
    return 0;
}