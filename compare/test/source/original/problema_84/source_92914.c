#include <stdio.h>

int main(void) 
{
    int n,m,c=0,i,a[1000];
    scanf("%d %d",&n,&m);
    while(n--)
    {
        for(i=1;i<=2*m;i++)
        {
            scanf("%d ",&a[i]);
        }
        for(i=1;i<=2*m;)
        {
            if(a[i]== 1 && i%2!=0)
                {
                    c++;
                    i+=2;
                }
            else if(a[i]== 1 && i%2==0)
                {
                    c++;
                    i++;
                }
            else
                i++;
        }
    }
    printf("%d",c);
        
    return 0;
}