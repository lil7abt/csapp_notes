#include <iostream>
#include <string>

void show_list3(){};
//variadic template可以创建一个 参数个数不定的 函数模版
template<typename T>
void show_list3(const T & value)
{
    std::cout << value << '\n';
}

template<typename T, typename... Args>
void show_list3(T value, Args... args)
{
    std::cout << value << ", ";
    show_list3(args...);
}

int main()
{
    int    n         = 14;
    double x         = 2.71828;
    std::string mr = "Mr.String objects!";
    show_list3(n, x);
    show_list3(x*x, '!', 7, mr);
    return 0;
}