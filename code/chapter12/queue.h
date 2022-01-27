// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
// This queue will caontain Custormer items
class Customer
{
private:
    long arrive;                // arrive time for customer
    int processtime;            // processing time for customer
public:
    Customer() { arrive = processtime = 0; }

    void set(long when);
    long When() const { return arrive; }
    int Ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
// class scope definition
    // Node is a nested structure definition local to this c
    struct Node
    {
        Item item;
        struct Node * next;
    };
    enum{Q_SIZE = 10};
// private class members
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    // preemptive definitions to provent public copying
    Queue(const Queue & q):qsize(0){}
    Queue & operator=(const Queue & q){return * this;}
public:
    Queue(int qs = Q_SIZE);             // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);    // add item to end
    bool dequeue(Item & item);          // remove item form front
};

#endif