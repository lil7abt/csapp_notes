#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

// typedef std::ios_base::fmtflags format;
// typedef std::streamsize precis;
// format setFormat();
// void restore(format f, precis p);

// Brass methods

Brass::Brass(const string &s, long an, double bal)
{
    fullName = s;
    acctNum  = an;
    balance  = bal;
}
void Brass::Deposit(double amt)
{
    if (amt<0)
        cout<<"Negative deposit not allowed; "
            <<"Deposit is called.\n";
    else
        balance += amt;
}
void Brass::Withdraw(double amt)
{
    if (amt<0)
    {
        cout<<"Negative withdraw not allowed, process called.\n";           
    }
    else if (amt>balance)
    {
        cout<<"Not enough money on your account, process cancelled.\n";
    }
    else 
    {
        balance = balance-amt;
        cout<<"Money withdrawed.\n";
    }
}
double Brass::Balance() const
{
    return balance;
}
void Brass::ViewAcct() const
{
    cout<<"Client: "<<fullName<<endl;
    cout<<"Account Number: "<<acctNum<<endl;
    cout<<"Balance: "<<balance<<endl;    
}

//BrassPlus methods
BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r): Brass(s, an, bal)
{
    maxLoan  = ml;
    owesBank = 0.0;
    rate     = r;
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r): Brass(ba)
{
    maxLoan  = ml;
    owesBank = 0.0;
    rate     = r;
}
//Redefine how ViewAccT() works
void BrassPlus::ViewAcct() const
{
    Brass::ViewAcct();//invoke the original ViewAcct() function to display the base portion
    cout<<"Max Loan: "<<maxLoan<<endl;
    cout<<"Owed to Bank: "<<owesBank<<endl;
    cout<<"Loan Rate: "<<rate<<endl;
}
void BrassPlus::Withdraw(double amt)
{
    double bal = Balance();//因为不能直接获取基类的属性，
                           //只能通过调用基类的public方法来获取
    if (amt<=bal)
        Brass::Withdraw(amt);
    else if (amt<=bal+maxLoan-owesBank)
    {
        double advance = amt - bal;
        owesBank += advance*(1.0+rate);
        cout<<"Bank advance: "<<advance<<endl;
        cout<<"Finance charge: "<<advance*rate<<"\n";
        Deposit(advance);
        Brass::Withdraw(amt);
    }   
    else
        cout<<"Credit limit exceeded. Transaction cancelled.\n";    
}
