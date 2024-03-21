/*Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members
day, month, year. Implement the following functions.
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);*/

#include<stdio.h>


struct Date
{
    int dd;
    int mm;
    int yyyy;
};
    void initDate(struct Date* ptrDate)
{
    ptrDate->dd = 23;
    ptrDate->mm = 04;
    ptrDate->yyyy = 1999;
}
    void acceptDateFromConsole(struct Date* ptrDate)
    {
        printf("Enter date : ");
        scanf("%d%d%d",&ptrDate->dd,&ptrDate->mm,&ptrDate->yyyy);
    }
    void printDateOnConsole(struct Date* ptrDate)
    {
        printf("Date :%d-%d-%d\n",ptrDate->dd,ptrDate->mm,ptrDate->yyyy);
    
    } 


int main()
{
 struct Date d;
 initDate(&d);
 int choice;

 printf("Enter choice : ");

 do
 {
    printf("0.Exit\n 1.accept date\n 2.display date\n");
    scanf("%d",&choice);


    switch(choice)

    {
        case 0:
        printf("Thank you for using this app!");
        break;

        case 1:
        acceptDateFromConsole(&d);
        break;

        case 2:
        printDateOnConsole(&d);
        break;

        default:
        printf(" Wrong Choice! Please entre correct choice.");
        

    }
 }while (choice!=0);
    return 0;
 
}
