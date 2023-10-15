#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
class Student
{
private:
    string Name;
    string Id;
    double GPA;
public:
    Student(string name,string id,double gpa)
    {
        Name=name;
        Id  =id;
        GPA =gpa;
    }
    Student()
    {
        Name="";
        Id  ="";
        GPA =0;
    }
    int NumberOfComparisons=0;
    string GetName ()
    {
        return Name;
    }
    string GetID ()
    {
        return Id;
    }
    double GetGPA ()
    {
        return GPA;
    }
    void SetName (string n)
    {
        Name=n;
    }
    void SetID (string id)
    {
        Id=id;
    }
    void SetGPA (double gpa)
    {
        GPA=gpa;
    }

    void Print()
    {
        cout<<"Name: "<<GetName()<<endl;
        cout<<"ID  : "<<GetID  ()<<endl;
        cout<<"GPA : "<<GetGPA ()<<endl;
    }
    void PrintNumberOfComparisons (int x)
    {
    cout<<"Number Of Comparisons is : "<<x<<endl;
    }


bool  operator <(Student obj)
{
   /* if(this->Name.compare(obj.GetName())==0)
       //this->GetName()==obj.GetName();
       return 3;*/
     if (this->Name.compare(obj.GetName())>0)
        //(this->Name>(obj.GetName())<0)
        return 1;
    else if (this->Name.compare(obj.GetName())<0)
        //(this->Name<(obj.GetName()))
        return 0;
}
Student operator == (Student obj)
{
    this->SetName(obj.GetName());
    this->SetID  (obj.GetID  ());
    this->SetGPA (obj.GetGPA ());
}

};
template <class T>
T * BubbleSort(T a1[],int size)
{
    int NumberOfComparisons=0;

    for(int i=0 ; i<size-1 ; i++)
    {
        for(int j=1 ; j<size-i ; j++)
        {

            if(a1[j]<a1[j-1]==0)
                {
                    swap(a1[j],a1[j-1]);
                    NumberOfComparisons++;
                }

        }

    }
    a1[0].NumberOfComparisons+=NumberOfComparisons;
}


template <class T>
T  * ShellSort(T a2[],int size)
 {
     int NumberOfComparisons=0;
     for (int Gap = pow(2, (int)( log(size)/log(2) ) )-1 ; Gap > 0; Gap /= 2)
    {
        for (int i = Gap,j; i < size; i++)
        {
            T tmp = a2[i];

            for (j = i; j >= Gap && tmp < a2[j - Gap]==0; j -= Gap,NumberOfComparisons++)
            {
                    a2[j] = a2[j - Gap];
            }


            a2[j] = tmp;
        }

    }
    a2[0].NumberOfComparisons+=NumberOfComparisons;
 }

    template <class T>
    int  Partition(T a3[], int left, int right)
    {
        int i =left,NumberOfComparisons=0;
        for (int j=left+1; j<=right; j++)
        {
            if(a3[j] < a3[left] ==0)
            {
                i++;
                swap(a3[i],a3[j]);
            }
            NumberOfComparisons++;
        }

        swap(a3[left],a3[i]);
        a3[0].NumberOfComparisons+=NumberOfComparisons;

        return i;
    }
template <class T>
T * QuickSort(T a3[],int left, int right)
{
    a3[0].NumberOfComparisons++;
    if (left>=right)
        {
            return a3;
        }

    else
    {
        int x =Partition(a3,left,right);
        QuickSort(a3,left,x-1);
        QuickSort(a3,x+1,right);
    }

}

void PrintArray (Student a[],int size)
{
    for(int i=0;i<size;i++)
    {
        if (i==0)
            cout<<"NumberOfComparisons : "<<a[0].NumberOfComparisons<<endl;

        cout<<"Name: "<<a[i].GetName()<<endl;
        cout<<"ID: "  <<a[i].GetID  ()<<endl;
        cout<<"GPA: " <<a[i].GetGPA ()<<endl;
    }
}

int binarySearch(Student arr[], int left, int Size, string Parameter)
{
    while (left <= Size)
    {
        int m = left + (Size - left) / 2;

        // Check if x is found at middle
        if (arr[m].GetName() == Parameter)
            return m;

        // If x greater ignore left half
        if (arr[m].GetName() < Parameter)
            left = m + 1;

        // If x is smaller, ignore right half
        else
            Size = m - 1;
    }

    // if we reach here, then element was not found
    return -1;
}


#endif // STUDENT_H_INCLUDED
