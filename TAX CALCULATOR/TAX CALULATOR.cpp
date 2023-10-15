#include <iostream>

using namespace std;

int main()
{
    int filingStatus;
    float income,taxes;
    cout<<"Please select your Filing Status : (0 or 1 or 2 or 3"<<endl;
    cin>>filingStatus;
    cout<<"Please insert your income : "<<endl;
    cin>>income;
    if (filingStatus==(0 ))
    {
        if (income<=8350){

            taxes=income*0.1;
            cout << "your taxes is : "<<taxes <<"$"<<endl;

        }
        else if (income>8350 && income <=33950)
                   {

                taxes=(8350*0.1)+((income-8350)*0.15);
               cout<<"Your Taxes is :  "<<taxes<< "$"<<endl;

                   }
        else if (income>33951){
            taxes=(8350*0.1)+(33950*0.15)+((income-33950)*0.25);
            cout<<"Your Taxes is :      " <<taxes<< "$" <<endl;
        }
    }


    if (filingStatus==1)
    {
        if (income<=16700)
        {
            taxes=income*0.1;
            cout<<"Your Taxes is : "<<taxes<< "$"<<endl;

        }
        else if (income>16700 && income <=67900)
                   {

                taxes=(16700*0.1)+(income-16700)*0.15;
                cout<<"Your Taxes is : "<<taxes<<  "$"<<endl;

                   }
        else if (income>67901)
        {
             taxes=(16700*0.1)+(67900*0.15)+(income-67900)*0.25;
            cout<<"Your Taxes is : "<<taxes<< "$"<<endl;
        }



    }
    if (filingStatus==3)
        {
        if (income<=11950){

            taxes=income*0.1;
            cout << "your taxes is : "<<taxes <<"$"<<endl;

        }
        else if (income>11950 && income <=45500)
                   {

                taxes=(11950*0.1)+((income-11950)*0.15);
               cout<<"Your Taxes is :  "<<taxes<< "$"<<endl;

                   }
        else if (income>45501){
            taxes=(11950*0.1)+(45500*0.15)+((income-45500)*0.25);
            cout<<"Your Taxes is :      " <<taxes<< "$" <<endl;
        }
    }
        if (filingStatus==(2 ))
    {
        if (income<=8350){

            taxes=income*0.1;
            cout << "your taxes is : "<<taxes <<"$"<<endl;

        }
        else if (income>8350 && income <=33950)
                   {

                taxes=(8350*0.1)+((income-8350)*0.15);
               cout<<"Your Taxes is :  "<<taxes<< "$"<<endl;

                   }
        else if (income>33951){
            taxes=(8350*0.1)+(33950*0.15)+((income-33950)*0.25);
            cout<<"Your Taxes is :      " <<taxes<< "$" <<endl;
        }
    }
    return 0;
}
