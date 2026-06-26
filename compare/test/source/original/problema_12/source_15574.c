#include<stdio.h>
#include<string.h>

int main(){
    int n,j,i,flag=0,a,b,c;
    scanf("%d",&n);
    int s[n][n];
    int x[n*n],y[n*n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        s[i][j]=0;
        }
    }
    for(i=0;i<n*n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }

    for(i=0;i<n*n;i++){
        if(s[x[i]-1][y[i]-1]==0){printf("%d ",i+1);
        for(j=0;j<n;j++){
            s[x[i]-1][j]=1;
        }
        for(j=0;j<n;j++){
            s[j][y[i]-1]=1;
        }

        }
    }
    return 0;
}