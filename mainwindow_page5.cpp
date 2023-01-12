#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 10            //maximum number of accounts that can exist

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
