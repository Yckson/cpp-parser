#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,er=0,yi=0;
    scanf("%d%d",&a,&b);
    while(a!=0&&b!=0)
    {
        a--;
        b--;
        er++;
    }
    while(a>=2)
    {
        a-=2;
        yi++;
    }
    while(b>=2)
    {
        b-=2;
        yi++;
    }
    printf("%d %d",er,yi);
}