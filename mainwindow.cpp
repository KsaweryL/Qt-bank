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
        customer[i].surname = "0";
    }
        admin.Change("admin", "login");
        admin.Change("adminpass", "password");

        customer[0].Change("Admin", "name");
        customer[0].Change("Admin", "surname");
        customer[0].Change(admin["login"], "login");
        customer[0].Change(admin["password"], "password");

        customer[1].Change("Adam", "name");
        customer[1].Change("Kowalski", "surname");
        customer[1].Change("login1", "login");
        customer[1].Change("password1", "password");

        customer[2].Change("Barbara", "name");
        customer[2].Change("Nowak", "surname");
        customer[2].Change("login2", "login");
        customer[2].Change("password2", "password");

        admin.FileOutput(customer,N);

        ui->stackedWidget->setCurrentIndex(0);

        ui->lineEdit_TransferToPerson_Name->hide();      //hiding the the transfer option in the beginning
         ui->lineEdit_TransferToPerson_Surname->hide();

        ui->pushButton_BanningTheUser->hide();              //hiding the possibility to ban the user in the beginning
        ui->pushButton_UnbanningTheUser->hide();              //hiding the possibility to unban the user in the beginning

        ui->pushButton_MoreOptions->hide();                 //hiding the possibility to access more options in the beginning




}

MainWindow::~MainWindow()
{
    admin.FileInput(customer, N);                     //initiating the files with users' data

    delete ui;
}



