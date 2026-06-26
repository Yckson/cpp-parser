#include<stdio.h>
int main(){
    int a,b,d;
    scanf("%d %d",&a,&b);
    if(a==b){
        d=0;
        printf("%d %d\n",a,d);
    }
    else if(a>b){
        d=a-b;
        if(d<2){
            printf("%d 0\n",b);
        }
        else{
            printf("%d %d\n",b,d/2);
        }
    }
    else{
        d=b-a;
        if(d<2){
            printf("%d 0\n",a);
        }
        else{
            printf("%d %d\n",a,d/2);
        }
    }
    return 0;
}