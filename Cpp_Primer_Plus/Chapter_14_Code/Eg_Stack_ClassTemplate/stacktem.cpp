#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using std::cin;
using std::cout;

int main()
{
    Stack<std::string> st; //create an empty stack with type of string
    char ch;
    std::string po;
    cout<<"Please enter A to add a purchase order \n"
        <<"P to process a PO, or Q to quit. \n";
    while(cin>>ch && std::toupper(ch)!='Q')
    {
        while(cin.get()!='\n')
            continue;
        if(!std::isalpha(ch))
        {
            cout<<'\a';
            continue;
        }
        switch (ch)
        {
        case 'A':
            break;
        case 'a': cout << "Enter a PO number to add: ";
                  cin>>PO;
                  if(st.isfull())
                    cout<<"stack already full\n";
                  else
                    st.push(po);
            break;
        case 'P': if (st.isempty())
                    cout << "stack already empty\n";
                  else
                  {
                      st.pop(po);
                      cout<<"PO #"<<po<<" popped\n";
                      break;
                  }                 
        default:
            break;
        }
        cout<<"Bye\n";
        retunr 0;
    }
}