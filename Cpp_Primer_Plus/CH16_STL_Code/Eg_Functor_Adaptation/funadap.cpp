#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional> // predefined functor to support the bind1st

void Show(double);
const int LIM = 6;

int main()
{
    using namespace std;

    double arr1[LIM] = {28, 29, 30, 35, 38, 59};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};

    vector<double> gr8(arr1, arr1+LIM);
    vector<double> m8(arr2, arr2+LIM);

    cout.setf(ios_base::fixed);//使输出用正常的记数方法显示浮点数(与科学计数法相对应).
    cout.precision(1); //设置显示浮点数精度值

    cout<<"gr8:\t";
    for_each(gr8.begin(), gr8.end(), Show);
    cout<<endl;

    cout<<"m8: \t";
    for_each(m8.begin(), m8.end(), Show);
    cout<<endl;

    vector<double> prod(LIM);//新建一个 vector，大小LIM个，存double类型的元素，叫prod
    transform(gr8.begin(), gr8.end(), prod.begin(), bind2nd(multiplies<double>(), 2.5));
    //transform()函数
    //前两个arguments是定义source sequence的iterator
    //第三个argument是destination sequence的首元素的iterator
    //第四个argument是必须是一个unary函数，这个函数作用于source sequence range内的所有元素，并把结果放到destination sequence

    //multiplies() functor是一个二元函数，此处不能用，
    //所以需要一个function adapter来把二元函数变成一个一元函数
    //就是bind1st和bind2nd类。

    //E.g: f2 is a binary funcion. 
    //By using bind1st, val is used as the 1st argument of the f2
    //By using bind2nd, val is used as the 2nd argument of the f2
    // binder1st(f2, val) f1;//Here, the f1 is a funcion object of the class bind1st
    // f1(x);//-->f2(val, x)
    //Ivoking the f1(x) with its single argument
    //returns the same value as invoking f2() with val as its 1st argument
    //and f1()'s own argument as its 2nd argument.


    cout<<"prod:\t";
    for_each(prod.begin(), prod.end(), Show);
    cout<<endl;
    
    return 0;
}
void Show(double v)
{
    std::cout.width(6);
    std::cout << v << ' ';
}