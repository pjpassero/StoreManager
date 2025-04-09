#include "salesview.h"
#include "ui_salesview.h"

SalesView::SalesView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SalesView)
{
    ui->setupUi(this);
}

SalesView::~SalesView()
{
    delete ui;
}
