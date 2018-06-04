#include <stdio.h>

int main() {
  int m;
  printf("Введите размерность матрицы: ");
  scanf("%d", &m);
  float matrix[m][m];
  float resultMatrix1[m][m];
  float resultMatrix2[m][m];
  for (int row = 0; row<m; row++) {
    for (int col = 0; col<m; col++) {
      printf("Введите эл-т %i строки %i столбца: ", row+1, col+1);
      scanf("%f", &matrix[row][col]);
    }
  }
  printf("\n");
  printf("Исходная матрица:\n");
  for (int row = 0; row<m; row++) {
    printf("|");
    for (int col = 0; col<m; col++) {
      printf(" % 03.1f ", matrix[row][col]);
      resultMatrix1[row][col] = 0.5*(matrix[row][col]+matrix[col][row]);
      resultMatrix2[row][col] = 0.5*(matrix[row][col]-matrix[col][row]);
    }
    printf("|\n");
  }
  printf("\n");
  printf("Результирующая матрица 1:\n");
  for (int row = 0; row<m; row++) {
    printf("|");
    for (int col = 0; col<m; col++) {
      printf(" % 03.1f ", resultMatrix1[row][col]);
    }
    printf("|\n");
  }
  printf("\n");
  printf("Результирующая матрица 2:\n");
  for (int row = 0; row<m; row++) {
    printf("|");
    for (int col = 0; col<m; col++) {
      printf(" % 03.1f ", resultMatrix2[row][col]);
    }
    printf("|\n");
  }
  return 0;
}
