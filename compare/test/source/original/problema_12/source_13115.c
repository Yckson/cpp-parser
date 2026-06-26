#include<stdio.h>
#include<limits.h>
int col[2501];
int row[2501];
int main(){
int a,b,c,d,e;
scanf("%d",&a);
int i;
a*=a;
for(i=0;i<a;i++)
{
    int x,y;
    scanf("%d%d",&x,&y);
    x--;
    y--;
    if(row[x]!=1 && col[y]!=1){
        printf("%d ",i+1);
        row[x]=1;col[y]=1;
    }
}
}