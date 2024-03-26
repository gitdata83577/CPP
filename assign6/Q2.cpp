/*Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]*/

#include<iostream>
#include<string>
using namespace std;

class Product
{
private:
    int id;
    string title;
    double price;
public:
    Product()
    {
        id = 0;
        title = " ";
        price = 0;
    }
    virtual void accept()
    {
        cout<<"Book id:"<<id<<endl;
        cin>>id;
        cout<<"Title :"<<title<<endl;
        cin>>title;
        cout<<"Price :"<<price<<endl;
        cin>>price;

    }
    virtual void display()
    {
        cout<<"Product details are:\n"<<endl;
        cout<<"ID:"<<id<<endl;
        cout<<"Title:"<<title<<endl;
        cout<<"Price:"<<price<<endl;
    }
    void setPrice(int x)
{
    if(x==1)
        price =price*0.9;
    else
        price=price*0.95;
}
    double getPrice()
        {
            return price;
        }
};
class Book : public Product
{
    private:
    string Author;

    public:
    Book()
    {
        Author="";
    }
void accept()
{
    cout<<"Please enter the book details :\n"<<endl;
    cout<<"Enter Author name :"<<Author<<endl;
    cin>>Author;
    Product::accept();
    Product::setPrice(1);

//also reuse the function of Product(Base) class accept
//give discount of 10% on price and update the price.use mutators and inspector for price
}
virtual void display()
{
    cout<<"The details of book are:"<<endl;
    cout<<"Author name is:"<<Author<<endl;
    Product::display();
    cout<<"The discount price is : "<<Product::getPrice()<<endl;
//complete function by displaying author;
//also reuse the function of Product(Base) class display
}
};
class Tape : public Product
{
    private:
    string Artist;
    public:
    Tape()
    {
        Artist="";
    }
    void accept()
{
    cout<<"Please enter the Tape details :\n"<<endl;
    cout<<"Enter Artist :"<<Artist<<endl;
    cin>>Artist;
     Product::accept();
    Product::setPrice(2);
    //also reuse the function of Product(Base) class accept
//give discount of 5% on price and update the price.use mutators and inspector for price
}
virtual void display()
{
    cout << "The details of tape are " << endl;
    cout<<"Artist is :"<<Artist<<endl;
    Product::display();
    cout<<"The discount price is : "<<Product::getPrice()<<endl;
//also reuse the function of Product(Base) class display
//todo to display artist;
}

};

int main()
{
    int choice;
    Product *arr[3];
    int index=0;
    double total;
do
{
    cout<<"Enter your choice :"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"1.Enter Book details "<<endl;
    cout<<"2.Enter Tape details"<<endl;
    cout<<"3.Total bill of three products"<<endl;
    cout<<"4.The product details are :"<<endl;

    cin>>choice;
    switch(choice)
    {
    case 0:
    cout<<"Thank You!"<<endl;
    break;

    case 1:
    if(index<3)
    {
        arr[index]=new Book();
        arr[index]->accept();
        index++;
    }
    else
        cout<<"Array is full..."<<endl;
    break;

    case 2:
    if(index<3)
    {
        arr[index]=new Book();
        arr[index]->accept();
        index++;
    }
    else
        cout<<"Array is full..."<<endl;
    break;

    case 3:
    for(int i=0;i<index;i++)
    {
        total +=arr[i]->getPrice();
    };
    cout << "The total price of all 3 products is " << total << endl;
    break;
    
    case 4:
    for(int i=0;i<index;i++)
    {
        arr[i]->display();
    };
    break;

    default:
    cout<<"Wrong choice! Please enter correct choice."<<endl;
    break;
    }
    
} while (choice!=0);

for(int i=0;i<index;i++)
    delete arr[i];
    return 0;
// write menu driven code.
// to calculate bill use for loop and call the getPrice to make total of all products
}