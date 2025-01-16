#include "addvendorview.h"
#include "ui_addvendorview.h"
#include <pqxx/pqxx>
AddVendorView::AddVendorView(QWidget *parent, pqxx::connection &conn)
    : QDialog(parent)
    , ui(new Ui::AddVendorView), C(conn)
{
    ui->setupUi(this);
}

AddVendorView::~AddVendorView()
{
    delete ui;
}



