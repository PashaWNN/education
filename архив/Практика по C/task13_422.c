#include <stdio.h>
#include <string.h>


int main() {
  FILE *f = fopen("f", "r");
  static char s[256];
  static char max[256];

  if (f == NULL) {
    printf("Ошибка открытия файла f");
  } else {
    while (!feof(f)) {
      if (fscanf(f, "%s\n", &s)) {
        if ( strlen(s) >= strlen(max) ) {
          strcpy(max, s);
        }
      }
    }
    printf("Наиболее длинная строка: \'%s\'\n", max);  
  }
  return 0;
}
