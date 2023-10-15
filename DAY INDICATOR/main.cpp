#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    float q , m , j  , s ;
    int h , k ;
    cout << "Please enter the year :" << endl;
     cin >> k ;
     cout << "please enter the number of the month : " << endl;
     cin >> m ;
     if(m == 1 || m==2){
        m = m+12 ;
     }
     cout << " please enter the day of the month : " << endl;
     cin >> q ;


     j = (k/100) + 1 ;
     k = k%100 ;

     s=26*(m+1);
     float x,y,z,f ;
     x = s/10.0 ;
     y = k/4.0 ;
     z = j/4.0 ;
     f = 5.0*j ;
     h = q+x+k+y+z+f ;
     h = h%7 ;



if (h==0)
    cout << " The day is saturday ";
else if (h==1)
    cout << " The day is sunday ";
else if (h==2)
    cout << " The day is monday ";
else if (h==3)
    cout << " The day is tuesday ";
else if (h==4)
    cout << " The day is wednesday ";
else if (h==5)
    cout << " The day is thursday " ;
else
    cout << " The day is friday " ;




    return 0;
}
