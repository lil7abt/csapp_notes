#include <iostream>
// #include <vector>
// #include <string>

using namespace std; // make definitions visible


int main()
{
    double wages[3]={10000.0, 20000.0, 30000.0};
    short stacks[3]={3,2,1};

    //here are two ways to get the address of an array with array element
    double *pw = wages;
    short *ps= &stacks[0];

    cout<<"pw="<<pw<<", *pw="<<*pw<<endl;
    pw=pw+1;
    cout<<"add 1 to the pw pointer:\n";
    cout<<"pw ="<<pw <<"*pw="<<*pw<<"\n\n";

    cout<<"access 2 elements with array notation\n";
    cout<<"stacks[0]="<<stacks[0]
        <<", stacks[1]="<<stacks[1]<<endl;
    cout<<"access 2 elements with pointer notation\n";
    cout<<"*stacks ="<<*stacks
        <<", *(stacks+1)="<<*(stacks+1)<<endl;

    cout<<sizeof(wages)<<" =size of wages array\n";
    cout<<sizeof(pw)<<"=size of pw pointer\n";
    
    return 0; // terminate the main function
}