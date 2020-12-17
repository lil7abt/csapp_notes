#include <iostream>
double hmean(double a, double b);

int main()
{
    double x, y, z;
    std::cout<<"Enter two numbers: ";
    while (std::cin>>x>>y)
    {
        try
        {
            z=hmean(x,y);
        }
        catch (const char * s)//exception type is a string; s is the argument
        {
            std::cout<<s<<std::endl;
            std::cout<<"Enter a new pair of numbers: ";
            continue;
        }
        std::cout<<"Harmonic mean of "<<x<<" and "<<y
                 <<" is "<< z <<std::endl;
        std::cout<<"Enter next set of numbers <q to quit>: ";
    }
    std::cout<<"Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if(a==-b)
        throw "bad hmean() argumens: a=-b not allowed";//like a return-statement, here is a string
    return 2.0*a*b/(a+b);
}