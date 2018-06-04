#include <stdio.h>

int main() {
  char str[256];
  printf("Введите строку:\n");
  fgets(str, 256, stdin);
  char res[256];
  int j = 0;
  int mode = 0;
  for (int i = 0; i < sizeof(str); i++)
  { 
    if (str[i] == '.') 
    { 
      res[j]=str[i];
      mode = 1; 
    } else {
      if (str[i] == ',') 
      {
        if (mode) 
        { 
          res[j] = str[i];
        } else {
          j--;
        }
      }
      else if (str[i] == '3')
      {
        if (mode)
          {
            res[j] = '+';
          } else {
            res[j] = str[i];
          }
      }
      else res[j] = str[i];
    }
    j++;
  }
  if (!mode)
  {
    printf("В строке нет точек!\n");
    return 1;
  }
  res[j]='\0';
  printf("Результат:\n%s", res);
  return 0;
}
