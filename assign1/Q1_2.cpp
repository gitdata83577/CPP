/*Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();*/
#include<iostream>
using namespace std;

struct Date
{
    int dd;
    int mm;
    int yyyy;

  void initDate()
  {
    dd = 23;
    mm = 4;  //Month should be specified without leading zeros
    yyyy =1999;
  }
  void acceptDateFromConsole()
  {
    cout<<"Enter Date"<<":"<<endl;
    cin>>dd>>mm>>yyyy;  //no need to end cin (scanf) in endl

  
    
  }
  void printDateOnConsole()
  {
    cout<<"Date - "<<dd<<"-"<<mm<<"-"<<yyyy<<endl;

   if(isLeapYear())
   cout<<"This year is a Leap year! "<<endl;
   else
   cout<<"This year is NOT a Leap year!"<<endl;
  }

  
  bool isLeapYear()
  {
    if((yyyy%4==0 && yyyy%100!=0) || (yyyy%400==0))
      return true;
    else
      return false;
  }
};

int main()
{
  struct Date d;
  d.initDate();
  int choice;
  

  do
  {
    cout<<"Enter your choice\n"<<"0.Exit\n"<<"1.Accept Date\n"<<"2.Display Date\n"<<endl;
    cin>>choice;

    switch(choice)
    {
     case 0:
     cout<<"Thank you for using this app."<<endl;
     break;

     case 1:
     d.acceptDateFromConsole();
     break;

     case 2:
     d.printDateOnConsole();
     break;

     default :
     cout<<"Incorrect choice! Please enter correct choice."<<endl;
    }

  }while(choice!=0);

return 0;
 
  
}
