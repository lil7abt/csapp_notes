#include <iostream>

/*****Example Reference Passing for Function*****/
// struct Demo
// {
//     char name[100];
//     int count;
// };
// using namespace std;
// void func1(Demo demo);//传递实参，需要创建副本，即对传入数据作修改，都不会影响my_demo 
// void func2(const Demo *demo_p); //传递指针, 指针可能传递个null过来，必须要检查有效性
// void func3(const Demo &demo_ref);//传递引用，引用则必然代表某个对象，不需要检查;加const,是不希望函数来去修改原始数据
//                                  //传递引用，只能传递变量/对象，不能传递常量
// int main()
// {
//     Demo my_demo={"hi",0};
//     Demo *my_demo_p=&my_demo;
//     Demo &my_demo_ref=my_demo;
//     func1(my_demo);
//     func2(my_demo_p);
//     func3(my_demo_ref);

//     return 0;
// }
// void func1(Demo demo)
// {
//     cout<<demo.name<<endl;
// }
// void func2(const Demo *demo_p)
// {
//     cout<<demo_p->name<<endl;
// }
// void func3(const Demo &demo_ref)
// {
//     cout<<demo_ref.name<<endl;
// }
/*****Reference Passing for Function*****/

// const int ArSize=80;
// char * left(const char *str, int n=1);
// int main()
// {
//     using namespace std;
//     char sample[ArSize];
//     cout<<"Enter a string:\n";
//     cin.get(sample, ArSize);
//     char *ps=left(sample, 4);
//     cout<<ps<<endl;
//     delete [] ps;// free new string
//     return 0;
// }
// // this function returns a pointer to a new strin
// // consisting of the first n characters in the str string
// char *left(const char *str, int n)
// {
//     if (n<0)   
//         n=0;
//     char *p=new char[n+1];// 
//     int i;
//     for(i=0;i<n&& str[i];i++)
//         p[i]=str[i]; //copy characters
//     while(i<=n)
//         p[i++]='\0';
//     return p;
// }


/***********Chapter 8 Exercise2 *************/
// struct CandyBar
// {
//     char name[1000];
//     double weight;
//     int calorien;
// };
// void setCandyBar(CandyBar &my_CandyBar,  char *ptr_my_name, double my_weight, int my_calorien)
// {
//     my_CandyBar.name = ptr_my_name;
//     my_CandyBar.weight = my_weight;
//     my_CandyBar.calorien= my_calorien;
// }
// void showCandyBar(CandyBar &my_CandyBar)
// {
//     using namespace std;
//     cout<<my_CandyBar.name<<endl;
//     cout<<my_CandyBar.weight<<endl;
//     cout<<my_CandyBar.calorien<<endl;
// }
// int main()
// {
//     CandyBar my_CandyBar;
//     char my_name[]="li li";
//     char *ptr_my_name;
//     ptr_my_name=my_name;
//     setCandyBar(my_CandyBar, ptr_my_name, 2.85, 350);
//     showCandyBar(my_CandyBar);
//     return 0;
// }
/***********Chapter 8 Exercise2 *************/

/***********Chapter 8 Exercise5 *************/
using namespace std;
template <typename T>
T max5 (T ar[5]);
int main()
{
    // int ar[5]={4,5,7,1,1};
    double ar[5]={1.2, 5.6, 1.5, 6.9, 1.1};
    cout<<max5(ar)<<endl;
    return 0;
}
template <typename T>
T max5(T *ar)
{
    T my_max = ar[0];
    for(int i=1; i<5; i++)
    {
        if(ar[i]>my_max)
        {
            my_max=ar[i];
        }
        else
        {
            
        }
        
    }
    return my_max;
}
/***********Chapter 8 Exercise2 *************/