#include <stdio.h>

#define MOD 0
// . + + + +
// . . + + +
// . . . + +
// . . . . +
// . . . . .

//#define MOD = 1
// + + + + +
// . + + + +
// . . + + +
// . . . + +
// . . . . +

int main() {
  printf("Введите n: ");
  int n;
  scanf("%d", &n);
  float m[n][n];
  float max = 0.0;
  for (int row = 0; row<n; row++) {
    for (int col = 0; col<n; col++) {
      printf("Введите эл-т %i строки %i столбца: ", row+1, col+1);
      scanf("%f", &m[row][col]);
      if ((row < col+MOD) & (m[row][col] > max)) {
        max = m[row][col];
      }
    }
  }
  printf("Максимальный элемент верхней-левой части матрицы: %f\n", max);
  return 0;
}
