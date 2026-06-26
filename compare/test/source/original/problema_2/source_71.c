#include <stdio.h>

int main()
{
    int a, b, day = 0, sock;
    scanf("%d %d", &a, &b);

    if(a > b)
    {
        day = b;
        sock = (a-b)/2;
    }
    else
    {
        day = a;
        sock = (b-a)/2;
    }
    printf("%d %d\n", day, sock);

    return 0;
}