#include <iostream>
#include <list>
#include <algorithm>

void Show(int);

const int LIM = 10;

int main()
{
    using namespace std;
    int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
    list<int> la(ar, ar+LIM);
    list<int> lb(la);

    cout<<"Original list contents:\n\t";
    for_each(la.begin(), la.end(), Show);
    cout<<endl;

    la.remove(4);//this remove() is STL's own member function, can resize the container after removal
    cout << "After using the remove() method:\nla:\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;

    list<int>::iterator last;
    last = remove(lb.begin(), lb.end(), 4); 
    //this remove is not a member funciton.it cannot resize the list
    //it puts all the nonremoved items are at the beginning of the list, 
    //and it returns an iterator to the new past-the-end value.
    //You can use this iterator to fix, like the erase()
    cout << "After using the remove() function:\nlb:\t";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;

    lb.erase(last, lb.end());
    cout << "After using the erase() method:\nlb:\t";
    // cout << "";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;
    return 0;

}
void Show(int v)
{
    std::cout << v << ' ';
}