//
// Created by Dell on 5/1/2022.
//

#ifndef UNTITLED3_NODE_H
#define UNTITLED3_NODE_H
template<class T>
class Node
{
    T info;
    Node* next;
public:
    Node(T data, Node* n=0)
    {
        info=data;
        next=n;
    }
    Node* getNext()
    {
        return next;
    }
    void setNext(Node*x )
    {
        next=x;
    }
    T getInfo ()
    {
        return info;
    }
    void setInfo (T a)
    {
        info=a;
    }
};
#endif //UNTITLED3_NODE_H
