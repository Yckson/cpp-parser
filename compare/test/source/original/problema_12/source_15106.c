#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int horizontal[n];
    int vertical[n];
    int i;
    int j,k;
    for(i=0;i<n;i++){
        horizontal[i]=0;
        vertical[i]=0;
    }
    for(i=1;i<=n*n;i++){
        scanf("%d%d",&j,&k);
        if(horizontal[j-1]==0 && vertical[k-1]==0){
            horizontal[j-1] = 1;
            vertical[k-1] = 1;
            printf("%d ",i);
        }
    }


}