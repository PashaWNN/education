#include <stdio.h>
#include <math.h>

int main() {
  float U;
  float x;
  printf("Input X: ");
  scanf("%f", &x);
  float y;
  printf("Input Y: ");
  scanf("%f", &y);
  
  if (((1 - x*x) >= y) && ((pow(x, 2)+pow(1-y, 2))<1))
  {
    U = x - y;
  } else {
    U = x*y+7;
  }

  printf("U = %f\n", U);
  return 0;
}
