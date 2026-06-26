#include<stdio.h>
int main()
{
    int i,j,k,l;
    scanf("%d",&i);
    scanf("%d",&j);
    if(i>j)
    {
        printf("%d ",j);
        l=i-j;
        k=l/2;
        printf("%d ",k);
    }
    else
    {
        printf("%d ",i);
        l=j-i;
        k=l/2;
        printf("%d ",k);
    }
}