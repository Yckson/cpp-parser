#include <stdio.h>
int main()
{
    int n,m,i,j,ara[205];
    scanf("%d %d",&n,&m);
    int count=0;
    for(j=1;j<=n;j++){
        for(i=0;i<2*m;i++){
            scanf("%d",&ara[i]);

        }
        for(i=0;i<2*m-1;i=i+2){
            if(ara[i]==0&&ara[i+1]==0){
                continue;
            }
            else{
                count++;
            }
    }

    }



    printf("%d\n",count);

}