#include <iostream>
#include "list.h"

void showItem(ch10_list::Item &item);
void populateList(ch10_list::list &mylist, int numItems);

int main()
{
    using ch10_list::list;
    list my1stList;

    populateList(my1stList, 11);
    std::cout<<"Items in my1stList:"<<std::endl;
    my1stList.visit(showItem);
    list my2ndList(1000);
    populateList(my2ndList, 1000);
    std::cout<<"Items in my2ndList"<<std::endl;
    my2ndList.visit(showItem);
    return 0;
}
void showItem(ch10_list::Item &item)
{
    std::cout<<item<<std::endl;
}
void populateList(ch10_list::list &list, int numItems)
{
    std::cout<<"size before add items"<<list.getSize()<<std::endl;
    for (int i = 0; i < numItems; i++)
    {
        list.add(i);
    }
    std::cout<<"size after add items"<<list.getSize()<<std::endl;
    
}
