#include <cstddef>
#include "Node.h"
#include "SLL.h"
#include " StackSLL.h"

#ifndef UNTITLED3_QUEUESLL_H
#define UNTITLED3_QUEUESLL_H

#endif //UNTITLED3_QUEUESLL_H
template<class T>
class QueueSLL
{
    SLL <T> l;
public:
    void enqueue(T a)
    {
        l.addtoTail(a);
    }
    void dequeue()
    {
        l.removeFromHead();
    }
    T Front( )
    {
       return l.getValueAtHead();
    }
    bool isempty()
    {
        return l.isEmpty();
    }
    void clear()
    {
        l.clear();
    }



};
