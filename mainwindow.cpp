#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 4            //maximum number of accounts that can exist

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i<N; i++)
    {
        customer[i].name = "0";
    }

        admin.login = "admin";
        admin.password = "adminpass";
        customer[0].name = "Admin";
        customer[0].surname = "Admin";
        customer[0].login = admin.login;
        customer[0].password = admin.password;

        customer[1].name = "Adam";
        customer[1].surname = "Kowalski";
        customer[1].login = "login1";
        customer[1].password = "password1";

        customer[2].name = "Barbara";
        customer[2].surname = "Nowak";
        customer[2].login = "login2";
        customer[2].password = "password2";

        ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_3_clicked()
{

    for(int i = 0; i<N; i++)
    {
        if(customer[i].name != "0"){
        if((ui->lineEdit_login->text()).toStdString() == customer[i].login &&
                (ui->lineEdit_password->text()).toStdString() == customer[i].password &&
                (ui->lineEdit_login->text()).toStdString() != "" &&
                (ui->lineEdit_password->text()).toStdString() != "")
            {

                ui->textBrowser_welcome->setText("                                  Welcome " + QString::fromStdString(customer[i].name) + "!");

                customer[i].active = 1;
                ui->textBrowser_currentBalance->setText("Current bank balance: " + QString::number(customer[i].bank_balance));          //showing the current bank balance of the user

                ui->lineEdit_login->setText("");                   //resetting the input for both login and password
                ui->lineEdit_password->setText("");
                ui->stackedWidget->setCurrentIndex(3);

            }
        }
    }


    ui->textBrowser_incorrectLogin->setText("Either login or password is incorrect.");

}


void MainWindow::on_pushButton_login_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_newAccount_clicked()
{
    for(int i = 0; i<N; i++)                 //resetting the active status for all users just in case
    {
        customer[i].active = 0;
    }

    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_restatePassword->hide();
    ui->textBrowser_RepeatPassword->hide();
    ui->pushButton_restate->hide();
}


void MainWindow::on_pushButton_comeBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    for(int i = 0; i<N; i++)                 //resetting the active status for all users when coming back to main menu
    {
        customer[i].active = 0;
    }

}


void MainWindow::on_pushButton_InsertMoney_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to insert?");
    ui->pushButton_insert->setText("Insert");
     ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_insert_clicked()
{
    int customer_nr = 0;
    for(customer_nr = 0; customer_nr<N; customer_nr++)                 //to check which customer is currently active
    {
        if(customer[customer_nr].active == 1) break;
    }

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
    int customer_nr = 0;
    for(customer_nr = 0; customer_nr<N; customer_nr++)                 //to check which customer is currently active
    {
        if(customer[customer_nr].active == 1) break;
    }

    customer[customer_nr].TakingLoan(stof(ui->lineEdit_InsertAmount->text().toStdString()));        //taking out a loan
     ui->textBrowser_confirmationMoney->setText(ui->lineEdit_InsertAmount->text() + "zł was successfully taken out as a loan");         //confirmation

}

ui->textBrowser_currentBalance->setText("Current bank balance: " + QString::number(customer[customer_nr].bank_balance) + "\nCurrent loan balance: " + QString::number(customer[customer_nr].loanOwe));          //showing the current bank balance of the user

}


void MainWindow::on_pushButton_comeBackInsert_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    ui->lineEdit_InsertAmount->setText("");                     //resetting the confirmation of the previous action
    ui->textBrowser_confirmationMoney->setText("");
}


void MainWindow::on_pushButton_WithdrawMoney_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to withdraw?");
    ui->pushButton_insert->setText("Withdraw");
     ui->stackedWidget->setCurrentIndex(4);

}


void MainWindow::on_pushButton_TakeOutLoan_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to take out as a loan?");
    ui->pushButton_insert->setText("Take out");
     ui->stackedWidget->setCurrentIndex(4);


}


void MainWindow::on_pushButton_ComeBackMainMenu_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
     ui->textBrowser_incorrectLogin->setText("");       //resetting the text output in login menu

     for(int i = 0; i<N; i++)                 //resetting the active status for all users when coming back to main menu
     {
         customer[i].active = 0;
     }


}




void MainWindow::on_pushButton_insertNewData_clicked()
{

    ui->textBrowser_RepeatPassword->show();
    ui->lineEdit_restatePassword->show();
    ui->pushButton_restate->show();

    ui->textBrowser_RepeatPassword->setText("Please confirm your passwordf by restating it");


}


void MainWindow::on_pushButton_restate_clicked()
{
    string newName, newSurname, newLogin, tempNewPassword, newPassword;

    newName = (ui->lineEdit_newName->text()).toStdString();
    newSurname = (ui->lineEdit_newSurname->text()).toStdString();
    newLogin = (ui->lineEdit_newTempLogin->text()).toStdString();
    tempNewPassword = (ui->lineEdit_newTempPassword->text()).toStdString();
    newPassword = (ui->lineEdit_restatePassword->text()).toStdString();

    try{
        if(newPassword != tempNewPassword) throw 1;
    }
    catch (int x)
    {
        ui->textBrowser_RepeatPassword->setText("Exception caught: Passwords do not match. Please redefine them");
    }

    if(newPassword == tempNewPassword)              //everything is correct, creating new account
    {
        int customer_nr = 0;
        int detector = 0;
        for(customer_nr = 0; customer_nr<N; customer_nr++)                 //to check if there is an empty slot for a new customer and if there is - assing all of the data to it
        {
            if(customer[customer_nr].name == "0") break;
            if(customer[customer_nr].name != "0") detector++;
        }

        try {
            if(detector == N) throw 'a';
        } catch (char a) {
            ui->textBrowser_RepeatPassword->setText("Exception caught: No more new accounts can be created");
        }

        customer[customer_nr].name = newName;
        customer[customer_nr].surname = newSurname;
        customer[customer_nr].login = newLogin;
        customer[customer_nr].password = newPassword;

        ui->lineEdit_newName->setText("");                      //resetting the input
         ui->lineEdit_newSurname->setText("");
          ui->lineEdit_newTempLogin->setText("");
           ui->lineEdit_newTempPassword->setText("");
            ui->lineEdit_restatePassword->setText("");

        ui->textBrowser_RepeatPassword->setText("New account has been created");        //final confirmation
    }

}


void MainWindow::on_pushButton_BackToMainMenuFromNewAccount_clicked()               //coming back to the main menu from the "new account" page
{
    ui->stackedWidget->setCurrentIndex(0);
}

