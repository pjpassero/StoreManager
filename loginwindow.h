#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <homepageview.h>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
    HomePageView *home;
    void LoginToProgram();
    bool FindUserInDatabase(std::string &eUsername, std::string &ePassword);
    bool FindUserInDatastore();
    void LaunchHomeView();

};

#endif // LOGINWINDOW_H
