// queue.h -- definition of Queue class
#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
private:
    long arrive;
    int processtime;
public:

    Customer(){ arrive = processtime = 0;}

    void set(long when);
    long When() const {return arrive;}
    long Ptime() const {return processtime;}
};


typedef Customer Item;

class Queue
{
private:
    struct Node
    {
        Item item;
        struct Node * next;     // Node * next
    };
    enum{Q_SZIE = 10};
    // 
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    Queue(const Queue & q):qsize(0){}
    Queue & operator=(const Queue & q){return * this;}
public:
    Queue(int qs = Queue::Q_SZIE);         // why need to point to Queue class Q_SIZE
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};

#endif