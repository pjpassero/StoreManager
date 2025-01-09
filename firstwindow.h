#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H
#include <loginwindow.h>
#include <QMainWindow>
namespace Ui {
class FirstWindow;
}

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();

private:
    Ui::FirstWindow *ui;
    //LoginWindow login;


    void openDatabaseWizard();


};

#endif // FIRSTWINDOW_H
