//
// Created by pashawnn on 2/22/18.
//

#include <cmath>
#include "complex.h"



Complex::Complex(double re, double im) {
    real = re;
    imaginary = im;
}

double Complex::getReal() {
    return real;
}

double Complex::getImaginary() {
    return imaginary;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.imaginary - c2.imaginary);
}

Complex operator/(const Complex &c1, const Complex &c2)
{
    double a = c1.real;
    double b = c1.imaginary;
    double c = c2.real;
    double d = c2.imaginary;
    return Complex((a*c+b*d)/(pow(c, 2)+pow(d, 2)), (b*c-a*d)/(pow(c, 2)+pow(d, 2)));
}

Complex operator*(const Complex &c1, const Complex &c2)
{
    double a = c1.real;
    double b = c1.imaginary;
    double c = c2.real;
    double d = c2.imaginary;
    return Complex(a*c - b*d, a*d + b*c);
}

double  Complex::getModZ() {
    return sqrt(pow(this->getReal(), 2) + pow(this->getImaginary(), 2));
}

double Complex::getArgZ() {
    return acos(this->getReal()/this->getModZ());
}

Complex::operator std::string() {
    return "Complex = " + std::to_string(this->real) + " + " + std::to_string(this->imaginary) + "i";
}
