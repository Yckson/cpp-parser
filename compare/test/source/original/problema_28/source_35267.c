#include<stdio.h>
int main ()
{
    int n,a[100],i,j,k,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            count++;
            if(i+1==n-1)
            {
                if(a[i+1]==1)count++;
                break;
            }
            else
            {
                for(j=i+2;j<n;j++)
                {
                    if(a[j]==a[j-1])
                    {
                        if(a[j]==1)
                        {
                            if(j!=n-1)count++;
                            else count=count+2;
                        }
                        else
                        {
                            for(k=j+1;k<n;k++)
                            {
                                if(a[k]==1)
                                {
                                    j=k;
                                    if(j==n-1)count++;
                                    break;
                                }
                            }
                            if(j==n-1)
                            {
                                j=k;
                                break;
                            }
                        }
                    }
                    else
                    {
                        if(j==n-1)
                        {
                            if(a[j]==1)count=count+2;
                            else count++;
                        }
                        else count++;
                    }
                }
                break;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}