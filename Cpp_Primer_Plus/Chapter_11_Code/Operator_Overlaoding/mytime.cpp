#include <iostream>
#include "mytime.h"
Time::Time()
{
    hours =0;
    minutes=0;
}
Time::Time(int h, int m)
{   
    hours=h;
    minutes=m;
}
void Time::addMin(int m)
{
    int res = m + this->minutes;
    if (res>59)
    {
        this->minutes=res-60;
        this->hours++;
        if(this->hours>23)
        {
            this->hours=0;
        }
        else
        {            
        }                
    }
    else{}
}
void Time::addHr(int h)
{
    if(this->hours+h>24)
    {
        this->hours = this->hours + h - 24;
    }
}
void Time::reset(int h, int m)
{
    hours=h;
    minutes=m;
}
// Time Time::sum(const Time &t) const// faster and more memory-efficient to just pass a referen——
// {
//     Time sum;
//     sum.minutes = this->minutes + t.minutes;
//     sum.hours = this->hours + t.hours + sum.minutes/60;
//     sum.minutes %=60;
//     return sum;
// }
/*****Note*****/
/* Don't return a reference to a local variable or another temporary object. 
When the function terminates and the local variable or temporary objects disappears, the reference becomes a reference to 
non-existent data*/
/*****Note*****/

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = this->minutes + t.minutes;
    sum.hours = this->hours + t.hours + sum.minutes/60;
    sum.minutes %=60;
    return sum;

}
void Time::show() const
{
    std::cout<<hours<<"hours, "<<minutes<<"minutes";
}
