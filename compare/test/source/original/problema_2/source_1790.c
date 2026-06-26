#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b ,c;
    scanf("%d %d",&a,&b);
    int min = a;
    if(min > b)
    {
        min = b;
        c = (a-b)/2;
    }
    else
        c = (b-a)/2;
    printf("%d %d\n",min,c);
    return 0;
}