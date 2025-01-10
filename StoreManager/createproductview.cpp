#include "createproductview.h"
#include "ui_createproductview.h"

CreateProductView::CreateProductView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateProductView)
{
    ui->setupUi(this);
}

CreateProductView::~CreateProductView()
{
    delete ui;
}
