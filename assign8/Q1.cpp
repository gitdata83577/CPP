/*Q1. Write a class to store Account information of Bank customer by using following class diagram.
Use enum to store information of account type.
Create an array of 5 Accounts in main() and accept their details from user.
Write Menu driven program to deposit/withdraw amount from the account.
After each transaction display updated account balance.
Throw exceptions for invalid values.
Also implement an exception class InsufficientFundsException.
In withdraw if sufficient balance is not available in account or while deposit the entered amount is
negative then throw this exception.*/
#include <iostream>
using namespace std;

enum EAccountType
{
    saving = 1,
    current,
    dmat
};
class InsufficientFundsException
{
private:
    int accno;
    EAccountType type;
    double balance;
    double amount;

public:
    // constructor to initialize object of class Exception
    InsufficientFundsException(int accno, double balance, int amount)
    {
        this->accno = accno;
        this->balance = balance;
        this->amount = amount;
    }
    void displayException()
    {
        cout << "Insufficient Balance in account no : " << accno << endl;
        cout << "Current Balance is : " << balance << endl;
        cout << "Withdrawal Amount: " << amount << endl;
    }
};
// Class to store Account information
class Account
{
private:
    int accno;
    EAccountType type;
    double balance;

public:
    Account()
    {
        cout << "Account details :" << endl;
    }

    Account(int accno, EAccountType type, double balance)
    {
        this->accno = accno;
        this->type = type;
        this->balance = balance;
    }
    // Function to accept account details from user
    void acceptdetails()
    {
        int choice;
        cout << "Enter account number :" << accno << endl;
        cin >> accno;
        cout << "Enter account type to create:(Saving / Current / Demat)" << type << endl;
        cout << "1.Saving \n 2.Current\n 3.Demat" << choice << endl;
        cin >> choice;
        if (choice <= 0 || choice > 3)
            throw "Worng input";     // throwing exception when user enter wrong input
        type = EAccountType(choice); // to convert enum value back to its actual data type.
        // if(type==saving)
        //     cout<<"Savings";
        // else if(type==current)
        //     cout<<"Current";
        // else
        // cout<<"Dmat";
        // cout<<endl;
        cout << "Enter Balance = " << endl;
        cin >> balance;
    }
    // Function to display account details
    void displaydetails()
    {
        cout << "Account number : " << accno << endl;
        cout << "Account Type : ";
        switch (type) //account type
        {
        case saving:
            cout << "Saving" << endl;
            break;
        case current:
            cout << "Current" << endl;
            break;
        case dmat:
            cout << "DMAT" << endl;
        default:
            cout << "Invalid Account Type" << endl;
        }
        cout << "Balance : Rs." << balance << endl;
    }
    // Function to deposit amount into the account
    void deposite(double amount)
    {
        /*if (amount < 0) {
            throw invalid_argument("Deposit amount cannot be negative");
        }*/
        balance += amount;
    }
    // Function to withdraw amount from the account
    void withdrawal(double amount)
    {
        cout << "Your balance is-Rs." << balance << endl;
        if (amount <= 0)
            cout << "Low balance! Cannot perform transaction!" << endl;
        if (amount > balance)
        {
            throw InsufficientFundsException(accno, balance, amount);
        }
        balance -= amount;
        cout << "withdraw amount Rs." << amount << "Tansaction successful!" << endl;
    }
    int get_accno()
    {
        return accno;
    }
    void set_accno(int accno)
    {
        this->accno = accno;
    }
    double get_balance()
    {
        return balance;
    }
    void set_balance(double balance)
    {
        this->balance = balance;
    }
};
int main()
{
    int choice;
    int index = 0;
    double amount;
    Account *arr[5];
    do
    {
        // cout << "0. EXIT" << endl;-> no need to write exit here
        cout << "1. Create an Account" << endl;
        cout << "2. Display Account details :" << endl;
        cout << "3. To deposit the amount" << endl;
        cout << "4. To withdraw the amount" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
            // case 0 :
            // cout << "Thankyou..." << endl;
            // break;

        case 1:
            if (index < 5)
            {
                arr[index] = new Account();
                arr[index]->acceptdetails();
                index++;
            }
            break;

        case 2:
            for (int i = 0; i < index; i++)
                arr[i]->displaydetails();
            break;

        case 3:// Deposite
            int accno;
            cout << "Enter account number : ";
            cin >> accno;
            cout << "Amount to be deposite : " << amount << endl;
            cin >> amount;

            for (int i = 0; i < index; i++)
            {
                if (accno == arr[i]->get_accno())
                    arr[i]->deposite(amount);
                arr[i]->displaydetails();
            }

            break;

        case 4://// Withdraw
            cout << "Enter account number : ";
            cin >> accno;
            for (int i = 0; i < index; i++)
            {
                if (accno == arr[i]->get_accno())
                    arr[i]->withdrawal(amount);
                    arr[i]->displaydetails();
                try
                {
                    cout << "Amount to be withdraw : "<< endl;
                    cin >> amount;

                    arr[i]->withdrawal(amount);
                }
                catch (InsufficientFundsException e)
                {
                    e.displayException();
                }
                break;
            }
        default:
            cout << "Invalid choice! Please enter again.\n" << endl;
        }

    } while (choice != 0);
};

