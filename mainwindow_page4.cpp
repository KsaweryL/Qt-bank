#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 10            //maximum number of accounts that can exist

void MainWindow::on_pushButton_comeBackInsert_clicked()
{
    ui->lineEdit_InsertAmount->setPlaceholderText("Insert amount of money here");
    ui->stackedWidget->setCurrentIndex(3);

    ui->lineEdit_InsertAmount->setText("");                     //resetting the confirmation of the previous action
    ui->textBrowser_confirmationMoney->setText("");
}

void MainWindow::on_pushButton_insert_clicked()
{
    int customer_nr = 0;
    for(customer_nr = 0; customer_nr<N; customer_nr++)                 //to check which customer is currently active
    {
        if(customer[customer_nr].active == 1) break;
    }

    int detector = 0;
    try{
        string input = (ui->lineEdit_InsertAmount->text()).toStdString();
        for(char sign: input)
        {
            if(sign != '0' && sign != '1' && sign != '2' && sign != '3' && sign != '4' && sign != '5' && sign != '6' && sign != '7'
                    && sign != '8' && sign != '9' && sign != '.') throw 'a';
        }
        if(input == "") throw 'a';
    }
    catch (char x)
    {
        ui->textBrowser_confirmationMoney->setText("The input isn't a number. Please, redefine it!");
        detector = 1;
    }

    if(detector == 0)
    {
    if(ui->pushButton_insert->text() == "Insert"){                              //if we are inserting money
    customer[customer_nr] + stof(ui->lineEdit_InsertAmount->text().toStdString());      //converting qstring to string and then to float
    ui->textBrowser_confirmationMoney->setText(ui->lineEdit_InsertAmount->text() + "zł was successfully added to your account");
}

if(ui->pushButton_insert->text() == "Withdraw")                                 //if we are withdrawing money
{
    int det = 0;
    try{
        if(stof(ui->lineEdit_InsertAmount->text().toStdString()) > customer[customer_nr].bank_balance) throw 'a';       //if user wants to withdraw more money than he/she currently has, throw an exception
    }
    catch(char x)
    {
        det = 1;
        ui->textBrowser_confirmationMoney->setText("Exception cought: not enough money on the account");
    }

    if(det == 0)
    {
        customer[customer_nr] - stof(ui->lineEdit_InsertAmount->text().toStdString());      //converting qstring to string and then to float
        ui->textBrowser_confirmationMoney->setText(ui->lineEdit_InsertAmount->text() + "zł was successfully withdrawn from your account");
    }
}

if(ui->pushButton_insert->text() == "Take out")                         //when user takes out a loan
{
    customer[customer_nr].TakingLoan(stof(ui->lineEdit_InsertAmount->text().toStdString()));        //taking out a loan
     ui->textBrowser_confirmationMoney->setText(ui->lineEdit_InsertAmount->text() + "zł was successfully taken out as a loan");         //confirmation

}

    if(ui->pushButton_insert->text() == "Give back")                         //when user gives back money he/she took out earlier for a loan
    {
        customer[customer_nr].GivingBackLoanMoney(stof(ui->lineEdit_InsertAmount->text().toStdString()));

         ui->textBrowser_confirmationMoney->setText(ui->lineEdit_InsertAmount->text() + "zł was successfully given back");         //confirmation
    }

     if(ui->pushButton_insert->text() == "Transfer")                         //when user wants to trasfer money to someone else
     {
         int det = 0;                                                                       //needs to be optimised!!!
         try{
             if(stof(ui->lineEdit_InsertAmount->text().toStdString()) > customer[customer_nr].bank_balance) throw 'a';       //if user wants to transfer more money than he/she currently has, throw an exception
         }
         catch(char x)
         {
             det = 1;
             ui->textBrowser_confirmationMoney->setText("Exception cought: not enough money on the account");
         }

         string given_name, given_surname;
         given_name = ui->lineEdit_TransferToPerson_Name->text().toStdString();
         given_surname = ui->lineEdit_TransferToPerson_Surname->text().toStdString();

         int customer_nr_to_whom = 0;
         for(customer_nr_to_whom = 0; customer_nr_to_whom<N; customer_nr_to_whom++)                 //to check to which customer the money should be transferred
         {
             if(customer[customer_nr_to_whom].name == given_name && customer[customer_nr_to_whom].surname == given_surname) break;
         }


         try{
             if(customer_nr_to_whom == N) throw 1;
         }
         catch(int x){
             det = 1;
             ui->textBrowser_confirmationMoney->setText("Exception cought: the given user doesn't exist");
         }
         if(det == 0)
         {
             customer[customer_nr] - stof(ui->lineEdit_InsertAmount->text().toStdString());      //converting qstring to string and then to float
             customer[customer_nr_to_whom] + stof(ui->lineEdit_InsertAmount->text().toStdString());     //adding the particular amount of money to the mentioned user's account

             ui->textBrowser_confirmationMoney->setText(ui->lineEdit_InsertAmount->text() + "zł was successfully transferred from your account to the " + QString::fromStdString(customer[customer_nr_to_whom].name) + "'s one.");
         }


     }

    ui->textBrowser_currentBalance->setText("Current bank balance: " + QString::number(customer[customer_nr].bank_balance) + "\nCurrent amount of owed money: " + QString::number(customer[customer_nr].loanOwe));          //showing the current bank balance of the user
    }
}
