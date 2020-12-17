# Friends, Exceptions, and More

## Friends
### Friends Class
* See Eg. 
* The class friendship:提供了一种可以直接操纵 某 原内对象 的类

### Shared Friends
为了实现某个函数能access两个不同类的private data。
如下面的例子，两个类都有自己的时钟，需要有一个函数来同步这两个时钟
```c++
class Analyzer; // forward declaration,可以让compiler在读到Probe的时候知道Analyzer是个类
class Probe
{
    friend void sync(Analyzer & a, const Probe & p); //sync a to p
    friend void sync(Probe & p, const Analyzer & a); //sync p to a
};
class Analyzer 
{
    friend void sync(Analyzer & a, const Probe & p); //sync a to p
    friend void sync(Probe & p, const Analyzer & a); //sync p to a
}
//define the friend functions
inline void sync(Analyzer & a, const Probe & p)
{
    ...
}
inline void sync(Pobe & p, const Analyzer & a)
{
    ...
}
```
### Nested Classes
一个类里面再定义一个类就是nested classes. 
目的:避免名称杂乱.是为了辅助implementation of another class
特点:外面的类的member functions可以创建和使用里面类的对象。如果外面的世界要用这个里面类nested class，它就必须要被定义在public区，且使用双冒号::


nested class 嵌套类的引入是为了更好的命名空间使用。
嵌套类是名字在其外围类的作用域中可见，但在其他类作用域或定义外围类的作用域中不可见。
嵌套类的名字将不会与另一作用域中声明的名字冲突。


但嵌套类是独立的类，基本上与他们的外围类不相关，因此外围类和嵌套类的“对象”是互相独立的。
嵌套类型的对象不具备外围类所定义的成员，同样，外围类的成员也不具备嵌套类所定义的成员。

* Nested classes 有两种access
    * 一个nested class定义的地方控制整个scope,也就是说，决定了哪一部分能创建这个类的对象
    * 一个nested class的public, private, protected区 能提供 access control给类的对象

### Exceptions
中文内容: 三个关键字 try, catch, throw
* throw: 当问题出现时，程序抛出异常
* catch: 捕获异常
* try: try的代码块 将 可能激活 特定异常，后面跟着一个或多个catch块
```c++
        try
        {
        // 保护代码
        }catch( ExceptionName e1 )
        {
        // catch 块, 用于处理异常的代码
        }catch( ExceptionName e2 )
        {
        // catch 块
        }
        //thow可以在代码任何地方抛出异常
        double division(int a, int b)
        {
            if( b == 0 )
            {
                throw "Division by zero condition!";
            }
            return (a/b);
        }
```
**C++的标准异常**   
异常	描述:
* **std::exception**	该异常是所有标准 C++ 异常的父类。
* std::bad_alloc	该异常可以通过 new 抛出。
* std::bad_cast	该异常可以通过 dynamic_cast 抛出。
* std::bad_exception	这在处理 C++ 程序中无法预期的异常时非常有用。
* std::bad_typeid	该异常可以通过 typeid 抛出。
* **std::logic_error**	理论上可以通过读取代码来检测到的异常。
* std::domain_error	当使用了一个无效的数学域时，会抛出该异常。
* std::invalid_argument	当使用了无效的参数时，会抛出该异常。
* std::length_error	当创建了太长的 std::string 时，会抛出该异常。
* std::out_of_range	该异常可以通过方法抛出，例如std::vector和std::bitset<>::operator* []()。
* **std::runtime_error**	理论上不可以通过读取代码来检测到的异常。
* std::overflow_error	当发生数学上溢时，会抛出该异常。
* std::range_error	当尝试存储超出范围的值时，会抛出该异常。
* std::underflow_error	当发生数学下溢时，会抛出该异常。

**定义新的异常**
```c++
#include <iostream>
#include <exception>
using namespace std;
struct MyException: public exception
{
    const char * what() const throw()
    {
        return "C++ Exception";
    }
};
int main()
{
    try
    {
        throw MyException();
    }
    catch(MyException & e)
    {
        std::cout<<"MyException caught<<std:::endl;
        std..cout<<e.what()<<std:.endl;
    }
    catch(std::exception & e)
    {

    }
}
```
**C++ Primer Plus**

**.1 Calling abort()**   
`cstdlib/stdlib.h: abort()` can terminates the program directly, without returning first to `main()`. In general, different compilers issue different abort messages.   
**.2 Returning an Error Code**   
**.3 The Exception Mechanism**      
Exceptions provide a way to transfer control from one part of a program to another. 3 Steps:
1) Throwing an exception: in essence, is a jump, it tells a program to jump to statements at another location.
2) Catching an exception wih a handler: is followed by a brace-enclosed block of code that indicaes the actions to take.
3) Using a try block: identifies a block of code for which particular exceptions will be activated.

*If any statement in the try-block leads to an exception being thrown, the catch blocks after this try-block, which matches the thrown exception type, will handle the exception.*

**.4 Using Objects as Exceptions**      

### Runtime Type Identification(RTTI)运行时类型识别
指程序能够使用基类的指针或引用来检索其所指对象的实际派生类型, The RTTI features allow a program to detect the type of an object.The
dynamic_cast operator is used to cast a derived-class pointer to a base-class pointer; its
main purpose is to ensure that it’s okay to invoke a virtual function call.The typeid
operator returns a type_info object.Two typeid return values can be compared to
determine whether an object is of a specific type, and the returned type_info object can
be used to obtain information about an object.  
RTTI only works for classes that have virtual functions
3 components supporting RTTI:


### Type Cast Operators