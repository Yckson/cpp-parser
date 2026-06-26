#include<stdio.h>
int main()
{
    int a[2500][3],i,j,k=1,l,n,b[2500],m,c[2500];
    scanf("%d",&n);
    scanf("%d %d",&a[0][0],&a[0][1]);
    c[0]=0;
    for(i=1; i<(n*n); i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
        for(j=i; j>=0; j--)
        {
            for(l=k; l>0; l--)
            {
                if((a[c[l-1]][0]!=a[i][0])&&(a[c[l-1]][1]!=a[i][1]))
                {
                    if(l==1)
                    {
                        c[k]=i;
                        k++;
                    }
                }
                else
                    break;
            }
            }
        }
        for(i=0; i<k; i++)
        {
            printf("%d ",c[i]+1);
        }
    }