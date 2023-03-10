#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#define N 10

using namespace std;

class Customer
{
    string name, surname, login, password;
    float active;
    float bank_balance;
    float loan;								//how much money one borrowed
    float loanOwe;							//how much money one has to return
    float ban_status;

    float customer_nr;                      //a unique number for each of the customers
public:

    Customer()
    {
        name = "0";
        surname = "0";
        login = "0";
        password = "0";
        bank_balance = 0;
        loan = 0;
        loanOwe = 0;
        ban_status = 0;
        active = 0;
        customer_nr = N+1;
    }


    void Change(string input, string type_of_input)                           //used for assigning values to the members of the class
    {
        if(type_of_input == "name") name = input;
        if(type_of_input == "surname") surname = input;
        if(type_of_input == "login") login = input;
        if(type_of_input == "password") password = input;
        if(type_of_input == "active") active = stoi(input);
        if(type_of_input == "bank_balance") bank_balance = stof(input);
        if(type_of_input == "loan") loan = stof(input);
        if(type_of_input == "loanOwe") loanOwe = stof(input);
        if(type_of_input == "ban_status") ban_status = stof(input);
        if(type_of_input == "customer_nr") customer_nr = stof(input);
    }


   string operator [](string type_of_input)                     //for returning a string
   {
       if(type_of_input == "name") return name;
       else if(type_of_input == "surname") return surname;
       else if(type_of_input == "login") return login;
       else if(type_of_input == "password") return password;
       else return "0";
   }

   float Return_float (string type_of_input)                                         //for returning a float
   {
       if(type_of_input == "active") return active;
       else if(type_of_input == "bank_balance") return bank_balance;
       else if(type_of_input == "loan") return loan;
       else if(type_of_input == "loanOwe") return loanOwe;
       else if(type_of_input == "ban_status") return ban_status;
       else if(type_of_input == "customer_nr") return customer_nr;
       else return 0;
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
    string Ciphering(string option);
    void Deciphering(string ciphered_password, string option);

};

#endif // CUSTOMER_H
