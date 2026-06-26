#include<stdio.h>
int main()
{
    int x,y,n,c,i=0,j,k=0,flag=0,glag=0;
    scanf("%d",&n);
    c=n*n;
    int e[c];
    int f [c];
    int d[c];
    for(i=0;i<c;i++)
    {
        scanf("%d %d",&x,&y);
        for(j=0;j<k;j++)
        {
            if(x==e[j])
                flag=1;
            //else
              //  flag=0;
            if(y==f[j])
                glag=1;
            //else
              // glag=0;
        }

     if(flag==0&&glag==0)
           {e[k]=x;
            f[k]=y;
         d[k]=i+1;
         k++;

        }

    flag=0;
    glag=0;

    }
    for(i=0;i<k;i++)
    {
        printf("%d ",d[i]);
    }

}