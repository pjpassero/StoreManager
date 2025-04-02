/*
 * Philip J. Passero IV
 * pointofsaleview.h
 *
 *
 * In development
 *
 * This will eventually be the home of the Point of Sale window for the application
 */

#ifndef POINTOFSALEVIEW_H
#define POINTOFSALEVIEW_H
#include "pqxx/pqxx"
#include "StoreManager/StoreManager/UserSession.h"
#include <QMainWindow>

namespace Ui {
class PointOfSaleView;
}

class PointOfSaleView : public QMainWindow
{
    Q_OBJECT

public:
    explicit PointOfSaleView(QWidget *parent, pqxx::connection &conn);
    ~PointOfSaleView();

    void setSession(UserSession* us);
    void updateWinData();


private:
    Ui::PointOfSaleView *ui;
    UserSession *session;
    pqxx::connection &C;
    bool loggedIn = false;
    void AddToList();
    void Login();
};

#endif // POINTOFSALEVIEW_H
