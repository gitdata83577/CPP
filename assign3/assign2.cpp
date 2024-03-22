/*
Q2. Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
Allocate the memory for the the object dynamically and test the functunalities using time ptr.
*/
#include<iostream>
using namespace std;

class Time
{
    int sec;
    int min;
    int hrs;
    int time;

public:
    Time()
    {
        sec=50;
        min=12;
        hrs=11;
    }

    Time(int h, int m, int s)
    {
        hrs=h;
        min=m;
        sec=s;
    }

    void setHour(int hrs)
    {
        this->hrs=hrs;
    }

    int getHour()
    {
        return this->hrs;
    }

    void setMinute(int min)
    {
        this->min=min;
    }

    int getMinute()
    {
        return this->min;
    }

    void setSecond(int sec)
    {
        this->sec=sec;
    }

    int getSecond()
    {
        return sec;
    }

    void printTime()
    {
        
        cout<<"Time = "<<hrs<<": "<<min<<": "<<sec<<endl;
    }

};

int main()
{
    Time *t1 = new Time;
    t1->printTime();

    Time *t2 = new Time(10,5,8);
    t2->printTime();
   
    t1->setHour(1);
    t1->getHour();
    t1->printTime();
    
    t1->setMinute(5);
    t1->getMinute();
    t1->printTime();
    
    t1->setSecond(5);
    t1->getSecond();
    t1->printTime();

    
    

    return 0;
}