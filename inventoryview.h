/*
 *Philip J. Passero
 *inventoryview.h
 *
 *Inventory View Class declaration file.
 *
 *This class creates the window that allows the user to see all the products in the database
 */

#ifndef INVENTORYVIEW_H
#define INVENTORYVIEW_H

#include <QMainWindow>
#include "addproductview.h"
#include "addvendorview.h"
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
    AddVendorView *newVendor;
    pqxx::connection &C;



    void PopulateInventoryViewFromFile();
};

#endif // INVENTORYVIEW_H
