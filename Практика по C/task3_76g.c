#include <stdio.h>

int main() {
  int k;
  int l;
  int m;
  int n;
  printf("Введите k, l, m, n: ");
  scanf("%d%d%d%d", &k, &l, &m, &n);
  if ((k<0)||(k>8)||(l<0)||(l>8)||(m<0)||(m>8)||(n<0)||(n>8)) 
  {
    printf("Введены неверные координаты!");
    return 1;
  }
  if ((k==m)&&(l==n))
  {
    printf("Ладья уже находится в точке назначения.");
    return 1;
  }
  if ((k == m) || (l == n))
  {
    printf("Ладья может добраться до точки назначения за один ход.\n");
  } else {
    printf("Ладья не может добраться до точки назначения за один ход.\n");
    printf("Промежуточное поле: %d,%d", m, l);
  }
  return 0;
}
