/*Write a class Address with data members (string building, string street, string city ,int pin)
Implement constructors, getters, setters, accept(), and display() methods.
Test the class functunalities by creating the object of class and calling all the functions.*/
#include<iostream>
using namespace std;

class address
{
private :

string building,street,city;
int pin;

public :

// Constructor
    address()
    {
        building = "Sunbeam";
        street = "shanivaar peth";
        city = "karad";
        pin = 415110;
    }
    address(string building,string street,string city,int pin)
    {
        //cout << "ADDRESS BY Parameterless Constructor" << endl;
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }

    void accept()
    {
        //getchar();
        cout<<"Fill following details:"<<endl;
        cout<<"building name :"<<endl;
        cin>>building;

        //getline(cin,building);
        cout<<"street name :";
        cin>>street;
        cout<<"city name :";
        cin>>city;
        cout<<"pin code :";
        cin>>pin;
    }
// Mutator -> Setter
    void setbuild(string b)
    {
        building = b;
    }
    void setstreet(string st)
    {
        street = st;
    }
    void setcity(string c)
    {
        city = c;
    }
    void setpin(int p)
    {
        pin = p;
    }
// Inspectors -> Getter
    string getbuild()
    {
        return building;
    }
    string getstreet()
    {
        return street;
    }
    string getcity()
    {
        return city;
    }
    int getpin()
    {
        return pin;
    }

    void display()
    {
        cout<<"The address is :"<<building<<"\n"<<street<<"\n"<<city<<"\n"<<pin<<endl;
    }
};
int main()
{
    address a0;   //parameterless
    a0.display();
    address a1;     
    a1.accept();
    a1.display();
    address a2("shivajinagar","swargate","kothrud",416115);  //parameterized
    a2.display();
    address a3; //set-get
    a3.setbuild("Ashirwad");
    a3.setstreet("ghole road");
    a3.setcity("pune");
    a3.setpin(411505);
    //cout<<"ADDRESS BY SET-GET IS :"<<endl";
    cout<<"building name:"<<a3.getbuild()<<endl;
    cout<<"street name:"<<a3.getstreet()<<endl;
    cout<<"city name:"<<a3.getcity()<<endl;
    cout<<"pin code:"<<a3.getpin()<<endl;

    return 0;
}
/*faciliators
    //void displayPoint()
    //{
     //   cout << "mk (" << xaxis << "," << this->yaxis << ")" << endl;
    //}

Destructor
    ~Point()
    {
        cout << "Destructor" << endl;
    }*/





