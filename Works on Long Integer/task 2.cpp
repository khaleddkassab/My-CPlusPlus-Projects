#include<iomanip>
#include <iostream>
using namespace std;
long long  numofdigit(long long x=0 )
{
    int counter=0;
    while(x>0)
    {
        x=x/10;
        counter++;
    }
    return counter;
}
long long sumofdigit(long long x=0)
{
    int sum=0;
    while(x>0)
    {
        sum=sum+x%10;
        x=x/10;
    }
    return sum;
}

int numberoftimes(long long x=0,int y=0)
{
    int counter=0;
    while(x>0)
    {
        if(x%10==y)
        {
            counter++;
        }
        x=x/10;
    }
    return counter;
}
long long reversenum(int x=0)
{
    long long  rev=0;
    while(x!=0)
    {
        rev=rev*10+(x%10);
        x=x/10;
    }
    return rev;
}
void avgeven(long long  x)
{   double sum=0,avg=0;
    int count=0,i= 1;
    x = reversenum(x);
    while(x !=0)
    {
        if(i%2==0)
        {
            sum +=x%10;
            count ++;
        }
        x /=10;
        i++;
    }
    avg =sum/count;
    cout<<avg<<endl;
}
void avgodd(long long x)
{   double sum=0,avg=0;
    int count=0,i= 1;
    x = reversenum(x);
    while(x !=0)
    {
        if(i%2==1)
        {
            sum +=x%10;
            count ++;
        }
        x /=10;
        i++;
    }
    avg =sum/count;
    cout<<avg<<endl;
}
double digitinthemiddle(long long  x=0)
{

    double middleeven=0;
    double middleodd=0;
    int i=0;
    int n =0;
    n=(numofdigit(x))/2;
    if((n-i)%2==1)
    {
        while((n-i)>0)
        {
            x=x/10;
            i++;
        }
        middleodd=x%10;
        return middleodd;
    }
    else
    {
        while(n-1-i>0)
        {
            x=x/10;
            i++;
        }
        middleeven=middleeven+x%10;
        x=x/10;
        middleeven=middleeven+x%10;
        middleeven=middleeven/2;
        return middleeven;
    }
}



int main()
{
    int e=0;
    while(e!=1)
    {
        long long  x=0 ;
        std::cout << "please enter the number you want" << std::endl;
        std::cin >> x ;
        std::cout << " this the number of digits you want"<<  numofdigit(x) << std::endl;
        std::cout <<"this is the sum of all digits"<< sumofdigit(x) << std::endl;
        std::cout << "the avearge of even numbers is "<< std::endl;
        avgeven(x);
        std::cout << "the avearge of odd numbers is "<< std::endl;
        avgodd(x);
        std::cout << "please enter the digit you want";
        int y=0;
        std::cin >> y;
        std::cout <<"the number of tims this number is repeated is "<< numberoftimes(x,y) << std::endl;
        std::cout<<"the reversed number is " << reversenum(x) << std::endl;
        std::cout <<"the median is "<< digitinthemiddle(x) << std::endl;
        std::cout << "please enter digt e =1 equal if you want program to stop" << std::endl;
        std::cin >> e;


    }

}
