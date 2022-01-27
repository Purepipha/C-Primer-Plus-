// queuetp.h -- queue template with a nested class
#ifndef QUEUETP_H_
#define QUEUETP_H_
#include <string>
template <class Item>
class QueueTP
{
private:
    class Node
    {
        public:
            Item item;
            Node * next;
            Node(const Item & i) : item(i), next(0) { }
    };
    enum {QSIZE = 10};
    Node * front;
    Node * rear;
    const int qsize;
    // static int items;
    int items;
    QueueTP(const QueueTP & q) : qsize(0) {}
    QueueTP & operator = (const QueueTP & q) { return * this; }
public:
    QueueTP(int qs = QSIZE);
    ~QueueTP();
    bool isempty() const { return items == 0; }
    bool isfull() const {return items == qsize; }
    int queuecount() const { return items; }
    bool enqueue(const Item & i);
    bool dequeue(Item & i);
};
// template <class Item>
// int QueueTP<Item>:: items = 0;
template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
    front = rear = 0;
    items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
    Node * temp;
    while (items > 0)
    {
        front = front->next;
        delete temp;
        items--;
    }
}

template <class Item>
bool QueueTP<Item>::enqueue(const Item & i)
{
    if (items < qsize)
    {
        Node * add = new Node(i);
        if (isempty())
        {
            front = rear = add;
        }
        else
        {
            rear->next = add;
            rear = add;
        }
        items++;
        return true;
    }
    else
        return false;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item & i)
{
    if (items > 0)
    {
        Node * temp = front;
        i = front->item;
        front = front->next;
        items--;
        delete temp;
        if (items == 0)
            rear = 0;
        return true;
    }
    else
        return false;
}
#endif