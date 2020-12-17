#include <iostream>
#ifndef __STRINGBAD__H__
#define __STRINGBAD__H__
class StringBad
{
private:
    char *str;  //****pointer to string*****
                //用指针而不用char数组来代表名称，是说 class声明并不分配内存给这个string，
                //而是用constructor中的new来分配内存给这个string
                //这样做是为了避免在class声明中提前限制string size

    int len;  //length of string
    static int num_strings;  //****num of objects*****
                             //static属性的特征:程序只创造一个static class variable的copy，
                             //不管它生成了几个objects.也就是说，
                             //static member is shared among all objects of that class, much as a phone number might be shared among all member of a family
                             // convenient for data that should be private to a class but that should have same value for all class objects
public:
    StringBad & operator=(const StringBad &);//fixed: explicite assign-operator to perform a deep-copy; argument is a reference, the return value is also a reference
    StringBad(const StringBad & st);// fixed: explicite copy-constructor
    StringBad(const char *s);       // user-defined constructor
    StringBad(/* args */);          // default constructor
    ~StringBad();
    
    friend std::ostream & operator<<(std::ostream &os, const StringBad &st);
};



#endif  //!__STRINGBAD__H__