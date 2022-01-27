// list.cpp -- methods for List class
#include "list.h"


List::List(int n):lsize(n)
{
    front = rear = nullptr;
    items = 0;
}

List::~List()
{
    while(!isempty())
    {
        Node * temp;
        temp = front;
        front = front->next;
        delete temp;
        items--;
    }
}

bool List::isempty() const
{
    return items == 0;
}

bool List::isfull() const
{
    return items == lsize;
}

bool List::enlist(const Item & item)
{
    if(items < lsize)
    {
        Node * add = new Node;
        add->item = item;
        if(isempty())
        {
            front = rear = add;
            rear->next = nullptr;
            items++;
            return true;
        }
        else
        {
            rear->next = add;
            rear = add;
            rear->next = nullptr;
            items++;
            return true;
        }
    }
    return false;
}

bool List::delist(Item & item)
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

void List::visit(void (* pf) (Item & item))
{
    Node * temp;
    temp = front;
    for(int i = 0; i < items; i++)
    {
        (* pf) (front->item);
        front = front->next;
    }
    front = temp;
}