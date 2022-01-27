// stack.h -- class defination for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
    private:
        enum {MAX = 10};
        Item * pitems;
        int top;            // index for top stack item
        int size;           // number of elements
    public:
        Stack(int n = MAX);
        Stack(const Stack & st);
        ~Stack();
        bool isempty() const;
        bool isfull() const;
        // push() return false if stack is full, ture otherwise
        bool push(const Item & item);
        // pop() return false if stack is empty, true otherwise
        bool pop(Item & item);
        Stack & operator=(const Stack & st);
};
#endif