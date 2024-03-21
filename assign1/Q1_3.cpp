/*Q3. Write a menu driven program for Student in CPP language. Create a class student with data
members roll no, name and marks. Implement the following functions
void initStudent();
void printStudentOnConsole();
void acceptStudentFromConsole();*/

#include<iostream>
using namespace std;
class student
{
    private:

    int rollno;
    string name;
    int marks;

public:

void initStudent()
{
    rollno = 23;
    name = "Mrunal";
    marks = 77;
    cout<<"rollno :\n"<<rollno<<endl;
    cout<<"name :\n"<<name<<endl;
    cout<<"marks :\n"<<marks<<endl;
}

void acceptStudentFromConsole()
{
    cout<<"Enter the student details :"<<endl;
    cin>>rollno>>name>>marks;
}


void printStudentOnConsole()
{
    cout<<"rollno :\n"<<rollno<<endl;
    cout<<"name :\n"<<name<<endl;
    cout<<"marks :\n"<<marks<<endl;
}

};

int main()
{
    student s;
    s.initStudent();
    int choice;
    
    do
    {
        cout<<"Please enter student details :"<<"0.Exit\n"<<"1.Accept Date\n"<<"2.Display Date\n"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 0:
            cout<<"Thank you!"<<endl;
            break;

            case 1:
            s.acceptStudentFromConsole();
            break;

            case 2:
            s.printStudentOnConsole();
            break;

            default :
            cout<<"Incorrect choice! Please enter correct choice."<<endl;
            break;
        }
    }while(choice!=0);

    return 0;
    
    }