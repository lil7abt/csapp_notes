#include <iostream>
#include "mytime.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planning(3,50);
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout<<"planning: ";
    planning.show();
    cout<<endl;

    cout<<"coding:  ";
    coding.show();
    cout<<endl;

    cout << "fixing time = ";
    fixing.show();
    cout << endl;      

    // total=coding.sum(fixing);
    total=coding+fixing+planning;//operator overloading, operator notation
    cout<<"coding.sum(fixing) = ";
    total.show();
    cout<<endl;

    return 0;
}