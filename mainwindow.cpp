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

        ui->pushButton_MoreOptions->hide();                 //hiding the possibility to access more options in the beginning

        admin.FileOutput(customer,N);



}

MainWindow::~MainWindow()
{
    admin.FileInput(customer, N);                     //initiating the files with users' data

    delete ui;
}



