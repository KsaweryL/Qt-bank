#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer
{
public:

    string name, surname, login, password;
    int active;
    float bank_balance;
    float loan;								//how much money one borrowed
    float loanOwe;							//how much money one has to return
    float ban_status;

    Customer()
    {
        name = "0";
        surname = "0";
        bank_balance = 0;
        loan = 0;
        loanOwe = 0;
        ban_status = 0;
        active = 0;


    }

    void operator + (float money)						//overloading operator + (for inserting money)
    {

        bank_balance = bank_balance + money;

    }
    void operator - (float money)						//overloading operator - (for withdrawing money)
    {

        bank_balance = bank_balance - money;

    }

    template <typename T>
    void TakingLoan(T money)
    {
        loan = loan + money;
        loanOwe = loanOwe + 1.15 * money;			//whenever a loan is taken, one has to pay back 115% of the borrowed amount of money
        bank_balance = bank_balance + money;
    }

    template <typename T>
    void GivingBackLoanMoney(T money)
    {
        if (money > loanOwe) { money = loanOwe;}

        if(money<= loan) loan = loan - money;
        loanOwe = loanOwe - money;
        bank_balance = bank_balance - money;
    }

    void FileInput(Customer customer[], int nrUsers);          //performing a write operation into the file
    void FileOutput(Customer customer[], int nrUsers);          //getting data from the file

    virtual void F_RTTI(){};

};

#endif // CUSTOMER_H
