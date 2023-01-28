#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 10            //maximum number of accounts that can exist

void MainWindow::on_pushButton_Ban_clicked()
{
    string given_user_nr = ui->lineEdit_enterUserNameBan->text().toStdString();

    Admin admin;

    int customer_int = 0;
    for(customer_int = 0; customer_int<N; customer_int++)
    {
        if(customer[customer_int].Return_float("customer_nr") == stof(given_user_nr)) break;
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
        admin.Additional_options(customer[customer_int], "banning", "");             //banning the user
        ui->textBrowser_BanUserInfo->setText("The user named " + QString::fromStdString(customer[customer_int]["name"]) +" "+ QString::fromStdString(customer[customer_int]["surname"]) + " was successfully banned");
        }

         if(ui->pushButton_Ban->text() == "Unban"){
             admin.Additional_options(customer[customer_int], "unbanning", "");          //unbanning the user
             ui->textBrowser_BanUserInfo->setText("The user named " + QString::fromStdString(customer[customer_int]["name"]) +" "+ QString::fromStdString(customer[customer_int]["surname"]) + " was successfully unbanned");
         }
    }
}


void MainWindow::on_pushButton_comeBackBan_clicked()
{
    ui->lineEdit_enterUserNameBan->setText("");             //resetting the input

    ui->stackedWidget->setCurrentIndex(3);
}
