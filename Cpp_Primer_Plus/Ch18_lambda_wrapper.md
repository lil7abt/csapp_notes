# Lambda函数 + Wrapper
* lambda表达式，表达式一般都是从方括号[]开始，然后结束于花括号{}，花括号里面就像定义函数那样，包含了lamdba表达式体
```c++
//Lambda Prototype
[capture list] (params list) mutable exception -> return type{function body}

auto add = [](int a, int b) -> int {return a+b;};//指明返回类型
auto multiply = [](int a, int b){return a*b;}    //自动推断返回类型
int sum = add(2, 5);
int product = multiply(2, 5);
```
原理:每定义一个lambda，编译器自动生成一个匿名类，运行时返回一个匿名的closure type，其实就是rvalue。

Mutable指示符:用来说明是否可以修改捕获的变量
Exception; 异常设定

## 为什么
### 以下四点
* Proximity
* Brevity
* Efficiency
* Capability
The main motivation for adding lambdas to C++ was to enable using a **function-like
expression** as an argument to a function expecting a function pointer or functor as an
argument.   
* **Lambda 表达式就是用于创建匿名函数的**

**方括号[]**:闭包(lambda-introducer)，闭包的强大在于可以通过传值或者ref的方式捕捉其封装作用域内的变量,方括号就是用来捕捉模式及变量。*这个引入符的作用就是表明，其后的 lambda 表达式以何种方式使用（正式的术语是“捕获”）这些变量（这些变量能够在 lambda 表达式中被捕获，其实就是构成了一个闭包）*

* `[ ]`: 不捕获任何外部变量
* `[=]`: 以值的形式捕获所有外部变量; 此时lambda体不允许修改外部变量，对外部变量的任何修改都会引发编译错误，除了使用mutable关键字，表示可以修改。
* `[&]`: 以引用的形式捕获所有外部变量
* `[x, &y]`: x 以值的形式， y以引用的形式
* `[=, &z]`: z 以引用的形式，其他的以值的形式
* `[&, x]`: x以值的形式，其余变量以引用的形式

## Wrapper
The function wrapper lets you rewrite the program so that it uses just one instantiation for function pointers, function objects, and lambdas with same call signation(E.g: `double(double)`). The function template, is declared in `functional` header file.
```c++
std::function<double(char, int)> fdci;
```