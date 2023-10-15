#include <iostream>
#include <math.h>
#include <fstream>
#include "Student.h"
using namespace std;
int main()
{
    cout << "Hello world!" << endl;

    int Size;
    int c=1,m=0;

    string firstName , lastName,id;
    double gpa;

    ifstream Ain;
    ofstream Aout1,Aout2,Aout3;


    Ain.open  ("Students.txt");

    Aout1.open("BubbleSort.txt");
    Aout2.open("ShellSort .txt");
    Aout3.open("QuickSort .txt");

    if (Ain.fail())
        {cout<<"Failed to open in"<<endl;}
    if( Aout1.fail() )
        {cout<<"Failed to open out 1"<<endl;}
    if( Aout2.fail() )
        {cout<<"Failed to open out 2"<<endl;}
    if( Aout3.fail() )
        {cout<<"Failed to open out 3"<<endl;}

    Ain>>Size;

    Student  * a1 = new Student [Size];
    Student  * a2 = new Student [Size];
    Student  * a3 = new Student [Size];


    //read file student by student  each student is saved in the 3 arrays then sort then write
    for ( int i=0 ; i<Size ; i++)
    {
        Ain>>firstName>>lastName ;
        Ain>>id ;
        Ain>>gpa ;


        a1[i].SetName(firstName+" "+lastName);
        a1[i].SetID(id);
        a1[i].SetGPA(gpa);

        a2[i].SetName(firstName+" "+lastName);
        a2[i].SetID(id);
        a2[i].SetGPA(gpa);

        a3[i].SetName(firstName+" "+lastName);
        a3[i].SetID(id);
        a3[i].SetGPA(gpa);


    }

    BubbleSort(a1,Size);//sort
    ShellSort (a2,Size);//sort
    QuickSort (a3,0,Size-1);

//write in text file
    for (int i=0 ; i<Size ; i++)
    {
        if (i==0)//to print Number Of Comparisons only ones
        {
            Aout1<<"Number Of Comparisons : "<<a1[0].NumberOfComparisons<<endl;
            Aout2<<"Number Of Comparisons : "<<a2[0].NumberOfComparisons<<endl;
            Aout3<<"Number Of Comparisons : "<<a3[0].NumberOfComparisons<<endl;
        }
        //
        Aout1<<"Name: "<<a1[i].GetName()<<endl;
        Aout1<<"ID: "  <<a1[i].GetID  ()<<endl;
        Aout1<<"GPA: " <<a1[i].GetGPA ()<<endl;

        Aout2<<"Name: "<<a2[i].GetName()<<endl;
        Aout2<<"ID: "  <<a2[i].GetID  ()<<endl;
        Aout2<<"GPA: " <<a2[i].GetGPA ()<<endl;

        Aout3<<"Name: "<<a3[i].GetName()<<endl;
        Aout3<<"ID: "  <<a3[i].GetID  ()<<endl;
        Aout3<<"GPA: " <<a3[i].GetGPA ()<<endl;
    }


    Ain.close();
    Aout1.close();
    Aout2.close();
    Aout3.close();


    while( c!= 0)
    {
        cout<<"1- Show number of comparison and Sorted Array of BubbleSort "<<endl;
        cout<<"2- Show number of comparison and Sorted Array of ShellSort "<<endl;
        cout<<"3- Show number of comparison and Sorted Array of QuickSort "<<endl;
        cout<<"4- Search for a Student by Name "<<endl;
        cout<<"5- Exit"<<endl;
        cin>>m;
        if (m==1)
        {
            PrintArray(a1,Size);
        }
        if (m==2)
        {
            PrintArray(a2,Size);
        }
        if (m==3)
        {
            PrintArray(a3,Size);
        }
        if (m==4)
        {
            cout<<"Enter Name : ";
            cin>>firstName>>lastName;
            int s=binarySearch(a1, 0, Size-1, firstName+" "+lastName);

            if (s==-1)
            cout<<"Name is not found"<<endl;

            else
            {
                cout<<"Name: "<<a1[s].GetName()<<endl;
                cout<<"ID: "  <<a1[s].GetID  ()<<endl;
                cout<<"GPA: " <<a1[s].GetGPA ()<<endl;
            }
        }
        if (m==5)
        {
            c=0;
        }
    }
    return 0;
}

