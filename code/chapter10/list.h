// list.h -- protype class list
// version 00

#ifndef LIST_H_
#define LIST_H_
typedef double Item;
class List
{
private:
    enum{MAX = 10};
    Item items[MAX];
    int header;
public:
    List();
    List(const Item * aritem, int n);
    bool add_data(const Item & item);
    bool isempty() const;
    bool isfull() const;
    void visit(void (*pf) (Item & item));
};


#endif