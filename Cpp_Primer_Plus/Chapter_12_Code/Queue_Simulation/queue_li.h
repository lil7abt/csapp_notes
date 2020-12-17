#ifndef __QUEUE_LI__H__
#define __QUEUE_LI__H__

class Customer
{
private:
    long arrive_time;
    int processtime;

public:
    Customer(){arrive_time=processtime=0;}
    void set(long when);
    long when() const {return arrive_time;}
    int  ptime() const {return processtime;}    
};

typedef Customer Item;


class Queue 
{  
    private:
        enum {Q_SIZE=10};//?
        struct Node //Node is a nested structure definition local to this class
        {
            Item item;
            struct Node *next;            
        };
        Node *front; //pointer to the head of the queue
        Node *rear;  //pointer to the rear of the queue
        int num_items;   //current num of items
        const int qsize;
        //如果copy constructor和assign operator暂时不用的话，可以先写个预先的这两个
        //首先可以覆盖compiler自动生成的这两个东西，防止出现未知结果，二个是是private，外面的世界并不能调用，如果调用则compiler会抱错
        Queue(const Queue &q): qsize(0){}//preemptive copy constructor;
        Queue & operator=(const Queue &q){return *this;}//preemptive assign operator
    public:
        Queue(int qs=Q_SIZE);
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item &item);//进队
        bool dequeue(Item &item);//出队
};




#endif  //!__QUEUE_LI__H__