#include <iostream>
#include "Node.h"
#include "QueueSLL.h"
#include "SLL.h"
#include " StackSLL.h"
#include <cstddef>

using namespace std;
int priority(char a) {
    if (a == '+' || a == '-')
        return 1;

    if (a == '*' || a == '/')
        return 2;

    if (a == '^')
        return 3;


    return 0;
}

string convertToBinary(int x) {
    StackSLL<int> s;
    int i=0;

    while (x != 0)
    {
        int rem = x % 2; //take remainder
        x = x / 2;
        s.push(rem);
    }

    string b="",stringg="";

    while (!s.is_empty())
    {
        i=s.top();
        stringg+=to_string(i);
        s.pop();
    }
    return stringg;


}

template<class T>
void reverseQueue(QueueSLL<T> &q) {
    StackSLL<T> s;
    while (q.isempty() != true) {
        s.push(q.Front());
        q.dequeue();
    }
    while (s.is_empty() != true) {
        q.enqueue(s.top());
        s.pop();
    }
}

template<class T>
bool moveNthElem(QueueSLL<T> &Q, int n) {
    QueueSLL<T> new_q;
    T x;
    int counter = 1;
    while (Q.isempty() != true) {
        if (n == counter) {
            x = Q.Front();
            Q.dequeue();
            counter++;
        } else {
            new_q.enqueue(Q.Front());
            Q.dequeue();
            counter++;
        }
    }
    Q.enqueue(x);
    while (new_q.isempty() != true) {
        Q.enqueue(new_q.Front());
        new_q.dequeue();
    }
    return true;


}

template<class T>
int evaluatePostfix(string d) {
    StackSLL<T> S;
    int x = 0;
    int y = 0;
    int counter = 0;
    while (counter < d.length())
    {
        if (isdigit(d[counter]))
        {
            S.push(d[counter] - '0');
            counter++;
        } else {
            if (d[counter] == '+') {
                x = S.top();
                S.pop();
                y = S.top();
                S.pop();
                S.push(x + y);
                counter++;
            }
            if (d[counter] == '-') {
                x = S.top();
                S.pop();
                y = S.top();
                S.pop();
                S.push(y-x);
                counter++;
            }
            if (d[counter] == '*') {
                x = S.top();
                S.pop();
                y = S.top();
                S.pop();
                S.push(x * y);
                counter++;
            }
            if (d[counter] == '/') {
                x = S.top();
                S.pop();
                y = S.top();
                S.pop();
                S.push(y/x);
                counter++;
            }
        }
    }
    return (S.top());

}

template<class T>
string convertInfixToPostfix(string a) {
    int i = 0;
    string postfix;
    // using inbuilt stack< > from C++ stack library
    StackSLL<T> s;

    while (a[i] != '\0') {
        // if operand add to the postfix expression
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= '0' && a[i]<='9')) {
            postfix += a[i];
            i++;
        }
            // if opening bracket then push the stack
        else if (a[i] == '(') {
            s.push(a[i]);
            i++;
        }
            // if closing bracket encounted then keep popping from stack until
            // closing a pair opening bracket is not encountered
        else if (a[i] == ')') {
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        } else {
            while (!s.is_empty() && (priority(a[i]) <= priority(s.top()))) {
                postfix += s.top();
                s.pop();
            }
            s.push(a[i]);
            i++;
        }
    }

    while (!s.is_empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

template<class T>
bool chkBalanced(string a) {
    StackSLL<T> STACK;
    char c;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[' || a[i] == '<') {
            STACK.push(a[i]);
            continue;
        } else {
            if (a[i] == ')') {
                c = STACK.top();
                STACK.pop();
                if (c != '(')
                    return false;
            }
        }
        if (a[i] == '}') {
            c = STACK.top();
            STACK.pop();
            if (c != '{')
                return false;
        }
        if (a[i] == ']') {
            c = STACK.top();
            STACK.pop();
            if (c != '[')
                return false;
        }
        if (a[i] == '>') {
            c = STACK.top();
            STACK.pop();
            if (c != '<')
                return false;
        }
    }
    return (STACK.is_empty());

}


int main() {
    int key=1;
    cout << "Please enter the key from 1 to 5 " << endl;
    while (key == 1 ||key == 2 || key == 3 || key == 4 || key == 5)
    {

        cout << "1) Check for balanced brackets." << endl;
        cout << "2) Convert to binary" << endl;
        cout << "3) Convert infix to postfix expression and evaluate." << endl;
        cout << "4) Move Nth element to front in a queue of strings." << endl;
        cout << "5) Reverse elements of a queue of doubles.  " << endl;
        cin >> key;

        if (key == 1)
        {
            string Brackets;
            cout << "please enter the string";
            cin >> Brackets;
            if (chkBalanced<char>(Brackets))
            {
                cout << "Balanced" << endl;
            }
            else
            {
                cout << "Unbalanced" << endl;
            }
        }
        if (key == 2)
        {
            int DecimalNumber;
            cout << "Enter a number to convert :" << endl;
            cin >> DecimalNumber;
            cout << "Your binary number is  :" << convertToBinary(DecimalNumber)<<endl ;
        }
        if (key == 3)
        {
            string y;
            cout << "Enter the string to transfer " << endl;
            cin >> y;
            string x = convertInfixToPostfix<char>(y) ;
            cout<<x<<endl ;
            cout << evaluatePostfix<char>(x) << endl;

        }
        if (key == 4)
        {
            QueueSLL<string> Q;
            int size = 0;
            string x;
            cout << "Enter the size of queue" << endl;
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                cout << "Enter the number : ";
                cin >> x;
                Q.enqueue(x);

            }
            cout << " Enter position: ";
            int Position;
            cin >> Position;
            moveNthElem(Q, Position);
            cout << "Result is : ";
            for (int i = 0; i < size; i++)
            {
                if (i ==size-1)
                {
                    cout << Q.Front();
                    Q.dequeue();
                }
                else
                {
                    cout << Q.Front()<<"-";
                    Q.dequeue();
                }

            }
            cout<<""<<endl;
        }
        if (key == 5)
        {
            QueueSLL<string> Q;
            int size_2 = 0;
            int y = 0;
            cout << "Enter the size of queue: ";
            cin >> size_2;
            for (int i = 0; i < size_2; i++)
            {
                string n;
                cin >> n;
                Q.enqueue(n);
            }
            reverseQueue(Q);
            cout << "Result: ";
            for (int i = 0; i < size_2; i++)
            {
                cout << Q.Front() << " ";
                Q.dequeue();
            }
            cout << endl;

        }

    }

}