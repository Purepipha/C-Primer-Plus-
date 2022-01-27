// list.cpp -- member function of class List
// compile with ex8_uselist.cpp

#include <iostream>
#include "list.h"

List::List()
{
    header = 0;
}

List::List(const Item * aritem, int n)
{
    for(header = 0; header < n; header++)
    {
        items[header] = aritem[header]; 
    }
}

bool List::add_data(const Item & item)
{
    if(header < MAX)
    {
        items[header++] = item;
        return true;
    }
    else
        return false;
}

bool List::isempty() const
{
    return header == 0;
}

bool List::isfull() const
{
    return header == MAX;
}

void List::visit(void (*pf) (Item & item))
{
    for(int i = 0; i < header; i++)
        (*pf)(items[i]);
}