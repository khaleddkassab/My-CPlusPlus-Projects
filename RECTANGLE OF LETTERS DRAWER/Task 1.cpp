#include <iostream>

using namespace std;

void DrawFirst_Last(int o, char m)
{
    for (int i=0;o>i;i++)
    {
            if (i==o-1)
                cout<<m<<endl;
            else
                cout<<m;
    }
}
void space(int k)
{
    int x;
    for (x=1;k-1>x;x++)
        cout<<" ";
}


void DrawMiddle (int l,char m,int f)
{
    int c,length,i;

    for (c=0;l-2>c;c++)
    {
        cout<<m;
        space(f);
        cout<<m<<endl;
        m++;
    }

}


void DrawRectangle(int length,int width)
{
    char m = 'a';
    DrawFirst_Last(width,m);
    DrawMiddle(length,m+1,width);
    m = m + (length - 1);
    DrawFirst_Last(width,m);

}





int main()
{
    int length,width;


    cout<<"Please Enter The Rectangle's Length & Width : ";
    cin>>length>>width ;
    DrawRectangle(length,width);

    return 0;
}
