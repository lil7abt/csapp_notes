#ifndef __LIST__H__
#define __LIST__H__

namespace ch10_list
{
    typedef unsigned long Item;
    class list
    {
    private:
        struct node
        {
            Item item;
            node *next;
        };
        int size_;
        int capacity_;
        node *tail_;
        node *head_;        
    public:
        list(int capacity=10);
        ~list();
        int getSize();
        void add(Item );
        bool isEmpty();
        void visit(void (*pf)(Item &));
    };
    
}//chp10_list





#endif  //!__LIST__H__


