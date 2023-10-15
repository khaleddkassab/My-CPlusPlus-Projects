//
// Created by Dell on 5/1/2022.
//
#include <cstddef>
#include "Node.h"
#include "SLL.h"

#ifndef UNTITLED3_STACKSLL_H
#define UNTITLED3_STACKSLL_H
template<class T>
class StackSLL
{
private:
    SLL <T> A;
public:
    void push(T x)
    {
        A.addtoHead(x);
    }
    T  pop()
    {
        T value=A.getValueAtHead();
        A.removeFromHead();
        return value;
    }
    T top()
    {
        return A.getValueAtHead();

    }
    bool is_empty()
    {


        return A.isEmpty();
    }
    void clear()
    {
        A.clear();
    }




};
#endif //UNTITLED3_STACKSLL_H
