#include "productview.h"
#include "ui_productview.h"

ProductView::ProductView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProductView)
{
    ui->setupUi(this);
}

ProductView::~ProductView()
{
    delete ui;
}
