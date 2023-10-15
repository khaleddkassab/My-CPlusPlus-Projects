 #include <iostream>
#include <cstring>
#include <cmath>
#include <ctype.h>

using namespace std;
 string defaulto="a";

class MyPhoneBook
{
private:
 string* names;
 string* phones;
 int phoneBookSize;
 int* arr;
 int* arr2;
 public:


 MyPhoneBook(int sizee)//constructor
 {
     phoneBookSize=sizee;

     names = new string[sizee];
     phones= new string[sizee];
     for (int i=0;i<phoneBookSize;i++)
     {
         names [i] =defaulto;
         phones[i] =defaulto;

    }
 }

 MyPhoneBook(const MyPhoneBook &obj)//copy constructor
{
    phoneBookSize=obj.phoneBookSize;
    names =new string [phoneBookSize];
    phones=new string [phoneBookSize];
    for (int i=0;i<phoneBookSize;i++)
    {
        names [i] =obj.names[i];
        phones[i] =obj.phones[i];
    }
}
bool addEntry(string a,string b)
{

    for (int i=0;i<phoneBookSize;i++)
    {
        if (names[i]==defaulto && phones[i]==defaulto )
        {
            char * u;
            strtol(b.c_str(), &u, 10);
            if(b.length()==3 && !*u)
            {
                names[i] = a;
                phones[i] = b;
                return true;
            }

            else
                return false;

        }
        else if (names[i]!=defaulto)
            //return false;
            continue;
   }


}
bool displayEntryAtIndex(int y)
{
    cout<<names[y-1];
    cout<<phones[y-1]<<endl;
    if (y<=phoneBookSize)
        return true;
    else
        return false;

}
void displayEntryAtIndices(int*numbers)
{

     for (int i =0;i<=phoneBookSize;i++)
     {
         if (numbers[i]==1)
            {
                cout<<" Name "<<i+1<<" :"<<names [i]<<endl;
                cout<<"phone "<<i+1<<" :"<<phones[i]<<endl;
            }
     }

}
void displayAll()
{
    for (int i=0;i<phoneBookSize;i++)
    {
        cout<<"Name " <<i+1<<":"<<names [i]<<endl;
        cout<<"Phone "<<i+1<<":"<<phones[i]<<endl;

    }
}
int* findByName(string v)
{
    int c;
    arr = new int[phoneBookSize];
    for (c =0;c<phoneBookSize;c++)
    {
        if (names[c].find(v,0) != string::npos)
        {
            for (int i=0;i<phoneBookSize;i++)
            {
                arr[i]=1;
                cout<<arr[i]<<endl;

            }
            break;
        }
    }
        if (c==phoneBookSize)
        {
            for (int i=0;i<phoneBookSize;i++)
            {
                arr[i]=0;
                cout<<arr[i]<<endl;
            }

        }
        delete[] arr;
    }


int* findByPhone(string w)
{
    int d;
    arr2 = new int[phoneBookSize];
    for (d =0;d<phoneBookSize;d++)
    {
        if (phones[d].find(w,0) != string::npos)
        {
            for (int i=0;i<phoneBookSize;i++)
            {
                arr2[i]=1;
                cout<<arr2[i]<<endl;

            }
            break;
        }
    }
        if (d==phoneBookSize)
        {
            for (int i=0;i<phoneBookSize;i++)
            {
                arr2[i]=0;
                cout<<arr2[i]<<endl;
            }

        }
delete[] arr2;
    }

bool updateNameAt(string e, int x)
{
    if (x<=phoneBookSize)
    {
        names[x-1]=e;
        return true;
    }
    else
        return false;


}
bool updatePhoneAt(string s, int y)
{
    if (y<=phoneBookSize)
    {
        phones[y-1]=s;
        return true;
    }
    else
        return false;


}
~MyPhoneBook()
{
    delete[] names;
    delete[] phones;
}







};

