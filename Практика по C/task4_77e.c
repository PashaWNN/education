#include <stdio.h>
#include <math.h>

int main() {
  int n;
  float sum = 0;
  float numerator = 0;
  float denominator = 0;
  printf("Введите n: ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    numerator += cos(i);
    denominator += sin(i);
    sum += numerator/denominator;
  }
  printf("Результат: %f", sum);
  return 0;
}
