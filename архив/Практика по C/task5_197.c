#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float get_a(int raw) {
  div_t n;
  n = div(raw, 2);
  if (n.quot == 1) {
    return (float)raw;
  } else {
    return (float)raw/2;
  }
}

float get_b(int raw) {
  div_t n;
  n = div(raw, 2);
  if (n.quot == 1) {
    return pow(raw, 2);
  } else {
    return pow(raw, 3);
  }
}

int main() {
  int a[30];
  int b[30];
  float sum;
  for(int i = 1; i <= 30; i++) {
    printf("Введите a[%i]: ", i);
    scanf("%d", &a[i-1]);
    printf("Введите b[%i]: ", i);
    scanf("%d", &b[i-1]);
  }
  for(int i = 0; i < 30; i++) {
    sum += pow(get_a(a[i]) - get_b(b[i]), 2);
  }  
  printf("Результат: %.2f", sum);
  return 0;
}
