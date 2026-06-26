#include<stdio.h>
main()
{   int i,j,n,k=0;
    scanf("%d",&n);
    int a[n],b[n];
    for(i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
        i=0;
        while(i<n)
            {j=i;
            int sum=0;
        while(b[i]<=b[j]&&i<n&&j<n)
        {sum=sum+a[j];
            j++;
        }
        k=k+sum*b[i];
        i=j;}
        printf("%d",k);

}