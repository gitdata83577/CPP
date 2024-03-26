/*Q1. Provide menu driven code for the functionalities:
1. Accept Employee
2. Display the count of all employees with respect to designation
3. Display All Managers
4. Display All Salesman
5. Display All SalesManagers*/

#include <iostream>
using namespace std;

// *******************************************************EMPLOYEE********************************************************************
class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }

    Employee(int id, double salary)
    {
        cout << "Inside Employee(int, double)" << endl;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return salary;
    }

    virtual void accept()
    {
        cout << "Enter the id: " << endl;
        cin >> id;
        cout << "Enter the salary: " << endl;
        cin >> salary;
    }

    virtual void display()
    {
        cout << "id : " << id << endl;
        cout << "salary : " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "Inside ~Employee()" << endl;
    }
};


// *******************************************************MANAGER********************************************************************

class Manager : virtual public Employee
{
private:
    double bonus;

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }

    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int, double, double)" << endl;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return bonus;
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }

    ~Manager()
    {
        cout << "Inside ~Manager()" << endl;
    }

protected:
    void acceptManager()
    {
        cout << "Enter the bonus: " << endl;
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "Bonus : " << bonus << endl;
    }
};


// *******************************************************SALESMAN********************************************************************

class Salesman : virtual public Employee
{
private:
    double commision;

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }

    Salesman(int id, double salary, double commision)
    {
        cout << "Inside Salesman(int, double, double)" << endl;
    }

    void setCommision(double bonus)
    {
        this->commision = commision;
    }

    double getCommision()
    {
        return commision;
    }

    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }

    ~Salesman()
    {
        cout << "Inside ~Salesman()" << endl;
    }

protected:
    void acceptSalesman()
    {
        cout << "Enter the commision: " << endl;
        cin >> commision;
    }

    void displaySalesman()
    {
        cout << "commision : " << commision << endl;
    }
};

// *******************************************************SALESMANAGER********************************************************************

class Salesmanager : public Manager, public Salesman
{
public:
    Salesmanager()
    {
        cout << "Inside Salesmanager()" << endl;
    }

    Salesmanager(int id, double salary, double bonus, double commision)
    {
        cout << "Inside Salesmanager(int, double, double)" << endl;
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }

    ~Salesmanager()
    {
        cout << "Inside ~Salesmanager()" << endl;
    }
};

int main()
{
    int choice;
    int index = 0;
    Employee *sptr[10];
    do
    {
        cout << "0. EXIT" << endl;
        cout << "1. Accept Employee" << endl;
        cout << "2. Display the count of all employees with respect to designation" << endl;
        cout << "3. Display All Managers" << endl;
        cout << "4. Display All Salesman" << endl;
        cout << "5. Display All SalesManagers" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            for (int i = 0; i < index; i++)
            {
                delete sptr[i];
                sptr[i] = NULL;
            }
            cout << "Thankyou..." << endl;
            break;
        case 1:
        {
            int option;
            cout << "1. accept Manager" << endl;
            cout << "2. accept Salesman" << endl;
            cout << "3. accept Salesmanager" << endl;
            cout << "Enter your choice" << endl;
            cin >> option;
            if (option == 1)
            {
                if (index < 10)
                {
                    sptr[index] = new Manager();
                    sptr[index]->accept();
                    index++;
                }
                else
                {
                    cout << "Array is full" << endl;
                }
            }
            else if (option == 2)
            {
                if (index < 10)
                {
                    sptr[index] = new Salesman();
                    sptr[index]->accept();
                    index++;
                }
                else
                {
                    cout << "Array is full" << endl;
                }
                cout << "Array is full" << endl;
            }
            else if (option == 3)
            {
                if (index < 10)
                {
                    sptr[index] = new Salesmanager();
                    sptr[index]->accept();
                    index++;
                }
                else
                {
                    cout << "Array is full" << endl;
                }
            }
            else
            {
                cout << "Wrong choice" << endl;
            }
        }
        break;
        case 2:
        {
            int countManager = 0;
            int countSalesman = 0;
            int countSalesmanager = 0;
            for (int i = 0; i < index; i++)
            {
                if (typeid(*sptr[i]) == typeid(Manager))
                {
                    countManager++;
                }
                else if (typeid(*sptr[i]) == typeid(Salesman))
                {
                    countSalesman++;
                }
                else if (typeid(*sptr[i]) == typeid(Salesmanager))
                {
                    countSalesmanager++;
                }
            }
            cout << "Number of Managers : " << countManager << endl;
            cout << "Number of Salesman : " << countSalesman << endl;
            cout << "Number of Salesmanager : " << countSalesmanager << endl;
        }
        break;
        case 3:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*sptr[i]) == typeid(Manager))
                {
                    sptr[i]->display();
                }
            }
            break;
        }
        case 4:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*sptr[i]) == typeid(Salesman))
                {
                    sptr[i]->display();
                }
            }
            break;
        }
        case 5:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*sptr[i]) == typeid(Salesmanager))
                {
                    sptr[i]->display();
                }
            }
            break;
        }
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}