#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 10            //maximum number of accounts that can exist

void MainWindow::on_pushButton_login_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_newAccount_clicked()
{
    for(int i = 0; i<N; i++)                 //resetting the active status for all users just in case
    {
        customer[i].Change("0", "active");
    }

    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_restatePassword->hide();
    ui->textBrowser_RepeatPassword->hide();
    ui->pushButton_restate->hide();
}

