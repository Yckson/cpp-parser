#include <stdio.h>
main()
{
    int n,a[100000],p[100000],i,dol=0,k;
    scanf("%i",&n);
    for (i=1;i<=n;i++) {scanf("%i %i",&a[i],&p[i]);}
    i=1;
    while (!(i>n)) {
        dol+=a[i]*p[i];
        k=1;
    while ((p[k+i]>p[i]) && !(k+i>n))
    {
        dol+=a[k+i]*p[i];
        a[k+i]=0;
        ++k;
    }
    ++i;}
    printf("%i",dol);
}