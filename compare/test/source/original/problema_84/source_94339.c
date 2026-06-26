#include <stdio.h>
#include <stdlib.h>

int main()
{int n,m,i,j,a,b,s;
do
{
    scanf("%d",&n);
}
while((n<1)||(n>100));
do
{
    scanf("%d",&m);
}
while((m<1)||(m>100));
b=0;
s=0;
for(i=0;i<n;i++)
{for(j=0;j<2*m;j++)
{
    do
    {
        scanf("%d",&a);
    }while((a!=0)&&(a!=1));
    if(j%2==1)
    {
        if((a==1)||(b==1))
            s++;
    }
    b=a;
}

}
printf("%d",s);


    return 0;
}