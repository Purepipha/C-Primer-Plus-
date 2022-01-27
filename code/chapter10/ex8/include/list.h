// list.h -- definition of List class

#ifndef LIST_H_
#define LIST_H_

typedef double Item;

class List
{
private:
// struct Node dedintion
    struct Node
    {
        Item item;;
        struct Node * next;
    };
    enum {L_SIZE = 10};
// private meber
    Node * front;
    Node * rear;
    int items;
    const int lsize;
// member methods
    List(const List & lt):lsize(0){}
    List & operator=(const List & lt){return *this;}
public:
    List(int ls = L_SIZE);
    ~List();
    bool isempty() const;
    bool isfull() const;
    bool enlist(const Item & item);
    bool delist(Item & item);
    void visit(void (* pf) (Item & item));
};
#endif
