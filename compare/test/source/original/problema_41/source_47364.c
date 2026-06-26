#include <stdio.h>

int main(void)
{
    int a, p, pmin, n;
    int psum = 0;
    scanf("%d",&n);
    n--;
    scanf("%d%d",&a,&pmin);
    psum += pmin * a;
    while(n > 0){
        scanf("%d%d",&a,&p);
        if(p < pmin){
            pmin = p;
        }
        psum += pmin * a;
        n--;
    }
    printf("%d", psum);
}