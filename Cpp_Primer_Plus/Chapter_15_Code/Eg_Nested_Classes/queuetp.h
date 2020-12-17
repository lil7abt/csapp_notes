#ifndef __QUEUETP__H__
#define __QUEUETP__H__


template <class Item>
class QueueTP
{
private:
    enum {Q_SIZE=10};
    /*****Node class, as a nested class******/
    class Node
    {
    public:
        Item item;
        Node * next;
        Node(const Item & i): item(i), next(0){}
    };
    Node * front;    // pointer to the front of the Queue
    Node * rear;     // pointer to the rear of the Queue
    int items;        // the counter for the items in Queue
    const int qsize; // the max num of items in Queue
    QueueTP(const QueueTP & q): qsize(0) {}
    QueueTP & operator = (const QueueTP & q) {return   *this;}

public: 
    QueueTP(int qs = Q_SIZE);
    ~QueueTP();
    bool isempty() const
    {
        return items==0;
    }
    bool isfull() const
    {
        return items==qsize;
    }
    int queuecount() const
    {
        return items;
    }
    bool enqueue(const Item &item);  //add item to the rear
    bool dequeue(Item &item);        //remove from front
};

/********class methods**********/
template <class Item>
QueueTP<Item>::QueueTP(int qs):qsize(qs)//初始化的constructor
{
    front = rear = 0;
    items = 0;
}
template <class Item>
QueueTP<Item>::~QueueTP()//循环删除第一个元素，直到第一个元素为空
{
    Node *temp;
    while (front!=0)
    {
        temp=front;
        front=front->next;
        delete temp;
    }    
}
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
    if (isfull())
    {
        return false;
    }
    Node *add= new Node(item);
    items++;
    if (front==0)
        front=add;
    else
        rear->next = add;
    rear=add;
    return true;    
}
//place former front item into item variable and remove from queue
template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
    if (front==0)
    {
        return false;   
    }
    item = front->item; //用item来接从queue删除出来的第一个item
    items--;
    Node * temp = front; //把原front指针赋值到temp指针
    front  = front->next;//把现front指向原front的next
    delete temp;         //删掉temp指针变量
    if (items==0)
    {
        rear = 0;
    }
    return true;    
}


#endif  //!__QUEUETP__H__