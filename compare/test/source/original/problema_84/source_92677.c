#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,z=0,k;
    scanf("%i%i",&n,&m);
    int w[m][2];
    for(k=0;k<n;k++){
        for(i=0;i<m;i++){
            for(j=0;j<2;j++){
                scanf("%i",&w[i][j]);
            }
            if(w[i][0]==1||w[i][1]==1)
                z+=1;
        }
    }
    printf("%i",z);
    return 0;
}