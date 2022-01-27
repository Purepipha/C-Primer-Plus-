// stacktp1.h -- modified Stack template
#ifndef STACKTP1_H_
#define STACKTP1_H_

template <class Type>
class Stack
{
private:
    enum {SIZE = 10};
    int stacksize;
    Type * items;
    int top;
public:
    Stack(int ss = SIZE);
    Stack(const Stack & st);
    ~ Stack() { delete [] items; }
    bool isempty() const { return top == 0; }
    bool isfull() const { return top == stacksize; }
    bool push(const Type & item);
    bool pop(Type & item);
    Stack & operator=(const Stack & st);
};

template <class Type>
Stack<Type>::Stack(int ss)
{
    stacksize = ss;
    items = new Type[stacksize];
    top = 0;
}

template <class Type>
Stack<Type>::Stack(const Stack<Type> & st)
{
    items = new Type[st.stacksize];
    for (int i = 0; i < st.top; i++)
    {
        items[i] = st.items[i];
    }
    top = st.top;
}

template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < stacksize)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
    if (this == &st)
        return *this;
    else
    {
        items = new Type[st.stacksize];
        for (int i = 0; i < st.top; i++)
        {
            items[i] = st.items[i];
        }
        top = st.top;
        return *this;
    }
}
#endif