#include <iostream>
#include <initializer_list>

double sum(std::initializer_list<double> il);
double average(const std::initializer_list<double> &ril);

int main()
{
    using std::cout;
    cout<<"List 1: sum = "<<sum({2,3,4})
        <<", ave = "<<average({2,3,4})<<'\n';
    std::initializer_list<double> dl={1.1, 2.2, 3.3, 4.4, 5.5};
    
}   