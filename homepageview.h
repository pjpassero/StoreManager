#ifndef HOMEPAGEVIEW_H
#define HOMEPAGEVIEW_H
#include <inventoryview.h>
#include <employeelistview.h>
#include <QMainWindow>
#include "StoreManager/StoreManager/UserSession.h"
namespace Ui {
class HomePageView;
}

class HomePageView : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePageView(QWidget *parent, pqxx::connection &conn, UserSession &newSession);
    ~HomePageView();

private:
    Ui::HomePageView *ui;
    UserSession &session;
    InventoryView *inventory;
    EmployeeListView *employees;
    pqxx::connection &C;
    void LoadInventoryView();
    void LoadEmployeeView();


};

#endif // HOMEPAGEVIEW_H
