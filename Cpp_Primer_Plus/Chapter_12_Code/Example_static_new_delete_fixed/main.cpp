#include <iostream>
using std::cout;
#include "StringBad.h"

void callme1(StringBad &);// pass by reference
void callme2(StringBad);  // pass by value

int main()
{
    using std::endl;
    {
        cout<<"starting an inner block.\n";
        StringBad headline1("Celery stalks ar midnight");
        StringBad headline2("Lettucy Prey");
        StringBad sports("Spinach leves boul for dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2); //!!!TODO
        cout << "headline2: " << headline2 << endl;


        cout << "Initialize one object to another:\n";
        StringBad sailor = sports; //!!!TODO
                                   //!!!!This is equivalent with "StringBad sailor = StringBad(sports);"
                                  // This constructor is not predefined, so the compiler generates automatically one constructor
                                  // without knowing to increase the counter

        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;//!!!TODO: Assign Operator.
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n"; 

        cout << "End of main()\n";
    }
        system("pause");
    return 0;
}


void callme1(StringBad &rsb)
{
    cout<<"String passed by reference:\n";
    cout<<"   \""<<rsb<<"\"\n";
}
void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << " \"" << sb << "\"\n";
}