int main()
{
    int sizeee,index,index2,index3,*arrayy,j;
    string name , phone ,searchedName,searchedPhone,updatedName,updatedPhone;
    cout << "Hello world!" << endl;
    cout<<"Enter the size of your phone book : ";
    cin>>sizeee;

    MyPhoneBook MPB(sizeee);
    for (int i=0;i<sizeee;i++)
    {
        cout<<"Enter name "<<i+1<<" :";
        cin>>name;
        cout<<"Enter phone "<<i+1<<" :";
        cin>>phone;
        if(MPB.addEntry(name,phone))
            cout<<"Inserted"<<endl;
        else
        {
            cout<<"Error Not Inserted"<<endl ;
            i--;
            continue;
        }
    }

    for(int k=0;j<11;k++)
    {
        cout<<"1- Display all phone book "<<endl;
        cout<<"2- Search for entry/entries by name"<<endl;
        cout<<"3- Search for entry/entries by phone"<<endl;
        cout<<"4- Find an entry by index "<<endl;
        cout<<"5- Update name by index"<<endl;
        cout<<"6- Update phone by index"<<endl;
        cout<<"7- Copy phone book to another and display entries of the new book "<<endl;
        cout<<"8- Enter the  element of the 0s and 1s array"<<endl;
        cout<<"9- Exit"<<endl;
        cout<<"Choice : ";
        cin>>j;

    if (j==1)        //1st
    {
       MPB.displayAll();
    }
    if (j==2)       //2nd
    {
        cout<<"Search for entry/entries by name"<<endl;
        cin>>searchedName;
        MPB.findByName(searchedName);
    }
    if (j==3)       //3rd
    {
        cout<<"3- Search for entry/entries by phone"<<endl;
        cin>>searchedPhone;
        MPB.findByPhone(searchedPhone);
    }
    if (j==4)       //4th
    {
        cout<<"4- Please enter the index you want to display : "<<endl;
        cin>>index;
        if(MPB.displayEntryAtIndex(index))
            cout<<" "<<endl;
        else
        {
            while((MPB.displayEntryAtIndex(index))==false)
            {
                cout<<"Please enter the index you want to display : "<<endl;
                cin>>index;
                MPB.displayEntryAtIndex(index);
            }
        }

    }
    if (j==5)       //5th
    {
        cout<<"5- Update name by index"<<endl;
        cout<<"Enter the index :";
        cin>>index2;
        cout<<"Enter the updated name : ";
        cin>>updatedName;

        MPB.updateNameAt(updatedName, index2);
        if (MPB.updateNameAt(updatedName, index2))
            cout<<" "<<endl;
        else
        {
            while(MPB.updateNameAt(updatedName, index2)==false)
            {
                cout<<"Enter valid index";
                cin>>index2;
                cout<<"Enter the updated name : ";
                cin>>updatedName;
            }
        }
    }
    if (j==6)       //6th
    {   cout<<"6- Update phone by index"<<endl;
        cout<<"Enter the index :";
        cin>>index3;
        cout<<"Enter the updated phone : ";
        cin>>updatedPhone;
        MPB.updatePhoneAt(updatedPhone, index3);
        if (MPB.updatePhoneAt(updatedPhone, index3))
            cout<<" "<<endl;
        else
        {
            while(MPB.updatePhoneAt(updatedPhone, index3)==false)
            {
                cout<<"Enter valid index";
                cin>>index3;
                cout<<"Enter the updated name : ";
                cin>>updatedPhone;
            }
        }
    }
    if (j==7)       //7th
    {
       MyPhoneBook gg(MPB);
       gg.displayAll();
    }
    if (j==9)       //8th
    {
        exit(EXIT_FAILURE);
    }
    if (j==8)
    {
        arrayy = new int[sizeee];

        for (int i=0;i<sizeee;i++)
        {
            cout<<"Enter the "<<i<<" element of the 0s and 1s array"<<endl;
            cin>>arrayy[i];

        }
        MPB.displayEntryAtIndices(arrayy);
        delete[]arrayy;
    }


    }

    return 0;
}
