#include <stdio.h>

int main()
{
    int r,b,diff=0,same=0;

    scanf("%d %d",&r,&b);

    while (r>=0 || b>=0)
    {
        if(r==0 || b==0)
        {
           if(r==0)
           {
               b=b-2;
               if(b>=0)
               {
                   same++;
               }
               else
               break;
           }
           else
           {
               r=r-2;
               if(r>=0)
               {
                   same++;
               }
               else
               break;
           }
        }
        else
        {
            diff++;
            r--;
            b--;
        }
    }
    printf("%d %d",diff,same);

}