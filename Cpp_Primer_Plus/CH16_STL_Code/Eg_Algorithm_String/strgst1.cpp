#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    using namespace std;
    string letters;

    cout<<"Enter the letter grouping (q to quit): ";
    while (cin>>letters&&letters !="q") 
    {
        cout<<"Permutations of "<<letters<<endl;
        sort(letters.begin(), letters.end());
        cout<<letters<<endl;


        // 全排列的函数: next_permutation(), prev_permutation
        // 是对container里面通过两个iterator as argument定义的range进行全排列
        while (next_permutation(letters.begin(), letters.end()))
        {
            cout<<letters<<endl;
        }
        cout<<"Enter next sequence (q to quit): ";
        
    }
    cout<<"Done.\n";
    return 0;
    
}