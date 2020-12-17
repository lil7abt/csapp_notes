//this file impmenting the stock class

#include <iostream>
#include "stock00.h"

stock::stock(const std::string &co, long n, double pr)
{
    company=co;
    if (n<0)    
    {
        std::cerr<<"number of shares cannot be negative; "
                 <<company<<" shares set to 9.\n";
        shares=0;
    }
    else
    {
        shares=n;
    }
    share_val=pr;
    set_tot();  
}
stock::stock() //default constructor
{
    company="lili";
    shares=0;
    share_val=0;
    set_tot();
}


void stock::acquire(const std::string &co, long n, double pr)
{
    company=co;
    if (n<0)    
    {
        std::cout<<"number of shares cannot be negative; "
                 <<company<<" shares set to 9.\n";
        shares=0;
    }
    else
    {
        shares=n;
    }
    share_val=pr;
    set_tot();  
}
void stock::buy(long num, double price)
{
    if(num<0)
    {
        std::cout<<"Number of shares purchased cannot be negative. "
            <<"Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val=price;
        set_tot();
    }    
}
void stock::sell(long num, double price)
{
    using std::cout;
    if (num<0)
    {
        cout<<"num of shares sold cannot be negative. Tansaction is aborted.\n";
    }
    else if (num>shares)
    {
        cout<<"you cannot sell more than you have! Transaction is aboeted.\n";
    }
    else
    {
        shares -=num;
        share_val=price;
        set_tot();
    }
}
void stock::update(double price)
{
    share_val=price;
    set_tot();
}
void stock::show()
{
    std::cout   << "Company: " << company
                << " Shares: " << shares << '\n'
                << " Share Price: $" << share_val
                << " Total Worth: $" << total_val << '\n';
}