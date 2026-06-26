#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=0;

    for(i=0;i<n*n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(a[x-1][y-1]==0)
        {
            a[x-1][y-1]=1;
            printf("%d ",i+1);
            for(j=0;j<n;j++)
                {
                    a[x-1][j]=1;
                    a[j][y-1]=1;
                }
        }
    }
    return 0;
}