#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 10            //maximum number of accounts that can exist

void MainWindow::on_pushButton_BackToMainMenuFromNewAccount_clicked()               //coming back to the main menu from the "new account" page
{

    int detector = 0;
    for(int i = 0; i<N; i++)                 //to check if there is an empty slot for a new customer
    {

        if(customer[i]["name"] != "0") detector++;
    }

    try {
        if(detector == N) throw 'a';
    } catch (char a) {
        ui->textBrowser_Announcement->setText("Exception caught: No more new accounts can be created");
        ui->pushButton_newAccount->hide();
    }

    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_insertNewData_clicked()
{

    ui->textBrowser_RepeatPassword->show();
    ui->lineEdit_restatePassword->show();
    ui->pushButton_restate->show();

    ui->textBrowser_RepeatPassword->setText("Please confirm your password by restating it");


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

        for(customer_nr = 0; customer_nr<N; customer_nr++)                 //to check if there is an empty slot for a new customer and if there is - assing all of the data to it
        {
            if(customer[customer_nr]["name"] == "0") break;

        }

        customer[customer_nr]["name"] = newName;
        customer[customer_nr]["surname"] = newSurname;
        customer[customer_nr]["login"] = newLogin;
        customer[customer_nr]["password"] = newPassword;

        ui->lineEdit_newName->setText("");                      //resetting the input
         ui->lineEdit_newSurname->setText("");
          ui->lineEdit_newTempLogin->setText("");
           ui->lineEdit_newTempPassword->setText("");
            ui->lineEdit_restatePassword->setText("");

        ui->textBrowser_RepeatPassword->setText("New account has been created");        //final confirmation
    }

}
