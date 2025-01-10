#include "inventoryview.h"
#include "ui_inventoryview.h"

InventoryView::InventoryView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InventoryView)
{
    ui->setupUi(this);
}

InventoryView::~InventoryView()
{
    delete ui;
}
