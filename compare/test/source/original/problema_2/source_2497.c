#include<stdio.h>
int main()
{
    int a,b,c=0,f=0,d,i,n;
    scanf("%d %d",&a,&b);
    while(a>0||b>0){
    if(a>0&&b>0)
    {
        a--;
        b--;
        c++;
    }
    else if(a>0||b>0)
    {
        if(a>=2||b>=2)
            {
                a=a-2;
                b=b-2;
                f++;
            }
            else
            break;

    }
    }
    printf("%d %d",c,f);
}