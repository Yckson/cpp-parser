#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d%d", &n,&m);
    int sum=0;
    int z=n*m;
    int i;
    int x,y;
    for(i=1;i<=z;i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        if(x+y>=1)
        sum+=1;
    }
    printf("%d", sum);
    return 0;
}