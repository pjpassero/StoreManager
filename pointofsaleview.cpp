#include "pointofsaleview.h"
#include "ui_pointofsaleview.h"

PointOfSaleView::PointOfSaleView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PointOfSaleView)
{
    ui->setupUi(this);
}

PointOfSaleView::~PointOfSaleView()
{
    delete ui;
}
