#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;

char toLower(char ch) {return tolower(ch);}
string & ToLower(string & st);
void display(const string & s);

int main()
{
    vector<string> words;
    cout<<"Enter words(q to quit): \n";
    string input;

    while (cin>>input && input !="q")    
    {
        words.push_back(input);
    }
    cout<<"Input words are: \n";
    for_each(words.begin(), words.end(),display);
    cout<<endl;

    // a set can automatically sort its contents and a set allows only one copy of a key.
    set<string> wordset;
    transform(words.begin(), words.end(), insert_iterator<set<string>> (wordset, wordset.begin()), ToLower);
    cout<<"\nAlphabetic list of words:\n";
    for_each(wordset.begin(), wordset.end(), display);
    cout<<endl;

    //place word and frequency in map
    //in map, you can use the array notation with keys that serve as indexes to access he stored values.
    map<string, int> wordmap;// this map has 1st argument "string" as the key, the 2nd argument int as the value
    set<string>::iterator si;
    for (si = wordset.begin(); si != wordset.end(); si++)
    {
        wordmap[*si]=count(words.begin(), words.end(), *si);
    }
    cout<<"\nWord Frequency\n";
    for (si = wordset.begin(); si != wordset.end(); si++)
    {
        cout<<*si<<": "<<wordmap[*si]<<endl;
        
    }
    return 0;
}
string &  ToLower(string & st)//把string里面的每个char都变成小写。
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}
void display(const string & s)
{
    cout<<s<<" ";
}