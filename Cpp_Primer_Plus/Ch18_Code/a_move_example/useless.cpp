#include <iostream>
#include <utility>
class Useless
{
private:
    int n;
    char * pc;
    static int ct;
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    // constructors in copy&move versions
    Useless(const Useless & f); //regular copy constructor
    Useless(Useless && f);      //move constructor
    // assignment operator=() in copy and move versions
    Useless & operator=(const Useless & f);
    Useless & operator=(Useless && f);
    ~Useless();                 //destructor
    Useless operator+(const Useless & f) const;
    
    void ShowData() const;
};

int Useless::ct=0;
Useless::Useless()
{
    ++ct;
    n  = 0;
    pc = nullptr;
    // cout<<"default constructor called, num of object: "<<ct<<endl;
}

Useless::Useless(int k):n(k)
{
    ++ct;
    // cout<<"int constructor called, num of objects: "<<ct<<endl;
    pc = new char[n];
    // ShowObject();
}

Useless::Useless(int k, char ch): n(k)
{
    ++ct;
    // cout<<"int, char constructor called, num of objects: "<< ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
    {
        pc[i]=ch;       
    }
    // ShowObject();
}
Useless::Useless(const Useless & f): n(f.n) //copy constructor
{
    ++ct;
    // cout<<"copy constructor called, num of objects: "<< ct <<endl;
    pc=new char[n];
    for(int i=0; i<n; i++)
        pc[i]=f.pc[i];
    // ShowObject();
}
Useless::Useless(Useless && f): n(f.n)
{
    ++ct;
    // cout<<"move constructor called; num of objects: "<< ct <<endl;
    pc   = f.pc;     // steal address
    f.pc = nullptr;  // give old object nothing in return
    f.n  = 0;
    // ShowObject();
}
Useless::~Useless()
{
    // cout<<"destructor called, objects left: "<< --ct <<endl;
    // cout<<"deleted object:\n";
    // ShowObject();
    delete [] pc;
}
Useless Useless::operator+(const Useless & f) const
{
    // cout<<"Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i++)
    {
        temp.pc[i]=pc[i];
    }
    for (int i = n; i < temp.n; i++)
    {
        temp.pc[i]=f.pc[i-n];
    }
    // cout<<"temp object:\n";
    // cout<<"Leaving operator+()\n";
    return temp;    
}
// void Useless::ShowObject() const
// {
//     cout<<"num of elements: "<<n;
//     cout<<"Data address: "<<(void*)pc<<endl;
// }
void Useless::ShowData() const
{
    if(n==0)    
        std::cout<<"(object empty)";
    else
    {
        for (int i = 0; i < n; i++)
        {
            std::cout<<pc[i];
        }
    }
    std::cout<<std::endl;
}

Useless & Useless::operator=(const Useless & f) // copy assignment
{
    std::cout << "copy assignment operator called:\n";
    if(this==&f)
        return *this;
    delete [] pc;
    n = f.n;
    pc = new char[n];
    for (int i = 0; i < n; i++)
    {
        pc[i]=f.pc[i];
    }
    return *this;    
}
Useless & Useless::operator=(Useless && f)//move assignment
{
    std::cout << "move assignment operator called:\n";
    if (this==&f)
    {
        return *this;
    }
    delete [] pc;  //deleted the original data in the target
    n    = f.n;    //steal the source object's attribute f.n
    pc   = f.pc;   //steal the source object's attribute f.pc
    f.n  = 0;      //reset the source object's attribute f.n, just like the initialization of one object
    f.pc = nullptr;//reset the source object's attribute f.pc, cause data is still there. 
    return *this;
    
}


int main()
{
    // {
    //     Useless one(10, 'x');
    //     Useless two = one; // copy
    //     Useless three(20, 'o');
    //     //the expression one+three invokes Useless::operator+(), and the rvalue reference f binds
    //     // to the rvalue temporary object returned by the method.
    //     Useless four (one + three);  //calls operator+()
        
    //     cout<<"object one: ";
    //     one.ShowData();
    //     cout<<"object two: ";
    //     two.ShowData();
    //     cout<<"Object three: ";
    //     three.ShowData();
    //     cout<<"Object four: ";
    //     four.ShowData();
    // }

    //Eg.2
    using std::cout;
    {
        Useless one(10, 'x');
        Useless two = one + one; //move constructor used
        cout<<"Object one: ";
        one.ShowData();
        cout<<"Object two: ";
        two.ShowData();

        Useless three, four;
        cout<<"***three=one\n";
        three = one; //automatic copy assignment, lvalue=lvalue;
        cout<<"now object three = ";
        three.ShowData();
        cout<<"an object one = ";
        one.ShowData();


        cout<<"***four=one + two\n";
        four = one + two; //automatic move assignment, lvalue=rvalue
        cout<<"now object four = ";
        four.ShowData();

        cout<<"***four = move(one)\n";
        four = std::move(one); //forced move assignment
        cout<<"now object four = ";
        four.ShowData();
        cout<<"and object one = ";
        one.ShowData();
    }

}