#include <stdio.h>

int main( void) {

    int n,a[100],i,j, max, ans, count = 0, lastOne = 0, lastZero = 0;

    scanf("%d", &n);

    for(i=0; i<n;i++){
       scanf("%d", &a[i]);
    }

    /*
    n = 8;

    a[0] = 1;
    a[1] = 1;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 1;
    a[6] = 1;
    a[7] = 0;
    */

    for(i=0; i<n;i++){
        if( a[i] == 1 ){
            count++;
        }

        if( i >=2 ){
            if( a[i] == 1 && a[i-1] == 0 && a[i-2] == 1 ){
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}