#include <stdio.h>
#include <stdlib.h>

int minn(int a,int b)
{
    if(a<=b){return a;}
    return b;
}

int maxx(int a,int b)
{
    if(a>=b){return a;}
    return b;
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int x = minn(a,b);
    printf("%d ",x);
    a -= x;
    b -= x;
    int y = maxx(a,b)/2;
    printf("%d",y);

    return 0;
}