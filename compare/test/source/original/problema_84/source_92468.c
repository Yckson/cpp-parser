#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,a,b,i=0,x;
    scanf("%d%d",&n,&m);
    for(a=1;a<=n;a++){
        for(b=1;b<=m;b++){
            x=fun(b);
            i=x+i;
        }
    }
    printf("%d",i);
    return 0;
}
int fun()
{
    int i,w,k=0;
    for(i=1;i<=2;i++){
    scanf("%d",&w);
    if(w==1) k++;
    }
    if(k>=1) return 1;
    else return 0;

}