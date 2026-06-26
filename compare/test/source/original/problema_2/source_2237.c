#include<stdio.h>

int main()
{
    int a,b,d,p;

    scanf("%d %d",&a,&b);

    if(a==b){
        printf("%d 0",a);
        return 0;
    }

    if(a>b){
        a=a-b;
        d=b;
        p=a/2;
    }

    else {
        b=b-a;
        d=a;
        p=b/2;
    }

    printf("%d %d",d,p);

    return 0;
}