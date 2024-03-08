#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
class Queue
{
private:
    int size;
    int count;
    T *queue;

public:
    Queue(int size);
    void enQue(T data);
    void deQue();
    int getCount();
    void display();
    
};
#endif