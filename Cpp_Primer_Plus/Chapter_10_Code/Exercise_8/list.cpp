#include <iostream>
#include "list.h"

namespace ch10_list
{
    list::list(int capacity)
    {
        this->capacity_=capacity;
        this->size_=0;
        this->head_= new node;
        this->tail_= head_;
    }
    list::~list()
    {
        if(this->size_==0)
        {
            delete this->head_;
        }
        node *current=this->head_;
        while (current!=0)
        {
            node *next = current->next;
            delete current;
            current=next;
        }    
    }
    int list::getSize()
    {
        return this->size_;
    }
    void list::add(Item item)
    {
        if(this->size_ < this->capacity_)
        {
            if (this->size_>0)
            {
                this->tail_->next = new node;
                this->tail_ = this->tail_->next;
            }
            this->tail_->item=item;
            this->size_++;        
        }
    }
    bool list::isEmpty()
    {
        return this->size_==0;    
    }
    void list::visit(void (*pf)(Item &item))//遍历visiting function, here pf is a funciton-pointer
                                        //the visit funcion applies this function to each item in the list
    {
        if (this->size_>0)
        {
            node current = *this->head_;
            for (int i = 0; i < this->size_; i++)
            {
                (*pf)(current.item);
                if (current.next!=NULL)
                {
                    current=*current.next;
                }            
            }        
        }    
    }
}//ch10_list


