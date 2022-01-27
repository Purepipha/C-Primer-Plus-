// stack.h -- Class Stack protype and  member function protype
#ifndef STACK_H_
#define STACK_H_

const int NSIZE = 35; // 

struct customer
{
    char fullname[NSIZE];
    double payment;
};

typedef struct customer Item;

class Stack
{
private:
    static const int MAX = 10; // also enum{MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
};



#endif