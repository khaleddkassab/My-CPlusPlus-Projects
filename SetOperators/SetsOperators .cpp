#include <iostream>

using namespace std;
class IntegerSet
{
private:
    int a[100];
public:
    IntegerSet()//default constructor
    {
        for (int i=0;i<100;i++){a[i]=0;}
    }

    IntegerSet(int param[],int sizee)//parametrized constructor
    {
        for (int i=0;i<100;i++){a[i]=0;}//assign all to zero

        for (int i=0;i<sizee;i++)
            {
                int x = param[i];
                a[x]=1;
            }
    }
    int getAny(int index)
    {
        return a[index];
    }

    void insertElement(int k)
    {
        a[k]=1;
    }
    void deleteElement(int m)
    {
        a[m]=0;
    }
    void printSet ()
    {
        int sum =0;
        cout<<"{";
        for (int i=0;i<100;i++)
        {
            if (getAny(i)==1)
            {cout<<i<<" ";}

            else if (getAny(i)==0)
            {sum++;}
        }

        if (sum==100)
            cout<<"---";

        cout<<"}"<<endl;
    }

    void unionOfSets(IntegerSet b )
    {
        IntegerSet c;
        for (int i=0;i<100;i++)
        {
           if (getAny(i)==1 || b.getAny(i)==1 )
            c.insertElement(i);
        }
        cout<<"unionOfSets ";
        c.printSet();

    }
    void intersectionOfSets(IntegerSet b )
    {
        IntegerSet c;
        for (int i=0;i<100;i++)
        {
           if (getAny(i)==1 && b.getAny(i)==1 )
            c.insertElement(i);
        }
        cout<<"intersectionOfSets  ";
        c.printSet();

    }
    bool isEqualTo(IntegerSet b)
    {
        for (int i=0;i<100;i++)
        {
            if (getAny(i)!=b.getAny(i))
                return false;
        }
        return true;
    }
    IntegerSet operator-(IntegerSet &obj)
    {
        IntegerSet c;
        for(int i=0;i<100;i++)
        {
            if (getAny(i)==1 && obj.getAny(i)==0)
                c.insertElement(i);
        }
        cout<<"differenceOfSets ";
        c.printSet();

    }
    IntegerSet operator!()
    {
        IntegerSet c;
        for(int i=0;i<100;i++)
        {
            if (getAny(i)==0)
                c.insertElement(i);
        }
        cout<<"complementOfSets ";
        c.printSet();
    }

};

int main()
{
    cout << "Hello world!" << endl;
    bool v;
    int o[7]={2,10,0,15,6,12,14}; //initialized array pass it

    IntegerSet a,b,c(o,7),d,e;//objects

    //insertion in set a
    a.insertElement(55);
    a.insertElement(5);
    a.insertElement(65);
    a.insertElement(10);
    a.insertElement(25);
    a.insertElement(36);
    a.insertElement(84);
    a.insertElement(2);
    a.insertElement(14);
    a.insertElement(96);

    //insertion in set b
    b.insertElement(65);
    b.insertElement(55);
    b.insertElement(5);
    b.insertElement(69);
    b.insertElement(44);
    b.insertElement(2);
    b.insertElement(84);
    b.insertElement(12);
    b.insertElement(88);
    b.insertElement(14);

    //union set and intersection set
    a.unionOfSets(b);
    b.unionOfSets(a);
    a.intersectionOfSets(b);
    b.intersectionOfSets(a);

    e.insertElement(20);
    e.insertElement(10);
    d.insertElement(10);
    d.insertElement(20);


    v=e.isEqualTo(d);
    cout<<v<<endl ;

    v=d.isEqualTo(e);
    cout<<v<<endl ;


    v=a.isEqualTo(b);
    cout<<v<<endl ;
    v=b.isEqualTo(a);
    cout<<v<<endl ;

    b-a;
    a-b;
    !a;
    !b;

    c.printSet();
    return 0;
}
