#ifndef INVENTORYVIEW_H
#define INVENTORYVIEW_H

#include <QMainWindow>
#include "addproductview.h"

namespace Ui {
class InventoryView;
}

class InventoryView : public QMainWindow
{
    Q_OBJECT

public:
    explicit InventoryView(QWidget *parent = nullptr);
    ~InventoryView();

private:
    Ui::InventoryView *ui;
    AddProductView *newProduct;

    void PopulateInventoryViewFromFile();

};

#endif // INVENTORYVIEW_H
