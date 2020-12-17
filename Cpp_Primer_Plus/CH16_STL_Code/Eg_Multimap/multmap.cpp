#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
    using namespace std;
    MapCode codes;

    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Staten Island"));
    codes.insert(Pair(415, "San Rafael"));
    codes.insert(Pair(510, "Berkeley"));

    cout<< "* Num of cities with area code 415: "
        << codes.count(415)<<endl;
    cout<< "* Number of cities with area code 718: "
        << codes.count(718) << endl;
    cout<< "* Number of cities with area code 510: "
        << codes.count(510) << endl;

    cout<<"Area Code    City\n";
    MapCode::iterator it;
    for (it = codes.begin(); it !=codes.end(); it++)    
    {
        cout<<"    "<<(*it).first<<"    "
            <<(*it).second<<endl;
        /* code */
    }
    	
    //multimap的equal_range()函数，来自于<algorithm>，使用前提是container的元素是有序的
    //函数返回一个pair，左边是左边界，右边是右边界，左闭右开，都是map的一个iterator
    //函数参数是上下界
    pair<MapCode::iterator/*左边界*/, MapCode::iterator/*右边界*/> range=codes.equal_range(718);
    cout<<"Cities with area code 718: \n";
    for (it = range.first; it!=range.second; it++)
    {
        cout<<(*it).second<<endl;
    }
    // cout<<range.first<<endl;
    // cout<<range.second<<endl;
    return 0;

}