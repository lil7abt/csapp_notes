#include <iostream>
#include "Complex.h"

Complex::Complex(double real, double imaginary)
{
    this->real_      = real;
    this->imaginary_ = imaginary;
}

Complex::Complex()
{
    this->imaginary_ = 0;
    this->real_      = 0;
}
Complex operator+(const Complex &a, const Complex &b)//friend function
{
    Complex res;
    res.real_      = a.real_      + b.real_;
    res.imaginary_ = a.imaginary_ + b.imaginary_;
    return res;
}

Complex operator-(const Complex &a, const Complex &b)
{
    Complex res;
    res.real_      = a.real_      - b.real_;
    res.imaginary_ = a.imaginary_ - b.imaginary_;
    return res;
}


Complex operator*(double a, const Complex &b)
{
    Complex res;
    res.real_      = a * b.real_;
    res.imaginary_ = a * b.imaginary_;
    return res;
}
Complex operator*(const Complex &a, const Complex &b)
{
    Complex res;
    res.real_      = a.real_ * b.real_ - a.imaginary_ * b.imaginary_;
    res.imaginary_ = a.real_ * b.imaginary_ + a.imaginary_ * b.real_;
    return res;    
}
Complex operator~(const Complex &a)
{
    Complex res = Complex(a.real_ , (0 - a.imaginary_));
    return res;
}

double Complex::getReal() 
{
    return real_;
}
double Complex::getImaginary()
{
    return imaginary_;
}
