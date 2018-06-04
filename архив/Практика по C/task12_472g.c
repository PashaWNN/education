#include <stdio.h>

int main() {
  FILE *f = fopen("f", "r");
  float min;
  float max;
  float val;
  if (f == NULL) {
    printf("Ошибка открытия файла f");
  } else {
    if (fscanf(f, "%f\n", &val)) {
      min = val;
      max = val; //Initializing with first float
    }
    while (!feof(f)) {
      if ( fscanf(f, "%f\n", &val ) ) {
        if (val>max) {
          max = val;
        }
        if (val<min) {
          min = val;
        }
      }
    }
    fclose(f);    
  }
  printf("Max value: %f\nMin value: %f\nSum: %f\n", max, min, max+min);
  return 0;
}
