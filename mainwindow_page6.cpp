#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "admin.h"

#define N 10            //maximum number of accounts that can exist

void MainWindow::on_pushButton_ComeBack_ListOfUsers_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
