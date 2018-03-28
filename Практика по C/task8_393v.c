#include <stdio.h>

int main() {
  int n;
  int flag;
  int sum;
  printf("Введите размерность матрицы:\n");
  scanf("%d", &n);
  int matrix[n*n];
  for (int row = 0; row<n; row++) {
    for (int col = 0; col<n; col++) {
      printf("Введите эл-т %i строки %i столбца: ", row+1, col+1);
      scanf("%d", &matrix[row*n+col]);
    }
  }
  for (int row = 0; row<n; row++) {
    printf("|");
    for (int col = 0; col<n; col++) {
      printf(" %i ", matrix[row*n+col]);
    }
    printf("|\n");
  }
  printf("Суммы элементов, предшествующих последнему отрицательному элементу:\n");
  for (int row = 0; row<n; row++) {
    sum = 0;
    for (int col = n-1; col>-1; col--) {
      if (flag == 1) { sum += matrix[row*n+col]; }
      else { if (matrix[row*n+col]<0) { flag = 1; } }
    }
    if (flag==0) { sum = 100; } else { flag = 0; }
    printf("Сумма эл-ов %i строки: %i\n", row, sum);
  }
  return 0;
}
