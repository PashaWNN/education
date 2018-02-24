#include <iostream>
#include "complex.h"

int main() {
    double re;
    double im;
    std::cout << "Complex int." << std::endl;
    std::cout << "Enter real part of an integer 1: ";
    std::cin >> re;
    std::cout << "Enter imaginary part of an integer 1: ";
    std::cin >> im;

    double re2;
    double im2;
    std::cout << "Complex int." << std::endl;
    std::cout << "Enter real part of an integer 2: ";
    std::cin >> re2;
    std::cout << "Enter imaginary part of an integer 2: ";
    std::cin >> im2;
    Complex c1(re, im);
    Complex c2(re2, im2);
    std::cout << "First: " << std::string(c1) << std::endl;
    std::cout << "Second: " << std::string(c2) << std::endl;
    std::cout << "First + second = " << std::string(c1+c2) << std::endl;
    std::cout << "First - second = " << std::string(c1-c2) << std::endl;
    std::cout << "First * second = " << std::string(c1*c2) << std::endl;
    std::cout << "First / second = " << std::string(c1/c2) << std::endl;

    return 0;

}