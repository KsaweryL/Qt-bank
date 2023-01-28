#include <string>
#include <fstream>
#include "customer.h"

#define N 10

string Customer::Ciphering(string option)                                //ciphering the password or the login
{
    string ciphered_string = "";
    if(option == "password") ciphered_string = password;
    if(option == "login") ciphered_string = login;

    for(int i = 0; i<ciphered_string.size();i++ ) ciphered_string[i] += 4;

    return ciphered_string;
}

void Customer::Deciphering(string ciphered_string, string option)        //deciphering the password or the login
{
    string Deciphered_string = ciphered_string;

    for(int i = 0; i<Deciphered_string.size();i++ ) Deciphered_string[i] -= 4;

    if(option == "password") password = Deciphered_string;
    if(option == "login") login = Deciphered_string;
}

void Customer::FileInput(Customer customer[], int nrUsers)				//the funcion used to create files with users' data
{
    for (int i = 0; i < nrUsers; i++)
    {
        string output[8], bank_balance, ban_status, loan_balance, loanOwe;

        bank_balance = std::to_string(customer[i].bank_balance);
        ban_status = std::to_string(customer[i].ban_status);
        loan_balance = std::to_string(customer[i].loan);
        loanOwe = std::to_string(customer[i].loanOwe);

            output[0] = "Name: ";
            output[0].append(customer[i].name);

            output[1] = "\nSurname: ";
            output[1].append(customer[i].surname);

            output[2] = "\nBank balance: ";
            output[2].append(bank_balance);

            output[3] = "\nLoan balance: ";
            output[3].append(loan_balance);

            output[4] = "\nBan status: ";
            output[4].append(ban_status);

            output[5] = "\nLoan balance + interest: ";
            output[5].append(loanOwe);

            output[6] = "\nLogin: ";
            output[6].append(customer[i].Ciphering("login"));

            output[7] = "\nPassword: ";
            output[7].append(customer[i].Ciphering("password"));              //the password saved in the file is ciphered

            output[0].append(output[1]);
            output[0].append(output[2]);
            output[0].append(output[3]);
            output[0].append(output[5]);
            output[0].append(output[4]);
            output[0].append(output[6]);
            output[0].append(output[7]);
            string name2;
            if (i == 0)									//for the admin
            {
                name2 = "";
                string name3(".txt");
                name2.append(to_string(customer[i].customer_nr));
                name2.append(name3);
            }
            else										//for the rest of the users
            {
                if(customer[i].name != "0"){
                name2 = "Customer_";
                string name3(".txt");
                name2.append(to_string(customer[i].customer_nr));
                name2.append(name3);
                }
            }

            fstream customerF;

            customerF.open(name2, ios::out);

            if (customerF.is_open())				//checking whether the file is open
            {
                customerF << output[0];
                customerF.close();					 //close the file object
            }


    }

    fstream list_of_customers;                                  //creating a seperate file that contains current list of users

    string list_of_users = "";
    for(int i = 0; i<N; i++)
    {
            list_of_users.append(to_string(customer[i].customer_nr));
            list_of_users.append("\n");
            list_of_users.append(customer[i].name);
            list_of_users.append("\n");
            list_of_users.append(customer[i].surname);
            list_of_users.append("\n");

    }

    list_of_customers.open("List_of_customers.txt", ios::out);

    if (list_of_customers.is_open())				//checking whether the file is open
    {
        list_of_customers << list_of_users;
       list_of_customers.close();					 //close the file object
    }

}

void Customer::FileOutput(Customer customer[], int nrUsers)
{
    fstream list_of_customers;

     list_of_customers.open("List_of_customers.txt", ios::in);                                                          //reading the names and surnames of the users that were created previously
     if (list_of_customers.is_open())				//checking whether the file is open
     {
         for(int i = 0; i < nrUsers; i++){
         string cutomer_nr = "";
         getline(list_of_customers, cutomer_nr);
         getline(list_of_customers, customer[i].name);
         getline(list_of_customers, customer[i].surname);
         customer[i].customer_nr = stof(cutomer_nr);
         }
         list_of_customers.close();
     }

    for (int i = 0; i < nrUsers; i++)
    {

                string bank_balance, ban_status, loan_balance, loanOwe;

                fstream file;
                string customer_bank_balance, customer_ban_status, customer_loan_balance, customer_loanOwe, name, surname, customer_login, customer_password;

                string file_name, input;
                if(i == 0) file_name = "0.000000.txt";
                else {
                   file_name = "Customer_";
                      file_name.append(to_string(customer[i].customer_nr));
                    file_name.append(".txt");
                }

                file.open(file_name, ios::in);
                if(file.is_open())                                      //reading from the file
                {
                     getline(file, name);
                     getline(file, surname);
                     getline(file, customer_bank_balance);
                     getline(file, customer_loan_balance);
                     getline(file, customer_loanOwe);
                     getline(file, customer_ban_status);
                     getline(file, customer_login);
                     getline(file, customer_password);

                     file.close();
                }
                else continue;

                string bank_balance_str = "", loan_balance_str = "", loanOwe_str = "", ban_status_str = "", login_str = "", password_str = "", name_str = "", surname_str = "";

                for(int j = 6; j<name.size(); j++) name_str += name[j];                     //only a part after the colon character (:) should be read and stored in the members of the customer object
                for(int j = 9; j<surname.size(); j++) surname_str += surname[j];
                for(int j = 14; j<customer_bank_balance.size(); j++) {bank_balance_str += customer_bank_balance[j];loan_balance_str += customer_loan_balance[j];}
                for(int j = 25; j<customer_loanOwe.size(); j++) loanOwe_str += customer_loanOwe[j];
                for(int j = 12; j<customer_ban_status.size(); j++) ban_status_str += customer_ban_status[j];
                for(int j = 7; j<customer_login.size(); j++) login_str += customer_login[j];
                for(int j = 10; j<customer_password.size(); j++) password_str += customer_password[j];


                customer[i].Deciphering(password_str, "password");                  //deciphering the password and assigning it to the object
                customer[i].Deciphering(login_str, "login");                        //deciphering the login and assigning it to the object
                customer[i].name = name_str;
                customer[i].surname = surname_str;
                customer[i].bank_balance = stof(bank_balance_str);
                customer[i].loan = stof(loan_balance_str);
                customer[i].loanOwe = stof(loanOwe_str);
                customer[i].ban_status = stof(ban_status_str);

    }

}
