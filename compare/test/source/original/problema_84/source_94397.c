#include <stdio.h>

int main()
{
    int n,m,a,b,sum=0,i;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n*m;i++){
        scanf("%d %d",&a,&b);
        if(a==1||b==1){
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}