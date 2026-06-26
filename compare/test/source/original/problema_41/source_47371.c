#include <stdio.h>

int main(){
  int n, amount = 0, j;
  scanf("%d", &n);
  int matrix[n][2];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 2; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
  for(int i = 0; i < n; i++){
    amount += matrix[i][0] * matrix[i][1];
    for(j = i + 1; j < n; j++){
      if(matrix[j][1] > matrix[i][1]){
        amount += matrix[j][0] * matrix[i][1];
      }
      else{
        break;
      }
    }
    i = j - 1;
  }
  printf("%d\n", amount);
  return 0;
}