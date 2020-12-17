#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
int main()
{
    using namespace std;
    const int N = 6;

    string s1[N] = { "thinkers", "buffon", "for", "heavy","can", "for"};
    string s2[N] = {"metal", "any", "food","elegant", "deliver", "for"};

    set<string> A(s1, s1+N); 
    set<string> B(s2, s2+N); 

    ostream_iterator<string, char> out(cout, " ");

    cout<<"Set A: ";
    copy(A.begin(), A.end(), out);
    cout<<endl;

    cout<<"Set B: ";
    copy(B.begin(), B.end(), out);
    cout<<endl;

    cout << "Union of A and B:\n";//set_union()两个集合合并
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout<<endl;

    cout << "Intersection of A and B:\n";//set_interaction() 求两个集合的交集
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout<<endl;

    cout<<"Difference of A and B:\n";//set_difference()求A-B
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout<<endl;

    set<string> C;
    cout<<"*Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>> (C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout<<endl;

    string s3("grungy");
    C.insert(s3);
    cout<<"*Set C after insertion:\n";
    copy(C.begin(), C.end(), out);
    cout<<endl;


    //lower_bound(k):返回一个iterator，指向 key值大于等于k的第一个元素
    //upper_boudn(k):返回一个iterator，指向 key值小于k的第一个元素
    cout<<"*Showing a range:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    //此处lower_bound返回grungy
    //此处upper_bound返回metal
    cout<<endl;
    
    return 0;
}