#include<stdio.h>
int main()
{
    int i,a,b,x;
    scanf("%d %d",&a,&b);
    x=abs(a-b);
    if(a>b)
    {
      if(x>1)
      {
          i=x/2;
          printf("%d %d",b,i);
      }
      else if(x<=1)
      {
       printf("%d %d",b,0);
      }
    }
    if(b>a)
    {
         if(x>1)
      {
          i=x/2;
          printf("%d %d",a,i);
      }
      else if(x<=1)
      {
       printf("%d %d",a,0);
      }
    }
    if(a==b)
    {
        printf("%d %d",a,0);
    }
    return 0;
}