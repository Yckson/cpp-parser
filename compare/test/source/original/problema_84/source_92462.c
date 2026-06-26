#include <stdio.h>
#include <stdlib.h>
int n,m,i,j,w1,w2,res=0;
main()
{
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d %d",&w1,&w2);
            if(w1+w2>0)res++;
        }
    }
    printf("%d",res);
}