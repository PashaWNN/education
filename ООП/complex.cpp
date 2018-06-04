#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class Complex // класс комплексных чисел
{
   
 
// создаем конструкторы   
public:
   double re, im; // целая и мнимая части
   Complex() {};
 
   Complex (double r) // конструктор по умолчанию
   {
      re = r; 
      im = 0;
   }
 
   Complex (double r, double i) // конструктор по умолчанию
   {
      re = r; 
      im = i;
   } 
 
   Complex (Complex &c) // конструктор копирования
   {
      re = c.re; 
      im = c.im;
   }
 
   ~Complex() {}
 
   float abs() // Модуль комплексного числа
   {
      return sqrt(re * re - im * im);
   }     
 
   Complex & operator = (Complex &c) // перегрузка оператора присваивания
   {
      re = c.re;
      im = c.im;
 
      return (*this);
   }
 
   Complex Complex::operator + (Complex &c) // перегрузка оператора сложения
   {
      Complex temp;
 
      temp.re = re + c.re;
      temp.im = im + c.re;
 
      return temp;
   }
 
   Complex Complex::operator - (Complex &c) // перегрузка оператора вычитания
   {
      Complex temp;
 
      temp.re = re - c.re;
      temp.im = im - c.re;
 
      return temp;
   }
 
   Complex Complex::operator * (Complex &c) // перегрузка оператора умножения
   {
      Complex temp;
 
      temp.re = re*c.re;
      temp.im = re*c.im;
 
      return temp;
   }
 
   Complex Complex::operator / (Complex &c) // перегрузка оператора деления
   {
      Complex temp;
 
      double r = c.re * c.re + c.im * c.im;
      temp.re = (re * c.re + im * c.im) / r;
      temp.re = (im * c.re - re * c.im) / r;
 
      return temp;
   }   
 
};
 

 
int main()
{
    Complex value1(5,2);
    Complex value2(3,-3);
    printf("Первое число: %f+i%f\n", value1.re, value1.im);
    printf("Второе число: %f+i%f\n", value2.re, value2.im);
    Complex v3(value1 * value2);
    printf("Произведение: %f+i%f\n", v3.re, v3.im);
    printf("Сумма: %f+i%f\n", value1.re, value1.im);
    printf("Разность: %f+i%f\n", value1.re, value1.im);
    printf("Деление: %f+i%f\n", value1.re, value1.im);
    //cout << value1 << " " << value2 << endl;
 
    //cout << value1 + value2 << endl;
 
    //cout << value1 - value2 << endl;
 
    //cout << value1 * value2 << endl;
 
    //cout << value1 / value2 << endl;    
 
    //value1 = value2;
 
    //cout << value1 << " = " << value2 << endl;
 
    return 0;
}
