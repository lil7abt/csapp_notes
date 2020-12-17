# Chapter 11 Working with classes
## Ch 11.1 Operator Overloading
实际上给class写了个函数，但是函数符号用的是标准大运算符   
**使用条件**   
1. 运算符的左边是 user-defined type
2. 重载运算符可以，但是不能破坏原运算符的syntax
3. 不能创造新的运算符
4. 以下几个标准运算符不可重载
   * sizeof
   * .
   * .*
   * ?:
   * typeide
   * const_cast
   * dynamic_cast
   * reinterpre_cast
   * static_cast
## Ch 11.2 Friends 友元函数
场景: use non-member function to solve the problem of getting the operands in the desired oder. But nomn-member function cannot directly access private data in a class. So, the friend fucntion cann access the private members of a class
有三种friends:
1. Friend function:
   1) create a prototypein the class declaration: `friend Time operator*(double m, const Time &t)`
   2) write the function definition: `Time operator*(double m, const Time &t)` 
2. Friend class
3. Friend member function
## Ch 11.3 Automatic Conversions and type casts for classes
