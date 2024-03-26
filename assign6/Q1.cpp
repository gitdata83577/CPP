/*Q1. Create a class Date with data memebrs day,month and year.
Create a class Person with data members name,address and birthdate. The birthdate shoud be of
type Date.
Create a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.
Employee class should be inherited from Person.
Implement following classes. Test all functionalities in main().
(Note - Perform the Association and Inheritance in the above case.)*/
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void acceptDate()
    {
        cout << "Enter Day:" << endl;
        cin >> day;
        cout << "Enter month:" << endl;
        cin >> month;
        cout << "Enter year:" << endl;
        cin >> year;
    }

    void displayDate()
    {
        cout << "Date is:" << day << "/" << month << "/" << year << endl;
    }
};
class Person
{
private:
    string name;
    string address;
    Date birthDate;

public:
    Person()
    {
        name = "";
        address = "";
    }
    // birthDate = new Date

    void acceptData()
    {

        cout << "Name :" << name << endl;
        cin >> name;
        cout << "Address :" << address << endl;
        cin >> address;
        cout << "birthDate :\n";
        birthDate.acceptDate();
        cout << endl;
    }
    void displayData()
    {
        cout << "Person is:" << name << "/" << address << "/" ;
        birthDate.displayDate();
    }
};
class Employee : public Person
{
    int empid;
    string dept;
    double salary;
    Date doj;
public:
    void acceptData()
    {
        cout << "Enter Employee ID:";
        cin >> empid;
        cout << "Enter Salary:";
        cin >> salary;
        cout << "Enter Department:";
        cin >> dept;
        cout << "Enter Date of Joining:\n";
        doj.acceptDate();
        Person::acceptData();
        cout << endl;
    }

    void displayData()
    {
        cout << "Employee ID:" << empid << endl;
        cout << "Salary:" << salary << endl;
        cout << "Department:";
        doj.displayDate();
        Person::displayData();
        cout << endl;
    }
};
int main()
{
    // Date d;
    // d.acceptDate();
    // d.displayDate();

    // Person p;
    // p.acceptPersonDatails();
    // p.displayPerson();

    Employee e;
    e.acceptData();
    e.displayData();

    /*
    person *ptr=new Employee;
    ptr->acceptdata();
    ptr->displaydata();*/

    return 0;
}
