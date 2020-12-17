# Adventures in Functions: 主要概括与c的关于函数的区别
## Inline functions
An inline function replaces a function call with inline code;
Inline和macro的区别:   
1. inline 可以传递expressions
2. macro 不可以，只能简单傻瓜式的文字替换
## Reference Variables
C++ adds a new compound type to the language --> the reference variable, which acts as an alias, or an alternative name, for a previously defined variable. Main use is a formal argument to a function. **If you use a reference as an argument, the function works with the original daa instead of with a copy. References provide a convenient alternative to pointers for processing large structures with a function, and they are essential for designing classes.**   

"&" 符号的第二种含义，看下面例子:
```c++
    int rats;//
    int & rodents = rats;//makes rodents an alias for rats
```
The reference declaration allows you to use rats and rodents interchangeabley, both refer to the same value an the same memeory location.

###### 引用和指针的区别
1. 不存在空应用， 引用必须连接到一块合法内存
2. 一旦引用被初始化为一个对象，就不能被指向到另一个对象，指针可以在任何时候指向到另一个对象
3. 引用必须在创建的时候初始化，指针可以在任何时间初始化

## How to pass function arguments by reference
见本章代码部分
## Default arguments
MISRA禁止
## Function overloading --> Function Polymorphism
The key to function overloading is a function's argument list(signature). C++ enables you to define a set of functions with same name but different signatures. When you use the function, the compiler matches your use to the prototype that has the same signature
## Function templates (generic programming 泛型编程)
**1. function template**: is a generic function description; that is, it defines a function in terms of a generic type for which a specific type, such as int or double, can be substituted. By passing a type as a pararmeter to a template, you cause the compiler to generte a function for that particular type.   

Eg:
```c++
    template <typename AnyType>//setting up a template
                               //you can use keyword typename or class
                               //There is no ";" after this 
    void swap(AnyType &a, AnyType &b)
    {
        AnyType temp;
        temp = a;
        a=b;
        b=temp;
    }
```
*1. You should use templates if you need functions that apply the same algorithm to a variety of types*   
*2. The function templates don't make executable programs any shorter, the compiler will generate different version based on the function templates. And the final code doesn't contain any templates*   
*3. The benefits of using function templaates are that they make generating multiple function definitions simpler and more reliable*   
*4. In general, templates are placed in a header file that is then included in the file usin them*: 
```c++
    template <typename T>
    void swap(T &a, T &b); //1st template
    {
        ...
    }
    template <typemame T>
    void swap(T &a, T &b, int n); // 2nd template
    {
        ...
    // }
```


## Summary