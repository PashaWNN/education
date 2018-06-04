#include <stdio.h>
#include <math.h>

int main() {
  float x;
  printf("Input X: ");
  scanf("%f", &x);
  float y;
  printf("Input Y: ");
  scanf("%f", &y);
  float z;
  printf("Input Z: ");
  scanf("%f", &z);
  float a;
  float b;
  a = (1 + y) * (x+(y/x*x+4))/(exp(-x-2)+1/x*x+4);
  b = (1+cos(y-2))/(pow(x, 4)/2+pow(sin(z), 2));
  printf("A = %f\nB = %f\n", a, b);
  return 0;
}
