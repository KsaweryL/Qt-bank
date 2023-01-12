#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 10            //maximum number of accounts that can exist

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

        ui->lineEdit_TransferToPerson_Name->hide();      //hiding the the transfer option in the beginning
         ui->lineEdit_TransferToPerson_Surname->hide();

        ui->pushButton_BanningTheUser->hide();              //hiding the possibility to ban the user in the beginning
        ui->pushButton_UnbanningTheUser->hide();              //hiding the possibility to unban the user in the beginning

        admin.FileOutput(customer,N);



}

MainWindow::~MainWindow()
{
    admin.FileInput(customer, N);                     //initiating the files with users' data

    delete ui;
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



void MainWindow::on_pushButton_comeBackInsert_clicked()
{
    ui->lineEdit_InsertAmount->setPlaceholderText("Insert amount of money here");
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

    ui->pushButton_BanningTheUser->hide();          //hide the admin options when coming back to main menu
    ui->pushButton_UnbanningTheUser->hide();

}


void MainWindow::on_pushButton_GiveBackMoney_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to give back?");
    ui->pushButton_insert->setText("Give back");
     ui->stackedWidget->setCurrentIndex(4);

}


void MainWindow::on_pushButton_TransferMoney_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to ransfer and to whom?");
    ui->pushButton_insert->setText("Transfer");
    ui->lineEdit_TransferToPerson_Name->show();
    ui->lineEdit_TransferToPerson_Surname->show();

     ui->stackedWidget->setCurrentIndex(4);

}


void MainWindow::on_pushButton_BanningTheUser_clicked()
{
    ui->lineEdit_InsertAmount->setPlaceholderText("Which user would you like to ban?");
     ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_pushButton_Ban_clicked()
{
    string input_name = ui->lineEdit_enterUserNameBan->text().toStdString();
    string input_surname = ui->lineEdit_enterUserSurnameBan->text().toStdString();

    int customer_int = 0;
    for(customer_int = 0; customer_int<N; customer_int++)
    {
        if(customer[customer_int].name == input_name && customer[customer_int].surname == input_surname) break;
    }

    try{                                                                    //checking if the user exists in the database
        if(customer_int == N) throw 'a';
    }
    catch(char x){
        ui->textBrowser_BanUserInfo->setText("Exception caught: such user doesn't exist");
    }

    if(customer_int != N)               //the user exists
    {
        if(ui->pushButton_Ban->text() == "Ban"){
        customer[customer_int].ban_status = 1;          //banning the user
        ui->textBrowser_BanUserInfo->setText("The user named " + QString::fromStdString(customer[customer_int].name) +" "+ QString::fromStdString(customer[customer_int].surname) + " was successfully banned");
        }

         if(ui->pushButton_Ban->text() == "Unban"){
             customer[customer_int].ban_status = 0;          //unbanning the user
             ui->textBrowser_BanUserInfo->setText("The user named " + QString::fromStdString(customer[customer_int].name) +" "+ QString::fromStdString(customer[customer_int].surname) + " was successfully unbanned");
         }
    }
}


void MainWindow::on_pushButton_comeBackBan_clicked()
{
    ui->lineEdit_enterUserNameBan->setText("");             //resetting the input
    ui->lineEdit_enterUserSurnameBan->setText("");
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_UnbanningTheUser_clicked()
{
    ui->lineEdit_InsertAmount->setPlaceholderText("Which user would you like to unban?");
    ui->pushButton_Ban->setText("Unban");
     ui->stackedWidget->setCurrentIndex(5);
}

