#include <iostream>
#include "Complex.h"

int main()
{
    Complex a(3.0, 4.0);
    Complex b(2.0, 5.0);
    Complex c = ~b;
    std::cout<<c.getReal()<<std::endl;
    std::cout<<c.getImaginary()<<std::endl;


    return 0;
}
