#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"
#define N 10            //maximum number of accounts that can exist

void MainWindow::on_pushButton_ComeBack_ListOfUsers_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_changeNameAdmin_clicked()
{
    ui->lineEdit_TransferToPerson_Name->show();                         //showing additional functions

    ui->textBrowser_MoneyGeneral->setText("Whoose name would you like to change?");
    ui->lineEdit_InsertAmount->setPlaceholderText("Insert a new name");
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_changeSurnameAdmin_clicked()
{
    ui->lineEdit_TransferToPerson_Name->show();                         //showing additional functions

    ui->textBrowser_MoneyGeneral->setText("Whoose surname would you like to change?");
    ui->lineEdit_InsertAmount->setPlaceholderText("Insert a new surname");
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_changeLoginAdmin_clicked()
{
    ui->lineEdit_TransferToPerson_Name->show();                         //showing additional functions

    ui->textBrowser_MoneyGeneral->setText("Whoose login would you like to change?");
    ui->lineEdit_InsertAmount->setPlaceholderText("Insert a new login");
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_changePasswordAdmin_clicked()
{
    ui->lineEdit_TransferToPerson_Name->show();                         //showing additional functions

    ui->textBrowser_MoneyGeneral->setText("Whoose password would you like to change?");
    ui->lineEdit_InsertAmount->setPlaceholderText("Insert a new password");
    ui->stackedWidget->setCurrentIndex(4);
}
