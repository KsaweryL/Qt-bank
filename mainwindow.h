#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admin.h"

#define N 10
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

   Customer customer[N];
   Admin admin;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_pushButton_3_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_newAccount_clicked();

    void on_pushButton_comeBack_clicked();

    void on_pushButton_InsertMoney_clicked();

    void on_pushButton_insert_clicked();

    void on_pushButton_comeBackInsert_clicked();

    void on_pushButton_WithdrawMoney_clicked();

    void on_pushButton_TakeOutLoan_clicked();

    void on_pushButton_ComeBackMainMenu_clicked();

    void on_pushButton_insertNewData_clicked();

    void on_pushButton_restate_clicked();

    void on_pushButton_BackToMainMenuFromNewAccount_clicked();

    void on_pushButton_GiveBackMoney_clicked();

    void on_pushButton_TransferMoney_clicked();

    void on_pushButton_BanningTheUser_clicked();

    void on_pushButton_comeBackBan_clicked();

    void on_pushButton_UnbanningTheUser_clicked();

    void on_pushButton_Ban_clicked();

    void on_pushButton_MoreOptions_clicked();

    void on_pushButton_ComeBack_ListOfUsers_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
