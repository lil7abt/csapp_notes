#ifndef __COMPLEX__H__
#define __COMPLEX__H__

class Complex
{
private:
    double real_;
    double imaginary_;
public:
    Complex(double real, double imaginary);
    Complex();
    friend Complex operator+(const Complex &a, const Complex &b);
    friend Complex operator-(const Complex &a, const Complex &b);
    friend Complex operator*(const Complex &a, const Complex &b);
    friend Complex operator*(double a, const Complex &b);
    friend Complex operator~(const Complex &a);
    double getReal();
    double getImaginary();


};



#endif  //!__COMPLEX__H__