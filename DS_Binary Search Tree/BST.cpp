#include <iostream>
#include<queue>
using namespace std;
template<class T>
class BSTNode {
    T el;
    BSTNode<T>* left;
    BSTNode<T>* right;
public:
BSTNode() {
    left = right = 0;
}
BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
    el = e;
    left = l;
    right = r;
}
T getKey(){return el;}
void setKey(T elem){el = elem;}
BSTNode<T>* getLeft(){return left;}
BSTNode<T>* getRight(){return right;}
void setLeft(BSTNode<T>* l){left = l;}
void setRight(BSTNode<T>* r){right = r;}

};
template<class T>
class BST {
protected:
    BSTNode<T>* root;
public:
    BST() {
        root = 0;
    }
    ~BST() {
        clearBST();
    }
    void clearBST() {
        root = 0;
    }
    bool isEmpty() const {
        return root == 0;
    }
    T* searchBST(BSTNode<T>*, const T& ) const;
    void breadthFirst();
    void insertBST(const T&);
    void visit(BSTNode<T>*);
    void InOrder(BSTNode<T>*);
     
};
template<class T>
void BST<T>::InOrder(BSTNode<T>* node)
{
    BSTNode<T>* p = node;
    if(p != 0)
    {
        InOrder(p->getLeft());
        visit(p);
        InOrder(p->getRight());
    }
}

template<class T>
T* BST<T>::searchBST(BSTNode<T>* p, const T& el) const
{
    while (p != 0)
    {
        if (el == p->getKey())
        {
            T* result = new T;
            *result = p->getKey();
            return result;
        }

        else if (el < p->getKey())
            p = p->getLeft();
        else p = p->getRight();
    }
    return 0;
}
template<class T>
void BST<T>::visit(BSTNode<T>* node)
{
    cout<<endl<<node->getKey();
}
template<class T>
void BST<T>::breadthFirst()
{
    queue<BSTNode<T>*> q;
    BSTNode<T>* p = root;
    if (p != 0)
    {
        q.push(p);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            visit(p);
            if (p->getLeft() != 0)
                q.push(p->getLeft());
            if (p->getRight() != 0)
                q.push(p->getRight());
        }
    }
}
template<class T>
void BST<T>::insertBST(const T& elem)
{
    BSTNode<T> *p = root, *prev = 0;
    while (p != 0)  // find a place for inserting new node;
    {
        prev = p;
        if (elem < p->getKey())
            p = p->getLeft();
        else p = p->getRight();
    }

    if (root == 0) // tree is empty;
        root = new BSTNode<T>(elem);
    else if (elem < prev->getKey())
        prev->setLeft(new BSTNode<T>(elem));
    else prev->setRight(new BSTNode<T>(elem));
}
int main()
{
    BST<int> t;
    t.insertBST(10);
    t.insertBST(20);
    t.insertBST(30);
    t.insertBST(15);
    t.insertBST(7);
    t.insertBST(3);
    t.insertBST(12);
    t.insertBST(17);
    t.insertBST(2);
    t.insertBST(4);

    t.breadthFirst();
    int* result = t.searchBST(t.getRoot(),30);
    if(result)cout<<endl<<"Found "<<*result;

    cout<<endl<<"In Order Depth First"<<endl;
    t.InOrder(t.getRoot());
    return 0;
}
===============================
#include <iostream>
#include<queue>

using namespace std;
template <class T>
class BSTNode
{
private:
    T Key;
    BSTNode<T> *left;
    BSTNode<T> *right;
public:
    BSTNode()
    {
        left=right=0;
    }
    BSTNode(const T& el,BSTNode<T> *l=0,BSTNode<T> *r=0)
    {
        Key=el;
        left=l;
        right=r;
    }
    BSTNode<T> * GetLeft()
    {
        return left;
    }
    BSTNode<T> * GetRight()
    {
        return right;
    }
    T GetKey()
    {
        return Key;
    }
    void SetRight(BSTNode<T> *r)
    {
        right=r;
    }
    void SetLeft(BSTNode<T> *l)
    {
         left=l;
    }
};
template <class T>
class BST
{
protected:
    BSTNode <T>* root;
public:
    BST()
    {
        root=0;
    }
    T * Search(T& el)
    {
        BSTNode <T> *p=root;
        while(p!=0)
        {
            if (el==p->GetKey())
                return &p->GetKey();
            else if (el<p->GetKey)
                p=p->GetLeft();
            else
                p=p->GetRight();
        }
	return 0;
    
    }
    void Insert (const T& el)
    {
        BSTNode <T> *p=root,*prev=0;
        while(p!=0)
        {
            prev=p;
            if (p->GetKey()>el)
                p=p->GetLeft();
            else
                p=p->GetRight();
        }
        if (root==NULL)
            root=new BSTNode<T>(el);

        else if (el<p->GetKey())
            prev->SetLeft(new BSTNode<T>(el)) ;
        else
            prev->SetRight(new BSTNode<T>(el));

    }
    void visit(BSTNode<T>* node)
{
    cout<<endl<<node->GetKey();
}

void breadthFirst()
{
    queue<BSTNode<T>*> q;
    BSTNode<T>* p = root;
    if (p != 0)
    {
        q.push(p);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            visit(p);
            if (p->GetLeft() != 0)
                q.push(p->GetLeft());
            if (p->GetRight() != 0)
                q.push(p->GetRight());
        }
    }
}

} ;

int main()
{
    cout << "Hello world!" << endl;
    BST<int>x;
    x.Insert(10);
    x.Insert(20);
    x.Insert(30);
    x.breadthFirst();
    return 0;
}
