#include<stdio.h>
int main()
{
    int n,r,c,b,j=0,l;
    scanf("%d",&n);
    int h[n*n],v[n*n];
    for(l=1;l<=n*n;l++)
    {
      scanf("%d %d",&h[l],&v[l]);
    }
    for(r=1;r<=n*n;r++)
    {
        if(h[r]==198765) 
        continue;
        else
        {
            printf("%d ",r);
        }
        for(c=r+1;c<=n*n;c++)
        {
       if(h[r]==h[c]||v[r]==v[c])
            {
                h[c]=198765;
                v[c]=198765;
            }
            
        }
    }
}