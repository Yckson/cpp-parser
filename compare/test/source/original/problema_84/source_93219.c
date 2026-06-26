#include<stdio.h>
int main( )
{
    int n,m,c=0,i,a[250],j;
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++)
    {
        for (j=1;j<=(2*m);j=j+2)
        {
            scanf("%d %d",&a[j],&a[j+1]);
            if ((a[j] | a[j+1] ==1))
            {
                c+=1;
            }
        }
    }
        printf("%d\n",c);
        return 0;
    }