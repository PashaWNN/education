//
// Created by pashawnn on 2/22/18.
//
#ifndef COMPLEX_INT_COMPLEX_H
#define COMPLEX_INT_COMPLEX_H
#include <iostream>
#include <cstdlib>

class Complex {
private:
    double imaginary;
    double real;
public:
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator*(const Complex &c1, const Complex &c2);
    friend Complex operator/(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
    Complex() = default;
    operator std::string();
    Complex(double re, double im);
    double getReal();
    double getModZ();
    double getArgZ();
    double getImaginary();

};


#endif //COMPLEX_INT_COMPLEX_H
