// definition and methods for QueueTP class
#ifndef QUEUETP_H_
#define QUEUETP_H_

#include "workermi.h"
// template class definition
template <class T>
class QueueTP
{
private:
    struct Node
    {
        T item;
        struct Node * next;
    };
    Node * front;
    Node * rear;
    enum {SIZE = 10};
    int qcount;
    int qsize;
    QueueTP(const QueueTP & q):qsize(0){}
    QueueTP & operator=(const QueueTP & q){return * this;}
public:
    QueueTP(int size = SIZE);
    ~QueueTP();
    bool isemptey() { return qcount == 0; }
    bool isfull() { return qcount == qsize; }
    bool enqueue(const T & t );
    bool dequeue(T & t);
};

// methods for QueueTP class
template <class T>
QueueTP<T>::QueueTP(int size) : qsize(size)
{
    front = rear = nullptr;
    qcount = 0;
}

template <class T>
QueueTP<T>::~QueueTP()
{
    while(qcount != 0)
    {
        Node * temp;
        temp = front;
        front = front->next;
        delete temp;
        qcount--;
    }
}

template <class T>
bool QueueTP<T>::enqueue(const T & t)
{
    if (qcount < qsize)
    {
        if (isemptey())
        {
            Node * create = new Node;
            create->item = t;
            create->next = nullptr;
            front = rear = create;
            qcount++;
            return true;
        }
        else
        {
            Node * create = new Node;
            create->item = t;
            create->next = nullptr;
            rear->next = create;
            rear = create;
            qcount++;
            return false;
        }
    }
    else
        return false;
}

template <class T>
bool QueueTP<T>::dequeue(T & t)
{
    if (qcount > 0)
    {
        Node * temp;
        t = front->item;
        temp = front;
        front = front->next;
        delete temp;
        qcount--;
        return true;
    }
    else
        return false;
}

#endif