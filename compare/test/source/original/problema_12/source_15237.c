#include<stdio.h>
int main()
{
    int i,j,n,a,b,l=0,x[51],y[51],ans[51];
    scanf("%d",&n);
    for(i=0;i<n*n;i++)
    {
        scanf("%d %d",&a,&b);
        for(j=0;j<l;j++)
        {
            if(a==x[j]||b==y[j])
                break;
        }
        if(j==l)
        {
            ans[l]=i+1;
            x[l]=a;
            y[l++]=b;
        }
    }
    for(i=0;i<l;i++)
        printf("%d ",ans[i]);
    return 0;
}