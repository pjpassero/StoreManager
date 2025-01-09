#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <homepageview.h>
#include <pqxx/pqxx>
namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent, pqxx::connection& conn);
    ~LoginWindow();

private:
    pqxx::connection &C;
    Ui::LoginWindow *ui;
    HomePageView *home;
    void LoginToProgram();
    bool FindUserInDatabase(std::string &eUsername, std::string &ePassword);
    bool FindUserInDatastore();
    void LaunchHomeView();

};

#endif // LOGINWINDOW_H
