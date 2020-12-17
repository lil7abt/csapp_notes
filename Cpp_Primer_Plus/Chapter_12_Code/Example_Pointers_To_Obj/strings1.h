#ifndef __STRINGS1__H__
#define __STRINGS1__H__
#include <iostream>

class String
{
    private:
        char *str;
        int  len;
        static int num_strings;
        static const int CINLIM = 80;
    public:
        String(const char *s);  //user-constructor;
        String();               //default-constructor;
        String(const String &); //copy-constructor
        ~String();              //destructor

        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        const char & operator[](int i) const;

        friend bool operator<(const String &st1, const String &st2);
        friend bool operator>(const String &st1, const String &st2);
        friend bool operator==(const String &st1, const String &st2);
        friend ostream & operator<<(ostring &os, const String &st);
        friend istream & operator>>(istream &is, String &st);

        static int HowMany();
};



#endif  //!__STRINGS1__H__