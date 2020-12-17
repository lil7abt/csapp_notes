#ifndef __STOCK00__H__
#define __STOCK00__H__

#include <string>

class stock
{
    private: //class members that can be accessed only through the public member functions (data hiding)
        std:: string company;
        long shares;
        double share_val;
        double total_val;        
        void set_tot() //-->defined in class declaration --> inline function
        {
            total_val=shares*share_val;
        }
    public://identifies class members that constitute the public interface for the class (abstraction)
        stock(const std::string &co, long n, double pr);
        stock();
        ~stock()
        {
            std::cout<<"Bye, "<<company<<"!\n";
        }
        void acquire(const std::string & co, long n, double pr);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();

};//; is required after class definition


#endif  //!__STOCK00__H__