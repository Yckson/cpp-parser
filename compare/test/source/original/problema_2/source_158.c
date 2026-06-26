#include <stdio.h>

int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);
    int k1 = a > b ? b : a;
    int k2 = a + b - 2 * k1; 
    k2 /= 2;
    printf("%d %d", k1, k2);
}