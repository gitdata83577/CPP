/*Q1. Write a class to find volume of a Cylinder by using following members. (volume of
Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI)
Class having following member functions:
Cylinder()
Cylinder(double radius, double height)
getRadius()
setRadius()
getHeight()
setHeight()
getVolume()
printVolume()
Initialize members using constructor member initializer list.*/

#include<iostream>
using namespace std;

class Cylinder
{
    private:
    double radius;
    double height;
    double Volume;
    static const double PI;

public:
    //parameterless ctor
    Cylinder()
    {
        radius=2.1;
        height=3.5;
    }
    // constructor member initializer
    Cylinder(double radius): height(5.5)
    {
        this->radius=radius;
    }
    // parameterized ctor
    Cylinder(double radius, double height)
    {
        this->radius=radius;
        this->height=height;
        printVolume();
    }

    static double getPI()
    {
        return PI;
    }

    void setRadius(double radius)
    {
        this->radius=radius;
    }

    double getRadius()
    {
        return this->radius;
    }
    
    void setHeight(double height)
    {
        this->height=height;
    }

    double getHeight()
    {
        return height;
    }

    void printVolume()
    {
        
        cout<<"Volume:- "<<(Volume=PI*radius*radius*height)<<endl;
    }

    double getVolume()
    {
        return Volume;
    }
   
};
const double Cylinder::PI = 3.14;
int main()
{
    
    Cylinder a;
    a.printVolume();

    Cylinder a1(5.9,8.5);
    a1.printVolume();

    Cylinder c(10);

    Cylinder a2;
    a2.setRadius(5);
    cout<<"The radius is: "<<a2.getRadius()<<endl;

    a2.setHeight(8);
    
    cout<< "The height is "<<a2.getHeight()<<endl;

    cout<<"The Volume is: "<<a2.getVolume()<<endl;

    return 0;
}

