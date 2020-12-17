#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    using namespace std;
    stack st;
    char ch;
    unsigned long po;
    cout<<"please enter A to add a purchase order,\n"
        <<"P to process a PO, or Q to quit.\n";
    while(cin>>ch&&toupper(ch)!='Q')
    {
        while (cin.get()!='\n')
        {
            continue;
        }
        if (!isalpha(ch))
        {
            cout<<'\a';
            continue;
        }
        switch (ch)
        {
            case 'a':
                /* code */
                    break;
            case 'A': cout<<"Enter a PO num to add: ";
                    cin>>po;
                    if (st.isfull())
                    {
                        cout<<"stack is full\n";
                    }
                    else
                        st.push(po);
                    break;
                            
            case 'P':
            case 'p': if(st.isempty())
                        cout<<"stack is empty\n";
                    else 
                        st.push(po);
                        cout<<"PO #"<<po<<" popped\n";
                    break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
        
    }
    cout<<"Bye!\n";
    return 0;
}