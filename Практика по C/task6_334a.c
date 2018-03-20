#include <stdio.h>

int main() {
  float sum = 0;
  for (int i = 1; i <= 100; i++) {
    float sum_j = 0;
    for (int j = 1; j <= 50; j++) {
      sum_j += 1.0 / (i + j * j);
    }
    sum += sum_j;
  }
  printf("Результат: %.2f", sum);
  return 0;
}
