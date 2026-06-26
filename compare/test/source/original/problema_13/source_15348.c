#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

int n, ar[MAX];
bool visited[MAX];

int main(){
    int i, j, k, l, x, y, pos, counter;

    while (scanf("%d", &n) != EOF){
        clr(visited);
        for (i = 0; i < n; i++) scanf("%d", &ar[i]);

        pos = 0, counter = 0;
        while (counter < n){
            if (!(pos & 1)){
                for (i = 0; i < n; i++){
                    if (!visited[i] && counter >= ar[i]){
                        counter++;
                        visited[i] = true;
                    }
                }
            }
            else{
                for (i = n - 1; i >= 0; i--){
                    if (!visited[i] && counter >= ar[i]){
                        counter++;
                        visited[i] = true;
                    }
                }
            }

            if (counter == n) break;
            pos++;
        }

        printf("%d\n", pos);
    }
    return 0;
}