#include <iostream>
#include <cstring>
#include "StringBad.h"

using std::cout;

int StringBad::num_strings = 0;//static class member不能在class declaration里面初始化。
                               //因为, declararion是描述如何分配内存，但不是真的分配内存。
                               //分配和初始化内存是 通过 按此format创造对象
                               // the static class meber should be initialized independently
                               //with a sperate statement outside the class declaration. 
                               //That's because the static class member is stored seperately rather than as part of an object.
                               //**Note: the init statement gives the type and uses the scope operator, but it doesn't use the static keyword.

                               // The exeception to the non-init of a static data member inside the class declaration is if the satic data member is a const of integral or enumeration type.



StringBad & StringBad::operator=(const StringBad &st) //explicite assign-operator;
{
    if(this==&st)             // object assgined to itself
        return *this;         // all done
    delete [] str;            // free the memory that str pointed to; If not so, the previous string will remain in memory; The program no longer has a pointer to the old string, that memory will be wasted.
    len = st.len;
    str = new char[len+1];    // get space for new string
    std::strcpy(str, st.str); // copy the string
    return *this;             // return reference to the invoking object
                              // Assignment doesn't not create a new obj, so you don't have to adjust the value of the static data memeber num_strings.
}

StringBad::StringBad(const StringBad & st) // explicite copy-constructor for deep copy
{
    num_strings++;             //handle static member update
    len = st.len;              //same length
    str = new char[len+1];     //allocate space
    std::strcpy(str, st.str);  //copy string to new location
    cout << num_strings << ": \"" << str
    << "\" object created\n"; // For Your Information
}
                               
StringBad::StringBad(const char *s)
{
    len = std::strlen(s); // strlen() returns the length fo a string, not count the terminating NULL character.
    str = new char[len+1];// the string is not stored in the object, but separately stored in heap memory.
                          // the object only stores information that tells where to find the string
    std::strcpy(str,s);
    num_strings++; //
    cout<<num_strings<<": \""<<str<<"\"object created\n";
}
StringBad::StringBad()
{
    len=4;
    str=new char[4];//
    std::strcpy(str, "C++");
    num_strings++; //
    cout<<num_strings<<": \""<<str<<"\" default object created\n";
}
StringBad::~StringBad()
{
    cout<<"\""<<str<<"\" object deleted, ";
    --num_strings;
    cout<<num_strings<<" left\n";
    delete [] str;// Required!!!!!!
                  // The str member points to the memory allocated with new.
                  // When a StringBad object expires, the str pointer expires
                  // But the memory str pointed to remains allocated unless you use delete to free it
                  // 删除一个对象只能free那些被objet占用的memory，但不能自动删除那些 对象自身的pointer指向的 内存
                  // 所以要用带delete statement 的deconstructor，来确保那些因为new来分配的内存会被freed,当这个对象expireds
                  // !!!!任何 你在constructor使用new来分配变量的时候都必须在对应的deconstructor里面用delete来释放内存
                  // If you use new [], then you should use delete []
}

std::ostream & operator<<(std::ostream &os, const StringBad &st)
{
    os<<st.str;
    return os;
}

