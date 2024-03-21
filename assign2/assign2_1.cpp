/*Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options ->
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values.*/

#include<iostream>
using namespace std;

class box
{
    private:

    int length;
    int width;
    int height;

    public:

    box()
    {
    length = 10;
    width = 20;
    height =30;
    //cout<<"VOLUME IS : \n"<<length*width*height<<endl;
    }

    box(int a)
    {
    length = a;
    width = a;
    height = a;
    
    }

    box(int length,int width,int height)
    {
    this->length = length;
    this->width = width;
    this->height = height;
    
    }
     
    void printVolume ()
    {
    cout<<"THE VOLUME IS : "<<length*width*height<<endl;
    }
};

int main()
{
    box b;
    int choice;

    do
    {
        cout<<"Enter your choice :"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"1.Calculate Volume with default values<<endl"<<endl;
        cout<<"2.Calculate Volume with length,breadth and height with same value"<<endl;
        cout<<"3.Calculate Volume with different length,breadth and height values"<<endl;
        cin>>choice;

        switch(choice)
        {
        case 0:
        {
        cout<<"THANK YOU!"<<endl;
        }
        break;
        

        case 1:
        {
        box b;
        b.printVolume();
        }
        break;

        case 2:
        {
        int value;
        cout<<"Enter single value :"<<endl;
        cin>>value;
        box b(value);
        b.printVolume();
        }
        break;

        case 3:
        {
            int a,m,c;
            cout<<"Enter length,width,height : "<<endl;
            cin>>a>>m>>c;
            box b(a,m,c);
            b.printVolume();
        }
        break;

        default:
        {
        cout<<"Invalid choice! Please enter correct choice."<<endl;
        }
        }

    }while(choice!=0);
     return 0;

}