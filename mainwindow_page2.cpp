#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 10            //maximum number of accounts that can exist

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
                ui->textBrowser_currentBalance->setText("Current bank balance: " + QString::number(customer[i].bank_balance)+ "\nCurrent amount of owed money: " + QString::number(customer[i].loanOwe));          //showing the current bank balance of the user

                ui->lineEdit_login->setText("");                   //resetting the input for both login and password
                ui->lineEdit_password->setText("");

                if(customer[i].ban_status == 1)
                {
                    ui->pushButton_InsertMoney->hide();
                    ui->pushButton_WithdrawMoney->hide();
                    ui->pushButton_TransferMoney->hide();
                    ui->pushButton_TakeOutLoan->hide();
                    ui->pushButton_GiveBackMoney->hide();
                    ui->textBrowser_currentBalance->setText("Your acccount is temporarily banned! All of the options are blocked. \nCurrent bank balance: " + QString::number(customer[i].bank_balance) + "\nCurrent loan balance: " + QString::number(customer[i].loanOwe));
                }
                else
                {
                    ui->pushButton_InsertMoney->show();
                    ui->pushButton_WithdrawMoney->show();
                    ui->pushButton_TransferMoney->show();
                    ui->pushButton_TakeOutLoan->show();
                    ui->pushButton_GiveBackMoney->show();
                }

                if(customer[i].login == admin.login) {ui->pushButton_BanningTheUser->show();   //if admin is detected, show "more options" button
                    ui->pushButton_UnbanningTheUser->show();
                ui->pushButton_MoreOptions->show();
                }
                ui->stackedWidget->setCurrentIndex(3);

            }
        }
    }


    ui->textBrowser_incorrectLogin->setText("Either login or password is incorrect.");

}

void MainWindow::on_pushButton_comeBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    for(int i = 0; i<N; i++)                 //resetting the active status for all users when coming back to main menu
    {
        customer[i].active = 0;
    }

}
