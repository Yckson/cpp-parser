#include<stdio.h>
int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  int i,j;
  int count=0;
  for(i=0;i<n;i++) {
    for(j=0;j<m;j++) {
       int a,b;
       scanf("%d%d",&a,&b);
       if(a==1 || b==1) count++;
    }
  }
  printf("%d\n",count);
  return 0;
}