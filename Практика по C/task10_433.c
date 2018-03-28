#include <stdio.h>
#include <math.h>

int a[13];

int p(int x) {
  return a[12]*pow(x, 12)+a[12]*pow(x, 11)+a[6];
}

int main() {
  int s;
  int t;
  printf("Введите s: ");
  scanf("%d", &s);
  printf("Введите t: ");
  scanf("%d", &t);
  for (int i = 0; i<13; i++) {
    printf("Введите a[%i]: ", i);
    scanf("%d", &a[i]);
  }
  int res = p(1) - p(t) + pow(p(s-t), 2) - pow(p(1), 3);
  printf("Результат: %i", res);
  return 0;
}
