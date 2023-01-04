#include <string>
#include <fstream>
#include "customer.h"

void Customer::FileInput(Customer customer[], int nrUsers)				//the funcion used to create files with users' data
{
    for (int i = 0; i < nrUsers; i++)
    {
        string output[6], bank_balance, ban_status, loan_balance, loanOwe;

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

            output[0].append(output[1]);
            output[0].append(output[2]);
            output[0].append(output[3]);
            output[0].append(output[5]);
            output[0].append(output[4]);
            string name2;
            if (i == 0)									//for the admin
            {
                name2 = "";
                string name3(".txt");
                name2.append(customer[i].surname);
                name2.append(name3);
            }
            else										//for the rest of the users
            {
                name2 = "Customer ";
                string name3(".txt");
                name2.append(customer[i].surname);
                name2.append(name3);
            }

            fstream customerF;

            customerF.open(name2, ios::out);

            if (customerF.is_open())				//checking whether the file is open
            {
                customerF << output[0];
                customerF.close();					 //close the file object
            }


    }
}

void Customer::FileOutput(Customer customer[], int nrUsers)
{
    for (int i = 0; i < nrUsers; i++)
    {

                string bank_balance, ban_status, loan_balance, loanOwe;

                fstream file;
                string customer_bank_balance, customer_ban_status, customer_loan_balance, customer_loanOwe, name, surname;

                string file_name, input;
                if(i == 0) file_name = "Admin.txt";
                else {
                   file_name = "Customer ";
                      file_name.append(customer[i].surname);
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

                     file.close();
                }
                else continue;

                string bank_balance_str = "", loan_balance_str = "", loanOwe_str = "", ban_status_str = "";

                for(int j = 14; j<customer_bank_balance.size(); j++) {bank_balance_str += customer_bank_balance[j];loan_balance_str += customer_loan_balance[j];}
                for(int j = 25; j<customer_loanOwe.size(); j++) loanOwe_str += customer_loanOwe[j];
                for(int j = 12; j<customer_ban_status.size(); j++) ban_status_str += customer_ban_status[j];

                customer[i].bank_balance = stof(bank_balance_str);
                customer[i].loan = stof(loan_balance_str);
                customer[i].loanOwe = stof(loanOwe_str);
                customer[i].ban_status = stof(ban_status_str);


    }

}
