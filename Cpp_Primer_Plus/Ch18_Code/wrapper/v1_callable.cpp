#include "somedefs.h"
#include <iostream>

double dub(double x) {return 2.0*x;}
double square(double x) {return x*x;}

int main()
{
    using std::cout;
    using std::endl;

    double y=1.21;

    cout << "Function poiner dub:\n";
    cout << " "<<use_f(y, dub)<<endl;//typename F is set to a pointer to function
    cout << "Function pointer square:\n";
    cout << " " << use_f(y, square)  << endl;//typename F is set to a pointer to function, same as the first
    cout << "Function object Fp:\n";
    cout << " " << use_f(y, Fp(5.0)) << endl; //typename F is set to Fp, cause Fp is an object of class Fp
    cout << "Function object Fq:\n";
    cout << " " << use_f(y, Fq(5.0)) << endl;//typename F is set to Fq, cause Fq is an object of class Fq
    cout << "Lambda expression 1:\n";
    cout << " " << use_f(y, [](double u) {return u*u;}) << endl;//typename F is set to whatever types the compiler uses for lambda
    cout << "Lambda expression 2:\n";
    cout << " " << use_f(y, [](double u) {return u+u/2.0;}) << endl;
    return 0;
}