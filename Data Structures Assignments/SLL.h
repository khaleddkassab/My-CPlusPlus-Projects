//
// Created by Dell on 5/1/2022.
//
#include <iostream>
#include <cstddef>
#include "Node.h"
#ifndef UNTITLED3_SLL_H
#define UNTITLED3_SLL_H
using namespace std;
template<class T>
class SLL {
    Node<T> *head, *tail;
public:
    SLL() { head = tail = 0; }

    void addtoHead(T data)
    {
        Node<T>* new_node=new Node<T>(data);
        if(head==NULL)
            head=tail=new_node;
        else
        {
            new_node->setNext(head);
            head=new_node;
        }
    }

    void addtoTail(T data)
    {
        Node<T>* new_node=new Node<T>(data);
        Node<T>* current=head;
        if(head==NULL)
            head=tail=new_node;
        else
        {
            while(current->getNext()!=NULL)
            {
                current=current->getNext();
            }
            current->setNext(new_node);
            tail=new_node;
        }

    }

    T removeFromHead()
    {
        Node<T>* new_node=head;

        if(head==NULL)
        {
            return NULL;
        }
        else
        {
            head=head->getNext();
            delete new_node;
            return head->getInfo();
        }
    }

    T removeFromTail()
    {
        Node<T>* new_node=head;
        if(head==NULL)
        {
            return ;
        }
        if(head->getNext()==NULL)
        {
            delete head;
            return ;
        }
        else
        {
            while(new_node->getNext()->getNext()!=NULL)
            {
                new_node=new_node->getNext();
            }
            delete new_node->getNext();
            new_node->setNext(NULL);

        }

    }

    T getValueAtHead()//a function that returns the value at head without deleting it
    {
        return head->getInfo();
    }
    bool isEmpty()
    {
        if(head==NULL&tail==NULL)
        {
            return true;
        }
        return false;
    }

    void clear()
    {
        SLL <T> l;
        if(l.isEmpty()==true)
        {
            return;
        }
        else
        {
            Node<T>* new_node=head;
            while(head->getNext()!=NULL)
            {
                new_node=head;
                head=head->getNext();
                delete new_node;
            }
            head= tail=NULL;
        }
    }

    friend ostream & operator<<(ostream &y, const SLL<T> &l);
};
template<class c>
 ostream & operator<<(ostream &y, const SLL<c> &l)
 {
    Node <c>* new_node=l.head;
    while(new_node!=NULL)
    {
        y<<new_node->getInfo()<<' ';
        new_node=new_node->getNext();
    }
    return y;
 }


#endif //UNTITLED3_SLL_H
