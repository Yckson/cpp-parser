#include<stdio.h>
int main()
{
    int n,i,j=0,cnt=0,l=0,s=0,x,flag=1,p;
    scanf("%d",&n);
    int a[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
       s=s+a[i];
    }
 for(i=0,l=0;i<n;i++)
 {
   if((i+1)%2!=0){
        if(i>=2)
        cnt++;
        for(j=0;j<n;j++)
    {
         if(a[j]<=l)
         {   a[j]=s*3;
             l++;
             if(l==n)
                goto here;
         }
    }

    }
   if((i+1)%2==0) {cnt++;
      for(j=n-1;j>=0;j--)
      {
          if(a[j]<=l)
          {
             a[j]=s*3;
             l++;
             if(l==n)
             goto here;
          }
      }



   }

       // printf("\n");



}


here:;
printf("%d",cnt);
 }