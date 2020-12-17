#include <iostream>
#include <cstring>
#include "strings1.h"

using std::cout;
using std::cin;

int String::num_strings=0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char *s)
{
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len=4;
    str=new char[1];
    str[0]='\0';
    num_strings++;
}

String::String(const String &st)
{
    num_strings++;
    len=st.len;
    str= new char[len+1];
    std::strcpy(str, st.str);
}

//assign a string to a string
String & String::operator=(const String &st)
{
    if(this==&st)
        return *this;
    delete [] str; //删掉被赋值的obj的str属性内容
    len=st.len;
    str=new char[len+1];
    std::strcpy(str, st.str);
    return *this;
}
//assign a C-style string to a string
String & String::operator=(const char *s)
{
    delete [] str;
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str, s);
    return *this;
}
//read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}
//read-only char access for const String
const char & String::operator[] (int i) const
{
    return str[i];
}

//overloaded operator friends function
bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str)<0);
}
bool operator>(const String &st1, const String &st2)
{
    return st1<st2;
}
bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
    st = temp;
    while (is && is.get() != '\n')
    continue;
    return is;
}


