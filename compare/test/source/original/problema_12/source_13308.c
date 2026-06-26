#include<stdio.h>
main(){
    int n,i,j,p,q,arai[51]={0},araj[51]={0},ara[51]={0},k=0;
    scanf("%d",&n);
    for(i=1;i<=n*n;i++){
        scanf("%d %d",&p,&q);
        if(arai[p]==0 && araj[q]==0){
            ara[k]=i;
            k=k+1;
            arai[p]=1;
            araj[q]=1;
        }
    }
    for(i=0;i<k;i++) printf("%d ",ara[i]);
}