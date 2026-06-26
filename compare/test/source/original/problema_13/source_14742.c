#include<stdio.h>
int arr[2500];

int main(){
    int a,b,c,d,e;
    scanf("%d",&a);
    int i;
    for(i=0;i<a;i++){
            scanf("%d",arr+i);
    }
    int cnt=0; int clean=a; int atm=0;
    while(clean){
    for(i=0;i<a;i++){
        if(arr[i]<=atm && arr[i]!=-1){
                arr[i]=-1;
                atm++;
                clean--;
        }
    }
    if(clean)
    cnt++;
    for(i=a-1;i>=0;i--){
        if(arr[i]<=atm && arr[i]!=-1){
                arr[i]=-1;
                atm++;
                clean--;
        }
    }
    if(clean)
    cnt++;
    }
    printf("%d",cnt);


}