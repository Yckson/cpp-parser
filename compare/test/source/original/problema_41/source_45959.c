#include <stdio.h>

main()
{
    int n,m,i,y=0,a,p,s=0,l=0;
    scanf("%d\n", &n);
    scanf("%d%d", &a, &p);
    l=p;
    s=a;
    for (i=1;i<n;i++)
    {
        scanf("%d%d", &a, &p);
        if (p>=l)
        {
            s+=a;
        }
        else
        {
            y+=l*s;
            l=p;
            s=a;
        }
    }
    y+=l*s;
    printf("%d", y);
}