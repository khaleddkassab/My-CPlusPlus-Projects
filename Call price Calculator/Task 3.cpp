#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;



int main()
{

float shours,sminutes,ehours,eminutes,starttimeinmins,endtimeinmins,duration,cost,totalcost;

cout << "Start Hour"<<endl;
cout<< ":Start Min "<<endl;
cin>>shours;
cout<<":";
cin>>sminutes;
cout << "End Hour "<<endl;
cout<< ":End Min "<<endl;
cin>>ehours;
cout<<":";
cin>>eminutes;
starttimeinmins=(shours*60)+sminutes;
endtimeinmins=(ehours*60)+eminutes;
duration=endtimeinmins-starttimeinmins;
cost=duration*0.5;
if ((shours>=23||shours<6) && ehours<=6)
    cost=cost*0.75;

if (duration >60.0)
    cost=cost*1.15;

totalcost=cost*1.07;
//totalcost=ceil(totalcost * 100.0) / 100.0;


cout << "Your total cost is : " << setprecision(4)<<totalcost<<" L.E."<<endl;



    return 0;
}
