#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T> //functor class defines operator()()
class TooBig
{
    private:
        T cutoff;
    public:
        TooBig(const T &t): cutoff(t) //initializer-list
        {

        }

        bool operator() (const T & v) //overload the operato()
        {                             //argument is an object-ref of the type T
            return v > cutoff;        //return true/false if the argumen the attribute cutoff
        }

};

void outin(int n) {std::cout<<n<<" ";}

int main()
{
    using std::list;
    using std::cout;
    using std::endl;
    
    
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10); // range cosntructor, vals is the vals-array's pointer, points to the 1st element of the array
    list<int> etcetera(vals, vals + 10);

    cout<<"Originanl lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outin);
    cout<<endl;
    for_each(etcetera.begin(), etcetera.end(), outin);
    cout<<endl;

    TooBig<int> f100(100);
    //创建了这个仿函数类的一个对象，且用cons tructor来初始化其属性cutoff为100
    //有点类似c语言的回调函数 
    yadayada.remove_if(f100);
    etcetera.remove_if(TooBig<int>(200)); //construted a anonym function object to set the cutoff as 200
    cout<<"Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outin);
    cout<<endl;
    for_each(etcetera.begin(), etcetera.end(), outin);
    cout<<endl;

    return 0;
    
}