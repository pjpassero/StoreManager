#ifndef SALESVIEW_H
#define SALESVIEW_H

#include <QMainWindow>
#include "pqxx/pqxx"

namespace Ui {
class SalesView;
}

class SalesView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SalesView(QWidget *parent, pqxx::connection &conn);
    ~SalesView();

private:
    Ui::SalesView *ui;
    pqxx::connection &C;


    void LoadTable();
};

#endif // SALESVIEW_H
