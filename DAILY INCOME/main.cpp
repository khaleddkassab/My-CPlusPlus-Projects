#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
double dayIndicator , shift , group , hours , income  ;
cout << "Which shift 0 or 1 ? " << endl;
cin >> shift ;
if (shift == 1)
    {

    cout <<"How many hours did you work ? " << endl;

    cin >> hours;
    income = hours *13 ;
    cout << "Your income is :" <<income << "$/day";
    }

else if ( shift == 0)
    {
    cout << " Day indicator 0 or 1 " << endl;
    cin >> dayIndicator;
        cout <<"How many hours did you work ? " << endl;
    cin >> hours;

    if (dayIndicator == 1)
        {
        cout<<"which group are you 0 or 1" << endl;
        cin >>group;
        if (group == 1)
           {
            income =hours*15;
            cout << "Your income is :" <<income << "$/holiday";
           }
        else
           {
           income =hours*14;
           cout << "Your income is :" <<income << "$/holiday";
           }
        }

     else
{
    cout<<"which group are you 0 or 1" <<endl;
    cin>>group;

    cout <<"How many hours did you work ? " << endl;
    cin>>hours;
}
    if (group==0)
    {
        if (hours>8)
        {
            income=((hours-8)*12)+(8*8);
            cout << "Your income is :" <<income << "$/day";
        }
        else
        {
            income = hours*8;
            cout << "Your income is :" <<income << "$/day";
        }
    }
    else
    {
      if (hours>8)
        {
            income=((hours-8)*12)+(8*8);
            cout << "Your income is :" <<income << "$/day";
        }
        else
        {
            income = hours*10;
            cout << "Your income is :" <<income << "$/day";
        }


    }
    }
else
    cout<< " error zero or 1 only ";
    return 0;
}
