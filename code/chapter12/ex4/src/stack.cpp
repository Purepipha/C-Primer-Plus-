// stack.cpp -- methods for Stack class
#include "stack.h"

Stack::Stack(int n)
{
    size = n;
    pitems = new Item[n];
    top = 0;
}

Stack::Stack(const Stack & st)
{
    size = st.size;
    pitems = new Item[st.size];
    
    for(top = 0; top < st.top; top++)
        pitems[top] = st.pitems[top];
    top = st.top;
}

Stack::~Stack()
{
    size = 0;
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item)
{
    if(top == size)
        return false;
    pitems[top++] = item;
    return true;
}

bool Stack::pop(Item & item)
{
    if(top == 0)
        return false;
    item = pitems[--top];
    return true;
    // if(top > 0)
    // {
    //     item = pitems[--top];
    //     return true;
    // }
    // return false;
}

Stack & Stack::operator=(const Stack & st)
{
    if(this == &st)
        return *this;
    size = st.size;
    pitems = new Item[st.size];
    
    for(top = 0; top < st.top; top++)
        pitems[top] = st.pitems[top];
    top = st.top;
    return *this;
}