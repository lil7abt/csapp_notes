## Move Semantics
- **l-value**: 左值，就是一个**数据对象(数据值+存储地址)**，在内存中的位置有一个可识别的地址，通常为一个变量，因此就有一个特定的内存地址，和对应的数据类型和值域 
- **l-value-reference**: 左值引用
- **r-value**: 右值，单个的字面量(一种文字或数字的符号或度量值)，没有特定的内存位置
- **r-value-referebce**: 右值引用
- **reference**:引用
1. 非常量左值non-const lvalue reference引用永远无法绑定右值!!
E.g:
```C++
//错误:函数的参数类型是左值引用，所以类型不匹配
double triangle(double & a, double &b, double &c){...}
triangle(3,4,5);
//正确
double triangle(const double & a, const double &b, const double &c){...}//常量左值引用
triangle(3,4,5);
```
*非常量左值引用永远无法绑定右值!!(临时变量 就是没有变量名的对象)*
*左值引用只能绑定左值，右值引用只能绑定右值!!*
*常量左值引用却是个奇葩，它可以算是一个“万能”的引用类型，它可以绑定非常量左值、常量左值、右值，而且在绑定右值的时候，常量左值引用还可以像右值引用一样将右值的生命期延长，缺点是，只能读不能改 `const int & a = 1;`*   
2. 非常量引用不能绑定到临时变量，因为临时变量是右值   
3. 为什么要区分左值和右值    
4. 深度拷贝   
    1) 对象拷贝的实质是source对象和destination对象分别是拥有两个独立的内存区域，也就是其变量有两个不同的内存地址   
    2) source和destination对象类型相同，起码要相容   
    3) source和destination对象的内容数据 相同
    4) 修改其中一个的对象的数据，都不会影响另外一个   
5. 右值引用: 必须一同初始化 `int&& c=5;`.说白了就是用&&来区分右值, 右值引用的目的是为了延长用来初始化对象的生命周期, 右值引用还可以用于函数参数
Eg:
```C++
#include <iostream>
void display_num(int & n)
{
    std::cout<<"display_num(int & n)"<<std::endl;
    std::cout<<n<<std::endl;
}
void display_num(int && n)
{
    std::cout<<"display_num(int &&)"<<std::endl;
    std::cout<<n<<std::endl;
}
int main()
{
    int j=23;
    display_num(j);
    display_num(73);
}
```


6. **Move**    
1) 消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率。    
2) 能够更简洁明确地定义泛型函数。

右值引用是用来支持转移语义的。转移语义可以将资源 ( 堆，系统对象等 ) 从一个对象转移到另一个对象，这样能够减少不必要的临时对象的创建、拷贝以及销毁，能够大幅度提高 C++ 应用程序的性能。临时对象的维护 ( 创建和销毁 ) 对性能有严重影响。

转移语义是和拷贝语义相对的，可以类比文件的剪切与拷贝，当我们将文件从一个目录拷贝到另一个目录时，速度比剪切慢很多。

有了右值引用和转移语义，我们在设计和实现类时，**对于需要动态申请大量资源的类，应该设计转移构造函数和转移赋值函数**，以提高应用程序的效率。

标准库提供了函数 std::move，这个函数以非常简单的方式将左值引用转换为右值引用
```c++
void ProcessValue(int& i)
{
    std::cout<<"LValue processed: "<< i << std::endl;    
}
void ProcessValue(int&& i)
{
    std::cout<<"RValue processed: "<< i << std::endl;
}
int main()
{
    int a = 0;
    ProcessValue(a);            //LValue processed: 0
    ProcessValue(std::move(a)); //RValue processed: 0
}
```
7.**Perfect Forwarding**
Use case: 需要将一组参数 原封不动的 传递给另一个函数
原封不动包括: 参数的值不变，左值/右值，const/Non-const    

E.g: forward_value是一个泛型函数，将参数传递给另一个函数 process_value
```c++

/*variant 1*/
template <typename T> void forward_value(const T & val)
{
    process_value(val);
}
template <typename T> void forward_value(T & val)
{
    process_value(val);
}
int a=0;
const int &b =1;
forward_value(a);//int &
forward_value(b);
forward_value(2);

/*variant 2: 只需要定义一次，接受一个右值引用的参数，就能够将所有的参数类型原封不动的传递给目标函数*/
template <typename T> void forward_value(T&& val)
{
    process_value();
}
int a = 0;
const in & b=1;
forward_value(a);// int&
forward_value(b);// const int&
forward_value(2);// int&&
// T&& 的推导规则为：
// 右值实参为右值引用，左值实参仍然为左值引用 => 一句话，就是参数的属性不变。
```
8. **Copy vs. Move**
* copy 就是照着别人的东西复制一份，所需的工作量随拷贝对象的不同而不同，比如拷贝一个字很快，拷贝一本书很慢
* move 就是把别人书上的名字擦掉，写上自己的。因为 move 不需要复制，所以很快。其实就是把自己的指针指过去，把原属主的指针指向别处。
* Objects initialized with an l-value object use the copy constructor/assignments, and objects initialized wiht an r-value object use the move constructor/assignments.
* **std::move(obj)**: is an rvalue, 