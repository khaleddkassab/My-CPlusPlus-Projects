
#include <iostream>

using namespace std;

class Item
{
private:
    int ID;
    int Quantity;
    double Price;
    string Name;
    static int id;
public:

    Item () //default constructor to count every new object and make it the the id of the objectt
    {ID = id++;}

    Item (int quantityyy,double price,string name)
    {
        Quantity=quantityyy;
        Price=price;
        Name=name;
        ID = id++;
    }

     Item (const Item &object)//copy constructor
    {
        ID=object.ID;
        Name=object.Name;
        Price=object.Price;
        Quantity=object.Quantity;
    }


    void SetQuantity (int q)//setter
       {Quantity=q;}

    void SetPrice (double p)//setter
        {Price=p;}

    void SetName (string n)//setter
        {Name=n;}

    int GetQuantity ()//Getter
        {return Quantity;}

    double GetPrice ()//Getter
        {return Price;}

    string GetName ()//Getter
        {return Name;}

    int GetID ()//Getter
        {return ID;}

    bool  operator==(const Item &object)//"=="operator overloading
    {
        bool status;
        if (Name==object.Name)
            {status=true;}
        else
            {status=false;}
        return status;
    }
    void operator+=(int quantityy)//"+="operator overloading
    {
        Quantity+=quantityy;

    }
    void operator-=(int quantity)//"-="operator overloading
    {

        Quantity-=quantity;


    }
     friend ostream &operator<<(ostream &cou, const Item& object)//"cout"operator overloading
    {
        cou<<"ID : "<<object.ID<<endl;
        cou<<"Name : "<<object.Name<<endl;
        cou<<"Price : "<<object.Price<<endl;
        cou<<"Quantity : "<<object.Quantity<<endl;
        cou<<endl;
        cou<<"----------------------------------------"<<endl;
        return cou;
    }
     friend istream &operator>>(istream &cn, Item& object)//"cin"operator overloading
    {
        cn>>object.Name>>object.Price>>object.Quantity;
        return cn;
    }

};
class Seller
{
private:
    string Name;
    string Email;
    Item *items;
    int MaxItems;
public:
    Seller(int sizee)//Parametrized constructor
    {
        MaxItems=sizee;
        items=new Item[MaxItems];
        for (int i=0;i<MaxItems;i++)
        {
            items[i].SetQuantity(0);
            items[i].SetPrice(-1);//negative number to let the user have any number even 0
            items[i].SetName("o");
        }
    }

    bool AddAnItem (Item param)//add an item to the seller list
    {
        for (int i =0;i< MaxItems ; i++ )
        {
          if (param==items[i])//if this item already exist increase quantity
          {
              items[i]+=param.GetQuantity();
              return true;
          }
        }
        for (int i=0;i<MaxItems;i++)//else save item in a index it the array
        {
            if (items[i].GetName()=="o")
             {
                items[i].SetName(param.GetName());
                items[i].SetPrice(param.GetPrice());
                items[i].SetQuantity(param.GetQuantity());;

                return true;
             }
        }
        return false ;//if there is any wrong

    }

    bool SellAnItem (string namee,int quantityy)//to sell an item
    {
        int c=-1;//because if entered the for loop change c to i which equal 0 and start to increase
        for (int i =0;i<MaxItems;i++)
        {
            if (items[i].GetName()==namee)
            {c=i;}
        }

        if (c!=-1 && items[c].GetQuantity()>=quantityy)
        {
            items[c]-=quantityy;
            return true;
        }

        else if (items[c].GetQuantity()<quantityy)
        {
            cout<<"There is only "<<items[c].GetQuantity()<<" left of this item "<<endl;
            return false;
        }

        else if (c==0)
        {return false;}

    }

    void PrintItems ()
    {

        for (int i=0;i<MaxItems;i++)
        {
            if (items[i].GetPrice()!=-1)//to print only the used item not all the array
                cout<<items[i];
        }
    }

    friend istream &operator>>(istream &cen, Seller& objecto)//cin operator overloading for seller info
    {
        cen>>objecto.Name>>objecto.Email;
        return cen;
    }
    friend ostream &operator<<(ostream &couo, const Seller& objecti)//cout operator overloading for seller info
    {
        couo<<objecti.Name<<endl;
        couo<<objecti.Email<<endl;
        return couo;
    }

    Item FindAnItembyID(int idd)//to find item in seller items by its id
    {
        int l =0;
       for (int i =0;i< MaxItems ; i++ )
        {
          if (idd==items[i].GetID())
          {l=i;}
        }
          return items[l];
    }

    ~Seller()//destructor
    {
        delete []items;
    }

};



int Item::id=1;//to make ids for every new object

int main()
{
    string NameofSold;
    int Counter,maxitems,id,QuantityofSold;

    cout<<"Enter number of items : "<<endl;
    cin>>maxitems;

    Seller one(maxitems);

    cout<<"Enter your info : "<<endl;
    cin>>one;
    Item n;





    while (Counter!=6)
    {
        cout<<"1.Print My Info ."<<endl;
        cout<<"2.Add An Item ."<<endl;
        cout<<"3.Sell An Item ."<<endl;
        cout<<"4.Print Items ."<<endl;
        cout<<"5.Find an Item by ID ."<<endl;
        cout<<"6.Exit . "<<endl;

        cin>>Counter;

        if (Counter==1)
        {cout<<one;}

        if (Counter==2)
        {

            cout<<"Name-Price-Quantity"<<endl;
            cin>>n;

            if(!one.AddAnItem(n))
            {cout<<"Fail"<<endl;}
            else
                cout<<"Successful addition "<<endl;
        }

        if (Counter==3)
        {

            cout<<"Enter the Name of item : ";
            cin>>NameofSold;
            cout<<"Enter the Quantity of sold item: ";
            cin>>QuantityofSold;
            if (!one.SellAnItem(NameofSold,QuantityofSold))
            {cout<<"Fail";}
            else
            cout<<"Successful  "<<endl;
        }

        if (Counter==4)
        {one.PrintItems();}

        if (Counter==5)
        {
            cout<<"Enter Required ID : ";
            cin>>id;
            cout<<one.FindAnItembyID(id);
        }

    }
    return 0;
}
