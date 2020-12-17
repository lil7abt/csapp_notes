#include "queue_li.h"
#include <cstdlib>



Queue::Queue(int qs): qsize(qs) //init the qsize to qs
{
    front=rear=NULL;
    num_items=0;
}
//   第二种constructor写法: 
//   Queue:Queue(int qs): qsize(qs), front(NULL), reat(NULL), items(0)
//   {}



Queue::~Queue()//需要一个destructor来确保删除所有的nodes
{
    Node *temp;
    while (front!=NULL)
    {
        temp=front;
        front=front->next;
        delete temp;//delete删除的是这个指针所指向的东西
    }    
}


bool Queue::isempty() const
{
    return num_items==0;
}
bool Queue::isfull() const
{
    return num_items==qsize;
}
int Queue::queuecount() const
{
    return num_items;
}

bool Queue::enqueue(const Item &item)
{
    if(isfull())
        return false;
    else
    {
        Node *add = new Node;//生成一个无名的node指针
        add->item = item;//使其指向 argument传进来的 item
        add->next = NULL;
        num_items++;
        if (front==NULL)
        {
            front=add;
        }
        else
        {
            rear->next=add;
        }        
        rear=add;
        return true;
    }    
}
//其使用方法是 传递一个reference给此函数，来删除队首元素，并把原队首元素给这个ref
//返回值为是否删除成功
bool Queue::dequeue(Item &item) 
{
    if(front==NULL)
        return false;//检查队列是否为空
    else
    {
        item=front->item; //把队首元素内容赋值给这个参数reference
        num_items--;      //队列总个数 自减
        Node *temp =front;//搞一个临时元素指针获取front的指向
        front=front->next;//front指针指向原来front的next指向
        delete temp;      //删除temp指向的第一个item，可以来省内存
        if (num_items==0)
        {
            rear=NULL;
        }           
        return true;
    }    
}


void Customer::set(long when)
{
    processtime = std::rand()%3+1;
    arrive_time = when;
}