# Ch1 习惯使用C++

## 1 把Cpp当作一个联合语言
    
## 2 使用const, enums, inlins 而不是 #define
    结论
    1. 对于单纯常量最好用const/enum替换#define
    2. 对于函数macro, 最好用inline来代替#define
## 3 只要可以就要使用const修饰
    const 可用在如下：
        1. pointer和iterator
        2. pointer，iterator 以及 reference 所指向的对象
        3. 函数的 参数，返回类型
        4. 在local变量
        5. member function...
    结论
     1 将某些东西声明为const 可帮助compiler识别 错误的使用
     2 编译器强制实行bitwise constness, 自己写的时候应该 写成 conceptual constness
        1） C++编译器要求const成员函数不能更改对象内的任何non-static成员变量，简单地说就是const成员函数中不能出现对non-static成员变量的赋值操作； 这种要求实质上是不能更改对象内的任何一个bit，因此叫做bitwise constness
        2） logical constness指的是，const成员函数可以修改它所处理对象内的**某些bits(即用mutable修饰)**，但前提是用户察觉不到这种修改。mutable可以去除non-static成员变量的bitwise constness约束。
     3 当const和non-const member function有几乎相同的implementation的时候，令non-const版本调用const版本可避免代码重复
## 4 确保任何对象在使用前都要初始化
    1）对ctor使用member initialization list
    2）对象的初始化顺序： 先base的ctor，再客人(成员变量的类)的ctor，最后自身的ctor
    3）不同源文件内定义的non-local static对象"的初始化问题： 因为C++对不同源文件的non-local static 对象初始化顺序没有明确定义
        a) 某个源文件中的non-local static对象初始化需要使用另一个源文件中的non-local static对象
        b) 但另一个源文件内的non-local static对象可能尚未被初始化
    解决方法：因为C++可以保证函数内的local static对象会在该第一次调用此函数时被初始化
        a) 将每个non-local static对象放到自己的专属函数中，这些函数返回一个reference指向它所含的对象
        b) 然后用户调用这些专属函数，而不直接使用这些对象

    *结论*
    1. 为built-in对象进行手工初始化， 因为C++只是有时候会主动初始化
    2. 为ctor使用initialization list, 且顺序要和class里面声明他们的顺序一样
    3. 为免除“跨源文件的初始化次序问题”，用local-static来代替non-local-static对象