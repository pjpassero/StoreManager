#ifndef ORDERVIEW_H
#define ORDERVIEW_H
#include "pqxx/pqxx"
#include <QMainWindow>

namespace Ui {
class OrderView;
}

class OrderView : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderView(QWidget *parent, pqxx::connection &conn);
    ~OrderView();


private:
    Ui::OrderView *ui;
    pqxx::connection &C;
    void PopulateProductsFromFile();
    void SendOrder();
};

#endif // ORDERVIEW_H
