#ifndef __STACK__H__
#define __STACK__H__
typedef unsigned long Item;

class stack
{
private:
    enum {MAX=10}; //constant specific to this clas
    Item items[MAX];//holds stack items
    int top;//index for top stack item
public:
    stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
};

#endif  //!__STACK__H__