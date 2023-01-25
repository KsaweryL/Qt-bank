#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 10            //maximum number of accounts that can exist

void MainWindow::on_pushButton_BanningTheUser_clicked()
{
    ui->lineEdit_TransferToPerson_Name->show();

    ui->lineEdit_InsertAmount->setPlaceholderText("Which user would you like to ban?");
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_ComeBackMainMenu_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
     ui->textBrowser_incorrectLogin->setText("");       //resetting the text output in login menu

     for(int i = 0; i<N; i++)                 //resetting the active status for all users when coming back to main menu
     {
         customer[i].Change("0", "active");
     }

    ui->pushButton_BanningTheUser->hide();          //hide the admin options when coming back to main menu
    ui->pushButton_UnbanningTheUser->hide();
    ui->pushButton_MoreOptions->hide();

}

void MainWindow::on_pushButton_GiveBackMoney_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to give back?");
    ui->pushButton_insert->setText("Give back");
     ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_InsertMoney_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to insert?");
    ui->pushButton_insert->setText("Insert");
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_TakeOutLoan_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to take out as a loan?");
    ui->pushButton_insert->setText("Take out");
     ui->stackedWidget->setCurrentIndex(4);


}

void MainWindow::on_pushButton_TransferMoney_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to ransfer and to whom?");
    ui->pushButton_insert->setText("Transfer");
    ui->lineEdit_TransferToPerson_Name->show();

     ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_UnbanningTheUser_clicked()
{
    ui->lineEdit_TransferToPerson_Name->show();                 //making it possible to see some additional options

    ui->lineEdit_InsertAmount->setPlaceholderText("Which user would you like to unban?");
    ui->pushButton_Ban->setText("Unban");
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_WithdrawMoney_clicked()
{
    ui->textBrowser_MoneyGeneral->setText("                             How much money would you like to withdraw?");
    ui->pushButton_insert->setText("Withdraw");
     ui->stackedWidget->setCurrentIndex(4);

}


void MainWindow::on_pushButton_MoreOptions_clicked()
{
    ui->pushButton_insert->setText("Change");
    string list_of_users = "List of users:\n\n";
    for(int i = 0; i<N; i++)
    {
        if(customer[i]["name"] != "0") {
            list_of_users.append(customer[i]["name"]);
            list_of_users.append(" ");
            list_of_users.append(customer[i]["surname"]);
            list_of_users.append(" -> User's number: ");
            list_of_users.append(to_string(customer[i].Return_float("customer_nr")));
            list_of_users.append(" -> User's bank balance: ");
            list_of_users.append(to_string(customer[i].Return_float("bank_balance")));
            list_of_users.append(" -> User's loan+interest balance: ");
            list_of_users.append(to_string(customer[i].Return_float("loanOwe")));
            list_of_users.append("\n\n");
        }
    }

    ui->textBrowser_ListOfUsers->setText(QString::fromStdString(list_of_users));
    ui->stackedWidget->setCurrentIndex(6);
}
