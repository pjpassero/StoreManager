#ifndef INVENTORYVIEW_H
#define INVENTORYVIEW_H

#include <QMainWindow>
#include "addproductview.h"
#include <pqxx/pqxx>

namespace Ui {
class InventoryView;
}

class InventoryView : public QMainWindow
{
    Q_OBJECT

public:
    explicit InventoryView(QWidget *parent, pqxx::connection &conn);
    void reloadDataTable();
    void onSelectedRow();
    ~InventoryView();

private:
    Ui::InventoryView *ui;
    AddProductView *newProduct;
    pqxx::connection &C;



    void PopulateInventoryViewFromFile();

};

#endif // INVENTORYVIEW_H
