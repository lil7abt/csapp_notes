# Special Member Functions C++11
## Following 6 types of SMF
1. move constructor(C++11)
2. move assignment operator(C++11)
3. default constructor
4. copy constructor
5. copy assignment operator
6. destructor

## Defaulted and Deleted Methods
因为SMF可以被compiler自动创造，所以有default和delete的两个关键字来激活或者取消compiler创造默认SMF
```C++
Someclass & operator=(const Someclass &) = default;//default keyword can explicitly delcare the defaulted versions of these methods
Someclass(const Someclass &) = delete; //delete keyword can prevent the compiler from using a particular method.

```

## Delegating Constructors
Delegation: Use a constructor as part of the definition of another constructor,如果要写很多个constructor，而且其中部分代码重复。
```c++
class Notes
{
    int k;
    double x;
    std::string st;
public:
    Notes();
    Notes(int);
    Notes(int, double);
    Notes(int, double, std::string);
};
Notes::Notes(int kk, double xx, std::string stt): k(kk), x(xx), st(stt){..do something..};
Notes::Notes()                   : Notes(0, 0.01, "Oh")   {..do other things..}
Notes::Notes(int kk)             : Notes(kk, 0.01, "Ah") {/* do yet other stuff*/ }
Notes::Notes(int kk, double xx ) : Notes(kk, xx, "Uh")   {/* ditto*/ }
```

## Inheriting Constructors

## Managing Virutal Methods: override and final
1. Override 虚函数重载: 确保派生类中声明的重载函数跟基类的许函数有相同的签名 
2. Final    阻止继承，需函数重载:阻止类的进一步派生，和虚函数的进一步重载