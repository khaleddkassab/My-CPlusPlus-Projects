#include <iostream>


using namespace std;
void dashing (int rows ,int columns , char** reserve){
    int m,u;
for (m=0;m<rows;m++)
{
    for (u=0;u<columns;u++)
        reserve[m][u]='-';
}}
void displayStats(int rows, int columns, char** reserve){
    int r,v;
    double statisticsCinema,statisticsRow,totalr,totalPerRow;
    for (r=0;r<rows;r++)
    {
        totalPerRow = 0 ;
        for (v=0;v<columns;v++)
        {
            if (reserve[r][v]=='$'){
                totalr=totalr+1;
                totalPerRow=totalPerRow+1 ;
            }
        }
        cout<<"Row "<<r<<": "<<(totalPerRow/columns)*100;
    }
    statisticsCinema=((totalr)/(rows*columns))*100;

    cout<<"Total : "<<statisticsCinema<<"%";
}
void displayCinema(int rows, int columns, char** reserve){
int z;
    char M ='A';

    for (z=0;z<rows;z++)
    {
        if (z==rows)
            cout<<M<<endl;

        else if (z==0)
        {
            cout<<"      "<<M;
            M++;
        }
        else
        {
            cout<<M;
            M++;
        }
    }

    cout<<" "<<endl;
    int o,s;
    for (o=0;o<rows;o++)
    {
        if (o>=9) //one space for 2 digits
            cout<<"row"<<o+1<<" ";

        else//two space for 1 digit
            cout<<"row"<<o+1<<"  ";

        for (s=0;s<columns;s++)
            cout<<reserve[o][s];

        cout<<endl;
    }
}
void reserveSeats(int rows , int columns , char** reserve){
    int seats,f,d,srow,scol,i ;
cout<<"Please enter the number of seats you want to reserve : "<<endl;
    cin>>seats;


    for (i=0;i<seats;i++)
    {
        cout<<"Please enter the seat's number row-column : ";
        cin>>f>>d;
        srow=f-1;
        scol=d-1;
        if (reserve[srow][scol]!='$')
            reserve[srow][scol]='$';
        else if (f>rows || d>columns )

        {
            cout<<" Sorry No seat in this hall with this number !!"<<endl;
            i--;
        }

        else{
            cout <<" Sorry this seat is reserved !!"<<endl;
            i--;
            }
    }
}
void showPosibility(int rows, int columns, char** reserve){
int n,c,b,q,seats,x;
    b=0;
    cout<<"Please enter the number of seats you want to reserve : "<<endl;
    cin>>seats;
    for (n=0;n<rows;n++)
    {
        int findSeats = 0 ;
        for(c=0;c<columns;c++)
        {
            if(reserve[n][c] == '-' && findSeats<seats){
                findSeats = findSeats + 1 ;
            }
            else if(findSeats == seats){
                cout<<"Row "<<n+1<<" ,from Column "<<c+1-seats<<" to column "<<c<<endl ;

                cout<<"Please enter 1 if you want to reserve the recommendations : ";
                cin>>b;
                if (b==1)
                {
                    q=seats;
                    x=c-1;
                    while (q>=0)
                    {
                        reserve[n][x]='$';
                        x--;
                        q--;

                    }
                    cout<<" Reservation Done .";
                    return;
                }

            }else{
                findSeats = 0;
            }
        }
    }
}
void restCinema(int rows ,int columns, char**reserve){
    int m,u;
for (m=0;m<rows;m++)
    {
        for (u=0;u<columns;u++)
        reserve[m][u]='-';
    }


}
void cancelation(int rows ,int columns, char**reserve){
    int f,d,seats,i,srow,scol;
cout<<"Please enter the number of seats you want to cancel its reservation : "<<endl;
    cin>>seats;



    reserve [0][0]='$';
    for (i=0;i<seats;i++)
    {
        cout<<"Please enter the seat's number row-column : ";
        cin>>f>>d;
        srow=f-1;
        scol=d-1;
        if (reserve[srow][scol]=='$')
            reserve[srow][scol]='-';
        else if (f>rows or d>columns )

        {
            cout<<" Sorry No seat in this hall with this number !!"<<endl;
            i--;
        }

        else{
            cout <<" Sorry this seat is not reserved !!"<<endl;
            i--;
            }
    }
}

int main()
{
int rows,columns;
char a;

cout<<"Please enter number of Rows and Columns : ";
cin>>rows>>columns;

char ** reserve = new char*[rows] ;

for(int i = 0 ; i<rows;i++)
    reserve[i] = new char[columns] ;

dashing(rows,columns,reserve);

while(true){
    cout<< "1)Please enter A if you want to Reserve seats "<<endl;
    cout<< "2)Please enter B if you want to Get seats recommendation  "<<endl;
    cout<< "3)Please enter C if you want to Cancel a number of seat reservations"<<endl;
    cout<< "4)Please enter D if you want to Clear all reservations to reset all the current seating reservations "<<endl;
    cout<< "5)Please enter E if you want to Display statistics about the current reservations "<<endl;
    cout<< "6)Please enter F if you want to Exit "<<endl;
    cin>>a;

if (a=='A'||a=='a')
{
    reserveSeats(rows,columns,reserve) ;
    displayCinema(rows,columns,reserve) ;
    cout<<" "<<endl;
}

if (a=='B' || a=='b')
{
    showPosibility(rows, columns,reserve) ;
        cout<<" "<<endl;
}

if (a=='C' || a=='c')
{
   cancelation(rows,columns,reserve);
   displayCinema(rows,columns,reserve) ;
}

if (a=='D' || a=='d')
{
   restCinema(rows,columns,reserve);
   displayCinema(rows,columns,reserve) ;
       cout<<" "<<endl;
}

if (a=='E' || a=='e')
{
    displayStats(rows,columns,reserve) ;
        cout<<" "<<endl;
}

if (a=='F' || a=='f')
{
    for(int i=0;i<rows;i++)
    {
        delete[] reserve[i];
        reserve[i] = 0;
    }
    break ;
}

}
    return 0;
}

