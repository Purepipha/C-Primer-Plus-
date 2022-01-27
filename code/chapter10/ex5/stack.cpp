// stack.cpp -- member function for stack class
// compile with ex4.cpp

#include <cstring>
#include "stack.h"

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if(isfull())
        return false;
    strcpy(items[top].fullname,item.fullname);
    items[top++].payment = item.payment;
    return true;
}

bool Stack::pop(Item & item)
{
    if(top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

