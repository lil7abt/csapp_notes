# Variadic Template 可变模板
为了实现 参数个数 都可变的 template function/template class

有以下几个知识点:
* Template parameter packs
* Function parameter packs
* Unpacking a pack
* Recursion

## Template- and Function- parameter packs 
```C++
template<typename... Args>  // Args is a template parameter pack
void show_list1(Args... args)// args is a function parameter pack
{
...
}
```
T matches a single type
Args matches any num of types including none.

## Unpacking the Packs
```C++
template<typename... Args>  // Args is a template parameter pack
void show_list1(Args... args)// args is a function parameter pack
{
    show_list1(args...); //passes unpacked args to show_lsit1()
}
show_list1(5, 'L', 0.5);//Function call, pack these three parameters in to args
//so, the notation args... expands to a list of discrete function arguments
```
## Using Recursion in Variadic Template Functions
The central idea is to unpack the function parameter pack; As usual with recursion, it's important to make sure that there is a call that terminates the recursion.

可变参数函数模板, 经常会使用递归(recursive)进行处理包(pack)参数, 需要一个非可变参数(nonvariadic)函数模板,结束递归, 当最后一次调用时, 会调用非可变参数版本, 则递归结束;