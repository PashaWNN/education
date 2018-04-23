#include <stdio.h>///

void removeCell(float **src, float **out, int x, int y, int n) {
  int rrow;
  int rcol;
  for (int row = 0; row<n; row++) {
    rcol = 0;
    for (int col = 0; col<n; col++) {
      if (row == x) {
        rrow++;
      }
      if (col == y) {
        rcol++;
      }
      out[row][col]=src[row+rrow][col+rcol];
    }
  }
}

int main() {
  int n;
  printf("Введите размерность матрицы: ");
  scanf("%d", &n);
  float mat[n][n];
  float res[n-1][n-1];
  for (int row = 0; row<n; row++) {
    for (int col = 0; col<n; col++) {
      printf("Введите эл-т %i строки %i столбца: ", row+1, col+1);
      scanf("%f", &mat[row][col]);
    }
  }
  int maxRow;
  int maxCol;
  for (int row = 0; row<n; row++)
  printf("\n");
  return 0;
}
