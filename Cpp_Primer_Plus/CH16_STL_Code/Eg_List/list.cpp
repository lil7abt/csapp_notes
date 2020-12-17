#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void outint(int n) {std::cout<<n<<" ";}

int main()
{
    using namespace std;
    list<int> one(5,2); // list of 5 2s
    
    int stuff[5] = {1, 2, 4, 8, 6};

    list<int> two;
    two.insert(two.begin(), stuff, stuff+5);

    int more[6] = {6, 4, 2, 4, 6, 5};

    list<int> three(two);
    three.insert(three.end(), more, more+6);

    cout << "List one: ";
    for_each(one.begin(),one.end(), outint);
    cout << endl << "List two: ";
    for_each(two.begin(), two.end(), outint);
    cout << endl << "List three: "; //--> 1 2 4 8 6 6 4 2 4 6 5
    for_each(three.begin(), three.end(), outint);

    three.remove(2); //delete all 2s --> 1 4 8 6 6 4 4 6 5
    cout << endl << "List three minus 2s: ";
    for_each(three.begin(), three.end(), outint);

    three.splice(three.begin(), one);//合并2个list函数。time-constant
    //1st argument: 一个iterator of the destination list用来标明插入位置
    //2nd argument: source list, 被剪切到destination list里面去了
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List one: ";
    for_each(one.begin(), one.end(), outint);

    three.unique(); //删除相邻重复的元素
    cout << endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);

    three.sort(); //从小到达排列
    three.unique(); 
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    two.sort();
    three.merge(two); //将两个有序列表合并，第二个列表会变空
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List two after merge: ";
    for_each(two.begin(), two.end(), outint);
    cout << endl;

    return 0;
}
