#include <stdio.h>

int main(void) {
    int n,i,c=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1)c++;
    }
    for(i=0;i<n-2;i++){
        if(a[i]==1 && a[i+1]==0 && a[i+2]==1)c++;
    }
    printf("%d",c);
    return 0;
}