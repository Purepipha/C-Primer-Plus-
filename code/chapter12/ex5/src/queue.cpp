// queue.cpp - methods for Queue class

#include "queue.h"
#include <cstdlib>

Queue::Queue(int q):qsize(q)
{
    items = 0;
    front = rear = nullptr;
}
Queue::~Queue()
{
    while(!isempty())
    {
        Node * temp;
        temp = front;
        front = front->next;
        items--;
        delete temp;
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

bool Queue::enqueue(const Item & item)
{
    if(items < qsize)
    {
        Node * add = new Node;
        add->item = item;
        if(isempty())
        {
            front = rear =add;
        }
        else
        {
            rear->next = add;
            rear = add;
        }
        rear->next = nullptr;
        items++;
        return true;
    }
    return false;
}

bool Queue::dequeue(Item & item)
{
    if(items > 0)
    {
        Node * temp;
        item = front->item;
        temp = front;
        front = front->next;
        delete temp;
        items--;
        return true;
    }
    return false;
}

void Customer::set(long when)
{
    arrive = when;
    processtime = rand() % 3 + 1;
}