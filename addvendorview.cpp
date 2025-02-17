/*
 * Philip J. Passero
 * addvendorview.cpp
 *
 * Add vendor view dialog class implementation
 *
 */

#include "addvendorview.h"
#include "ui_addvendorview.h"
#include <pqxx/pqxx>
#include <iostream>
AddVendorView::AddVendorView(QWidget *parent, pqxx::connection &conn)
    : QDialog(parent)
    , ui(new Ui::AddVendorView), C(conn)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a New Vendor");
    connect(ui->addVendor, &QPushButton::clicked, this, &AddVendorView::addVendor);

}

AddVendorView::~AddVendorView()
{
    delete ui;
}


/*
 * Add a new vendor button event handler. Will store the new vendor in the vendor table
 */

void AddVendorView::addVendor() {


    try {
        QString address = ui->Address->toPlainText();
        QString supplierContactPhone = ui->SalesContactPhone->toPlainText();
        QString supplierContactName = ui->salesContactName->toPlainText();
        QString vendorName = ui->vendorName->toPlainText();

        pqxx::work txn(C);
        std::string query = "INSERT INTO vendor (vendorname, salesname,salesphone,companyaddress) VALUES ($1,$2,$3,$4)";
        txn.exec_params(query,vendorName.toStdString(), supplierContactName.toStdString(),supplierContactPhone.toStdString(), address.toStdString());
        txn.commit();

        this->close();

    }catch (const std::exception &e) {
        std::cerr << "Error saving vendor to database: " << e.what() << std::endl;
    }





}
