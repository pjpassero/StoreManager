/*
 *Philip J. Passero IV
 *loginwindow.h
 *
 *
 *Login Window View declaration file
 *
 *This is the window that will display the login view
 */

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <homepageview.h>
#include <pqxx/pqxx>
#include "StoreManager/StoreManager/UserSession.h"

enum LOGINTYPE {
    MAINWINDOW,
    POINT_OF_SALE
};

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent, pqxx::connection& conn, LOGINTYPE);
    ~LoginWindow();

private:
    pqxx::connection &C;
    Ui::LoginWindow *ui;
    HomePageView *home;
    LOGINTYPE logInAs;
    void LoginToProgram();
    bool FindUserInDatabase(std::string &eUsername, std::string &ePassword);
    bool FindUserInDatastore();
    void LaunchHomeView(UserSession &us);
    void LauchPointOfSaleView(UserSession &us);

};

#endif // LOGINWINDOW_H
