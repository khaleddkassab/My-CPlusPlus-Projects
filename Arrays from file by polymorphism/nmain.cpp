
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class FloatArray
{
protected:
    float *Arr1;
    int Size;

public:

    FloatArray(int Size)
    {
        this->Size=Size;
        Arr1=new float [Size];
        for (int i=0;i<Size;i++)
        {
            Arr1[i]=-10000;
        }
    }

    int getSize()
    {return Size;}

    void setSize(int newSize)
    {Size = newSize;}

    virtual void Add (float x)
    {
        for(int i=0;i<Size;i++)
        {
           if (Arr1[i]==-10000)
            {
                Arr1[i]=x;
                return;
            }
        }

    }
    friend ofstream& operator<<(ofstream& outfile ,FloatArray *f)
    {
        int t=0;
        for (int i=0;i<f->getSize();i++)//to count array elements
        {
            if (f->Arr1[i]!=-10000)
            {t++;}
        }
        for (int i=0;i<f->getSize();i++)
        {
            if (i==0)//to print 1st line
            {outfile<<t<<"|\t";}

            if (f->Arr1[i]!=-10000)
            {outfile<<f->Arr1[i]<<"\t";}//to print array

            if (i==f->getSize()-1)//to make new line after end of array outfile
            {outfile<<""<<endl;}
        }

    }

    friend ifstream& operator>>(ifstream &infile,FloatArray *f)
    {
        for (int i=0;i<f->getSize();i++)
        {
            float readFile ;
            infile>>readFile;//read
            f->Add(readFile) ;//then add function
        }
    }

    virtual~FloatArray()
    {delete []Arr1;}

};
class SortedArray:public FloatArray
{
public:
    SortedArray(int Size2):FloatArray(Size2)
    {}
    virtual void Add (float x)
    {
        for (int i=0;i<Size;i++)
        {
            if(Arr1[i] == -10000)//add i element then compare with it the " float x"
            {
                Arr1[i] = x ;
                return ;
            }
            if(x < Arr1[i])//if smaller double inserted
            {
                for(int j=Size-2;j>=i;j--)//to shift all elements
                {
                    Arr1[j+1] = Arr1[j];
                }
                Arr1[i] = x;
                return;
            }

        }
    }
    virtual ~SortedArray()
    {delete []Arr1;}
};
class FrontArray:public FloatArray
{
  public:
      FrontArray(int Size3):FloatArray(Size3)
      {}
      virtual void Add (float x )
      {
          for (int i=0;i<Size;i++)
          {
                if(Arr1[0]==-10000)//to add in the first index after shifting all elements to right
                {
                    Arr1[0]=x;
                    return;
                }

                if (Arr1[0]!=-10000)//if first index not empty shift all elements
                {
                    for (int c=Size-2;c>=i;c--)
                    {
                        if (Arr1[c]!=-10000)

                        {Arr1[c+1]=Arr1[c];}//to shift all elements
                    }
                    Arr1[i]=x;
                    return;
                }
            }
      }
      virtual~FrontArray()
      {delete []Arr1;}

};
class PositiveArray:public SortedArray
{
  public:

      PositiveArray(int Size4):SortedArray(Size4)
      {}
      virtual void Add (float x)
      {
              if (x>=0)
              {SortedArray::Add(x);}//if positive add of positive class then add of sort class to sort positive doubles

      }
      virtual~PositiveArray()
      {delete []Arr1;}

};

class NegativeArray:public SortedArray
{
  public:
      NegativeArray(int Size5):SortedArray(Size5)
      {}

      virtual void Add (float x)
      {
            if (x<0)//if negative add of negative class then add of sort class to sort negative doubles
                {SortedArray::Add(x);}
      }

      virtual~NegativeArray()
      {delete []Arr1;}

};

int main()
{
    cout << "Hello world!" << endl;
    //initiating all variables
    int Size1; //size of array
    ifstream Ain;
    ofstream Aout;
    FloatArray *floatarr;
    string InputFile,OutputFile,TypeOfArr;


    cout<<"Enter the Input File Name : "<<endl;
    cin>>InputFile;
    cout<<"Enter the Output File Name : "<<endl;
    cin>>OutputFile;

    Ain.open(InputFile);

    Aout.open(OutputFile);

    if (Ain.fail() || Aout.fail() )
  {cout<<"failed to open"<<endl;}


    while(!Ain.eof() )//read while file is not ended yet
    {

        Ain>>TypeOfArr;
        Ain>>Size1;
        if(TypeOfArr=="Array")
        {
           floatarr= new FloatArray(Size1);
        }

        if (TypeOfArr=="Sorted")
        {
            floatarr= new SortedArray(Size1);
        }

        if (TypeOfArr=="Front")
        {
            floatarr= new FrontArray(Size1);
        }
        if (TypeOfArr=="Positive")
        {
            floatarr= new PositiveArray(Size1);
        }
        if (TypeOfArr=="Negative")
        {
            floatarr= new NegativeArray(Size1);
        }
        Ain>>floatarr;//read
        Aout<<floatarr;//write
    }

    Ain.close();
    Aout.close();


    return 0;
}

